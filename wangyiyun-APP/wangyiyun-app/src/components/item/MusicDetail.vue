<template>
    <!-- 弹窗部分 -->
    <div>
        <img :src="playList[playlistIndex].al.picUrl" alt="" class="bgimg">
        <!-- 顶部 -->
        <div class="datailTop">
            <div class="detailTopLeft">
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-houtui"></use>
                </svg>
                <div class="leftMarquee">
                    <Vue3Marquee style="color:#000;">
                        {{playList[playlistIndex].al.name}}
                    </Vue3Marquee>
                    <span v-for="item in playList[playlistIndex].ar" :key="item">
                        {{item.name}}
                    </span>
                    <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                        <use xlink:href="#icon-hongluobu"></use>
                    </svg>
                </div>
            </div>
            <div class="detailTopRight">
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-hongluobu"></use>
                </svg>
            </div>
        </div>
        <!-- 中部 -->
        <div class="detailContent" @click="isCd_show()">
            <template v-if="cd_show">
                <img src="@/assets/yuan.png" alt="" class="img_cd">
                <img src="@/assets/zhen.png" alt="" :class="[isbtnShow?'img_needle_active': 'img_needle' ]">
                <img :src="playList[playlistIndex].al.picUrl" alt="" :class=" [isbtnShow?'img_ar_active':'img_ar_pauesd']+' '+'img_ar'">
            </template>
            <!-- 歌词部分  -->
            <div class="lyric" v-else>
                <lyric />
            </div>

        </div>
        <!-- 底部 -->
        <div class="detailFooter">
            <div class="footerTop">
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-mangguo"></use>
                </svg>
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-mangguo"></use>
                </svg>
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-mangguo"></use>
                </svg>
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-mangguo"></use>
                </svg>
                <svg class="icon " aria-hidden="true" @click="$emit('upPopupShow')">
                    <use xlink:href="#icon-mangguo"></use>
                </svg>
            </div>
            <!-- 进度条部分 -->
            <div class="footerContent">
                <range />
            </div>
            <!-- 下面的播放 -->
            <div class="footer">
                <svg class="icon " aria-hidden="true" @click="arrowYN(-1)">
                    <use xlink:href="#icon-shangyiqu1"></use>
                </svg>
                <svg class="icon " aria-hidden="true" @click="arrowYN(-1)">
                    <use xlink:href="#icon-shangyiqu1"></use>
                </svg>
                <svg class="icon " aria-hidden="true" v-if="isbtnShow" @click="$emit('paly')">
                    <use xlink:href="#icon-zanting"></use>
                </svg>
                <svg class="icon " aria-hidden="true" v-else @click="$emit('paly')">
                    <use xlink:href="#icon-bofang"></use>
                </svg>
                <svg class="icon " aria-hidden="true" @click="arrowYN(1)">
                    <use xlink:href="#icon-xiayiqu1"></use>
                </svg>
                <!-- 展示待播放歌曲 -->
                <svg class="icon " aria-hidden="true" @click="islooklist()">
                    <use xlink:href="#icon-shoucang-"></use>
                </svg>
                <!-- !-- 队列 -->
                <FooterList v-if="looklist" />
            </div>
        </div>
    </div>
</template>

<script>
import { mapState, mapMutations } from "vuex";
import { Vue3Marquee } from "vue3-marquee"; //走马灯导入
import "vue3-marquee/dist/style.css"; //走马灯CSS导入
//子组件导入
import lyric from "@/components/item/detail/lyric.vue";
import range from "@/components/item/detail/range.vue";
// 播放队列展示
import FooterList from "@/components/item/detail/FooterList.vue";
export default {
    data() {
        return {
            cd_show: true, //cd 和歌词切换
        };
    },
    props: ["popupShow"], //弹出层控制变量
    emits: ["upPopupShow", "paly"], //控制弹出层方法
    methods: {
        isCd_show: function () {
            this.cd_show = !this.cd_show;
        },
        ...mapMutations(["updateIsbtnShow", "arrowYN", "islooklist"]),
    },
    computed: {
        ...mapState(["playList", "playlistIndex", "isbtnShow", "looklist"]),
    },
    mounted() {
        console.log(this.playList);
    },
    components: {
        Vue3Marquee,
        lyric,
        range,
        FooterList, //播放队列展示
    },
};
</script>

<style lang="less" scoped>
.datailTop {
    width: 100%;
    height: 1rem;
    display: flex;
    padding: 0.2rem;
    justify-content: space-between; //main 横轴上的对齐方式
    align-items: center; //corss 纵轴方向上的对齐方式
    fill: #fff;
    .detailTopLeft {
        display: flex;
        align-items: center;
        .leftMarquee {
            width: 3rem;
            height: 100%;
            margin-left: 0.4rem;
            span {
                color: #999;
            }
            .icon {
                width: 0.3rem;
                height: 0.3rem;
                fill: #999;
            }
        }
    }
}
.bgimg {
    position: absolute;
    width: 100%;
    height: 100%;
    z-index: -1;
    filter: blur(0.05rem);
}
.detailContent {
    width: 100%;
    height: 9rem;
    display: flex;
    flex-direction: column;
    align-items: center;
    position: relative;
    .img_needle {
        //已经渲染 所以已经是好的了
        width: 2rem;
        height: 3rem;
        position: absolute;
        left: 46%;
        transform-origin: 0 0;
        transform: rotate(-15deg);
        transition: all 1s;
    }
    .img_needle_active {
        //更改后  变化的动画样式
        width: 2rem;
        height: 3rem;
        position: absolute;
        left: 46%;
        transform-origin: 0 0;
        transform: rotate(0deg);
        transition: all 2s;
    }
    .img_cd {
        width: 5rem;
        height: 5rem;
        position: absolute;
        bottom: 2.3rem;
        z-index: -1;
    }

    .img_ar {
        //图片要旋转
        width: 3.2rem;
        height: 3.2rem;
        border-radius: 50%;
        position: absolute;
        bottom: 3.14rem;
        animation: mov 10s linear infinite;
    }
    .img_ar_active {
        animation-play-state: running; //启动
    }
    .img_ar_pauesd {
        animation-play-state: paused; //暂停
    }
    //动画
    @keyframes mov {
        0% {
        }
        100% {
            transform: rotateZ(360deg);
        }
    }
    .lyric {
        width: 100%;
        height: 100%;
    }
}
.detailFooter {
    width: 100%;
    height: 8rem;
    .footerTop,
    .footer {
        display: flex;
        height: 20%;
        justify-content: space-between; //main 横轴上的对齐方式
        align-items: center; //corss 纵轴方向上的对齐方式
        .icon {
            width: 50%;
            height: 50%;
        }
    }
    .footerContent {
        width: 100%;
    }
}
</style>