import { createStore } from "vuex";
//axios 函数
import { getmusicLyric } from "@/request/api/itme";
//子模块
import { modelueLogin } from "./longin.js";
//子模块 infouser
import { modelueInfouser } from "./user";
//子模块 token
import { modelueToken } from "./utils";
//普通的通用函数
export default createStore({
    state: {
        //作为模板
        tem: {
            al: {
                id: null,
                name: null,
                picUrl: null,
                ar: [], //作者名字
            },
            id: null,
            name: null,
        },
        playList: [
            //播放的列表
            //全局组件表示的是底部播放器的相关参数
        ],
        lyricList: {}, //歌词数据
        playlistIndex: -1, //播放的下标为0 当前播放
        isbtnShow: true, //是否在播放 控制播放按钮变形
        currentime: 0, //当前时间
        alltime: 0, //总时间
        intertime: null, //定时器
        audio: null, //播放器
        islogin: 0, //判断是否登录 0: 未登录 1: 登录 2: 游客
        isloginShow: false, //登录弹窗
        looklist: true, //播放队列展示
    },
    getters: {}, //类似计算属性 返回变异后的属性
    mutations: {
        //修改登录状态 根据传参修改 登录状态
        updateIslogin(state, coun) {
            console.log("登录状态被改变");
            console.log(coun);
            state.islogin = coun;
        },
        //播放队列展示
        islooklist(state) {
            console.log("更改队列展示");
            state.looklist = !state.looklist;
        },
        //同步操作
        //是否播放
        updateIsbtnShow: function (state, value) {
            state.isbtnShow = value;
        }, //增加播放源  传入 歌曲信息
        updatePlayList: function (state, value) {
            console.log("播放数组改变");
            console.log(state.playList);
            if (value instanceof Array) {
                state.playList = value.concat(state.playList);
                // 去重
                // state.playList.from set(...state.playList);
                state.playList = Array.from(new Set(state.playList));
                // state.playList = value;
                console.log(state.playList);
            } else {
                console.log("朴实拷贝1");
                console.log(value);
                // state.tem.id = value.id;
                // state.tem.name = value.name;
                // state.tem.al.id = value.album.id;
                // state.tem.al.name = value.album.name;
                // state.tem.al.picUrl = value.artists[0].img1v1Url;
                // state.tem.al.ar = value.artists[0].name;
                let newobj = new Object();
                let newobj2 = new Object();
                newobj.id = value.id;
                newobj.name = value.name;
                newobj2.id = value.album.id;
                newobj2.name = value.album.name;
                newobj2.picUrl = value.artists[0].img1v1Url;
                newobj2.ar = value.artists[0].name;

                newobj.al = newobj2;
                // Object.assign(newold, state.tem);
                // this.commit("deepCopy", newold);
                //歌曲信息不一样 修改一下 深拷贝
                state.playList.unshift(newobj);
            }
        },

        //删除该歌曲,并查看播放id 并适时更改
        delpalyList(state, index) {
            console.log("我在删除歌曲");
            //只剩下一首歌 直接清空  恢复原状
            if (state.playList.length == 1) {
                state.playlistIndex = -1; //播放的下标为0 当前播放
                state.isbtnShow = false; //是否在播放 控制播放按钮变形
                state.playList = {};
                state.looklist = false;
                state.looklist = false;
                clearInterval(state.intertime);
                return;
            } //删除的是最后一首  避免 播放下标落空
            if (state.playlistIndex == state.playList.length - 1) {
                state.playlistIndex--;
            }
            state.playList.splice(index, 1); //先删除
        },
        //上一曲1 暂停0 下一曲-1
        arrowYN(state, bool) {
            console.log("上一曲下一曲切换");
            if (bool === 1) {
                if (state.playlistIndex + 1 == state.playList.length) {
                    state.playlistIndex = 0; //重新循环
                } else {
                    state.playlistIndex++;
                }
            } else if (bool == -1) {
                state.playlistIndex == 0
                    ? (state.playlistIndex = 0)
                    : state.playlistIndex--;
            }
        },
        //暂时未使用
        listIndex: function (state, Index) {
            //点击后更改播放数组的下标
            console.log("更改播放下标");
            state.playlistIndex = Index;
        }, //由getLytic 调用  因为播放时需要获取歌词 是异步
        listIndex_scvie: function (state, tor) {
            //点击后更改播放数组的下标
            console.log("更改播放下标");
            console.log(tor);
            state.playlistIndex = tor.Index;
            state.lyricList = tor.lrc.data.lrc;
            //这里可以链式调用
            // state.lyriclist = tor.lrc.then((op) => {
            //     return op.data.lrc.lyric;
            // }); //给歌词赋值
            console.log(state.lyricList);
        },
        // 更改当前时间1
        updateCurrentime: function (state, audiotime) {
            state.currentime = audiotime;
            //总时间和当前时间 在此之前 会动态更新 下面直接使用即可
            //允许500毫秒的误差 避免出错
            console.log("时间");
            console.log(state.currentime);
            console.log(state.alltime);
            if (state.alltime) {
                //当总时间获取到后 才能进行判断是否播放完毕
                if (state.currentime > state.alltime - 500) {
                    this.commit("arrowYN", 1); //下一曲
                }
            }
        },
        //修改总时间  在进度条里会 使用 在歌曲播放中也会使用 所以播放即获得
        updataAlltime: function (state, all) {
            state.alltime = all * 1000;
            console.log("歌曲总时间打印");
            console.log(all);
        },
        //登录弹窗修改
        updataLoginShow(state) {
            console.log(state.isloginShow);
            state.isloginShow = !state.isloginShow;
            console.log(state.isloginShow);
            console.log("isloginShow 修改  " + state.isloginShow);
        },
    },
    actions: {
        //异步操作
        //获取歌词 //点击就会重新获取 index,id:list.id
        async getLytic(context, tor) {
            console.log("获取歌词数据   " + tor.index);
            console.log(tor);
            context.commit("listIndex_scvie", {
                Index: tor.index,
                lrc: await getmusicLyric(tor.id),
            });
            console.log("获取并更改下标完成");
            // context.commit('需要触发的Mutation函数')
            // return getmusicLyric(playlistIndex).data.al.ltc;
        },
        //播放时 获取 时间节点  time  是audil 对象
        async AcupdateCurrentime(context, time) {
            if (context.isbtnShow) {
                let trimop;
                // let _this = this;
                clearInterval(trimop);
                trimop = setInterval(function () {
                    if (time.audio.duration) {
                        console.log("不为空");
                        context.state.alltime = time.audio.duration;
                        clearInterval(trimop);
                    } else {
                        console.log("为空");
                    }
                }, 500);
            }
            // console.log(context.state.alltime);
            if (time == false) {
                //time 会传入false 或者 audio对象
                console.log(context.state.intertime);
                console.log("定时器删除");
                console.log(context.state.intertime);
                clearInterval(context.state.intertime);
                return;
            } else {
                //定时器创建与否 该打印值都为真  故无论什么情况 创建前先删除
                clearInterval(context.state.intertime);
                //不允许多次创建
                context.state.intertime = setInterval(function () {
                    context.commit("updataAlltime", time.audio.duration);
                    context.commit(
                        "updateCurrentime",
                        time.audio.currentTime * 1000
                    );
                    console.log("定时器触发");
                }, 700);
                console.log(context.state.intertime);
                console.log("结束 else");
            }
            return;
        },
    },
    modules: {
        modelueLogin,
        modelueInfouser,
        modelueToken,
    }, //模块化操作
});
