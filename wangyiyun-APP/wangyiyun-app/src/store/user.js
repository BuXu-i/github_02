import {
    userDetail, //获取用户详情
    userAccount, //获取账号信息
    userSubcount, //获取用户信息 , 歌单，收藏，mv, dj 数量
    userPlaylist, // 获取用户歌单
} from "@/request/api/user";
export const modelueInfouser = {
    namespaced: true,
    state: {
        //当前比较重要的几个信息  要是登陆后上传 会直接更换获得的用户json数据
        Userinfo: {
            id: "", //id 下面请直接使用 使用前判断是否已经写入store
            username: "",
            createTime: "",
        },
    },
    mutations: {
        //   上传id      本   mutation  action    根State   传入值
        // pushUserinfo(state, commit, dispatch, rootState, Userinfo) {
        pushUserinfo(state, Userinfo) {
            //暂时来者不拒  不做限制
            // 当用户信息能够上传后  表示登录成功 更改登录is
            console.log("我在更改用户登录状态和存储用户状态信息");
            console.log("!!!");
            console.log(Userinfo);
            console.log(Userinfo.qr);
            state.Userinfo = Userinfo.qr; //浅拷贝 浅拷贝 浅拷贝 浅拷贝 浅拷贝 浅拷贝
            //修改登录状态
            console.log("修改登录状态");
            this.commit("updateIslogin", 1);
            console.log("id写入完成");
        },
    },
    actions: {
        //以下函数的使用都需要 查看登录状态才能使用  所以需要一个id检测函数
        //id检测  会调用 登录状态的查询函数  需要会自己跳转到登录状态函数
        async isUserinfo(context) {
            if (!context.state.Userinfo.id) {
                //获取用户信息 中有id
                console.log("跳转到id 获取 id检测后准备获取id");
                //在longin中  获取用户登录状态
                await context.dispatch(
                    "modelueLogin/storeGetLonginStatus",
                    {}, //传参
                    {
                        root: true, //表示到根模块中去寻找
                    }
                );
            }
        },
        //获取用户详细信息
        async storeUserDetail(context) {
            //检查用户id 是否已经获取
            if (!context.state.Userinfo.id) {
                console.log("检测到id 不存在");
                await context.dispatch("isUserinfo"); //调用本模块中的异步函数 没有参入参数
                //获取用户详情 id获取完成后 可以继续获得其他信息
                console.log("id获取完毕");
            } else {
                console.log("检测到id 已存在");
            }
            console.log("正在返回获取的用户信息");
            console.log(context.state.Userinfo.id);
            return await userDetail(context.state.Userinfo.id); //获取其他信息
        },
        async storeUserAccount(context) {
            return await userAccount(); //获取账号信息
        },
        async storeUserSubcount(context) {
            return await userSubcount(); //获取用户信息 , 歌单，收藏，mv, dj 数量
        },
        async storeUserPlaylist(context) {
            //检查用户id 是否已经获取
            if (!context.state.Userinfo.id) {
                console.log("检测到id 不存在");
                await context.dispatch("isUserinfo"); //调用本模块中的异步函数 没有参入参数
                //获取用户详情 id获取完成后 可以继续获得其他信息
                console.log("id获取完毕");
            } else {
                console.log("检测到id 已存在");
            }
            return await userPlaylist(context.state.Userinfo.id); // 获取用户歌单
        },
    },
};
