<template>
    <div class="FooterMusic" v-if="playlistIndex>=0">
        <div class="footerLeft" @click="upPopupShow()">
            <img :src="playList[playlistIndex].al.picUrl" alt="">
            <div>
                <p>{{playList[playlistIndex].al.name}}</p>
                <span @click="arrowYN()">横滑切换上下首</span>
            </div>
        </div>
        <div class="footerRight">
            <svg class="icon " aria-hidden="true" @click="paly() " v-if="isbtnShow">
                <use xlink:href="#icon-zanting"></use>
            </svg>
            <svg class="icon " aria-hidden="true" @click="paly()" v-else>
                <use xlink:href="#icon-bofang"></use>
            </svg>
            <!-- 展示待播放歌曲 -->
            <svg class="icon " aria-hidden="true" @click="islooklist()">
                <use xlink:href="#icon-shoucang-"></use>
            </svg>
            <!-- !-- 队列 -->
            <FooterList v-if="looklist" />
        </div>
        <!-- controls 控制显性 -->
        <audio ref="audio" :src="`https://music.163.com/song/media/outer/url?id=${playList[playlistIndex].id}.mp3`">
        </audio>
        <!-- //弹出 -->
        <van-popup v-model:show="popupShow" position="bottom" :style="{ height: '110%'}">
            <MusicDetail :popupShow='popupShow' @upPopupShow="upPopupShow()" @paly="paly()" />
        </van-popup>
    </div>
</template>

<script>
//此处是全局组件 即页面底部的播放组件
import { mapState, mapMutations, mapActions } from "vuex";
import MusicDetail from "@/components/item/MusicDetail.vue";
// 播放队列展示
import FooterList from "@/components/item/detail/FooterList.vue";
export default {
    data() {
        return {
            popupShow: false, //控制弹出的变量
        };
    },
    methods: {
        //控制弹出层
        upPopupShow() {
            console.log("弹出层");
            // console.log(this.popupShow);
            this.popupShow = !this.popupShow;
            console.log(this.popupShow);
            // this.updataAlltime(this.$refs.audio.duration * 1000); //执行更改vuex的总时间
        },
        paly() {
            //判断音乐是否播放  获取时间并依据时间调整歌词
            console.log("音乐播放");
            // console.log(this.$refs.audio.currentTime);
            if (this.isbtnShow) {
                this.$refs.audio.pause(); //暂停
                this.updateIsbtnShow(false);
                console.log("暂停");
                this.AcupdateCurrentime(false); //删除定时器
                //还有以套方案 将audio 播放器传入store 中 ，方便修改
                //触发定时器
            } else {
                console.log("被创建 paly 创建定时器");
                this.$refs.audio.play();
                this.updateIsbtnShow(true);
                this.AcupdateCurrentime(this.$refs); //创建定时器
            }
            //判断
            console.log(this.isbtnShow);
        },

        //修改播放bool   修改歌曲 总时间    //上一曲下一曲
        ...mapMutations([
            "updateIsbtnShow",
            "updataAlltime",
            "arrowYN",
            "islooklist", //歌曲列表展示
        ]),
        ...mapActions(["AcupdateCurrentime"]),
    },
    mounted() {
        console.log("嘿嘿");
        console.log(this.$refs); //使用ref 传值 传node节点
        console.log(this.playlistIndex);
    },
    updated: function (el, binding) {
        // console.log("时间=" + this.$refs.audio.duration);
        // console.log("updated被执行");
        //id改变后执行 立刻播放音乐 无论是否id相同 下面就要避免id相同时导致问题
        // console.log("播放器对象");
        // console.log(this.$refs);
        // console.log(this.$refs.audio.duration);
        // console.log(this.$refs.audio.currentTime);
        if (this.isbtnShow && this.$refs.audio.paused) {
            console.log("updated被执行");
            this.$refs.audio.play(); //id改变后执行 立刻播放音乐
            this.AcupdateCurrentime(this.$refs); //创建定时器
        }
    },
    // `https://music.163.com/song/meida/outer/url?id=${playList[playlistIndex].id}.mp3`
    computed: {
        ...mapState([
            "playList",
            "playlistIndex",
            "isbtnShow",
            "lyricL",
            "looklist",
        ]),
    },
    component: {
        MusicDetail,
        FooterList, //播放队列展示
    },
};
</script>

<style lang="less" scoped>
.FooterMusic {
    width: 100%;
    height: 1.4rem;
    background-color: #fff;
    position: fixed;
    display: flex;
    justify-content: space-between;
    padding: 0.2rem;
    border-top: 1px solid #000;
    bottom: 0;
    z-index: 999;

    .footerLeft {
        width: 70%;
        height: 100%;
        display: flex;
        align-content: center;
        img {
            width: 1rem;
            height: 1rem;
            border-radius: 50%;
        }
    }
    .footerRight {
        width: 20%;
        height: 100%;
        display: flex;
        justify-content: space-between;
        align-content: center;
        .icon {
            width: 0.6rem;
            height: 0.6rem;
            // display: flex;
        }
    }
}
</style>