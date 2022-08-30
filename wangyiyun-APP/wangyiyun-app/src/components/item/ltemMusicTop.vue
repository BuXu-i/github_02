<template>
    <div class="itemMusicTop" v-if="Bool==true">
        <!-- playlist -->
        <img :src="playlist.creator.backgroundUrl" alt="" class="bgimg">
        <div class="itemLeft">
            <svg class="icon" aria-hidden="true" @click="$router.go(-1)">
                <use xlink:href="#icon-shangyiqu"></use>
            </svg>
            <span>歌单</span>
        </div>
        <div class="itemRight">
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-shangyiqu"></use>
            </svg>
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-shangyiqu"></use>
            </svg>
        </div>
    </div>
</template>

<script>
export default {
    data() {
        return {
            Bool: false,
        };
    },
    props: ["playlist"],
    //只能延时检测
    watch: {
        playlist: function (newval, oldval) {
            this.Bool = true;
            console.log("捕获到BOOL改变");
            deep: true; //为true后 不再监控
        },
    },
    // setup(props) {
    //     console.log("子组件得到的传值props");
    //     console.log(props.playlist);
    //     console.log(props);
    //     console.log("子组件得到的传值props");
    //     //使用sessionStorage 读取浏览器缓存
    //     console.log(props.playlist.creator);
    //     if (
    //         props.playlist.creator == undefined &&
    //         sessionStorage.getItem("itemDetail") != null
    //     ) {
    //         props.playlist.creator = JSON.parse(
    //             sessionStorage.getItem("itemDetail")
    //         ).playlist.creator;
    //         console.log("成功！！");
    //     }
    //     console.log("成功没？");
    //     console.log(props.playlist);
    //     console.log(JSON.parse(sessionStorage.getItem("itemDetail")).playlist);
    // },
    mounted() {
        console.log("子组件中mounted打印");
        //使用this 指向当前实例
        console.log(this.playlist);
    },
};
</script>

<style lang="less" scoped>
.itemMusicTop {
    width: 100%;
    height: 1rem;
    display: flex;
    justify-content: space-between;
    align-items: center;
    // padding: 0.2rem;
    position: relative;
    .itemLeft,
    .itemRight {
        width: 25%;
        height: 100%;
        display: flex;
        align-items: center;
        justify-content: space-between;
        span {
            font-size: 0.4rem;
            color: #fff;
        }
        img {
            fill: #fff; //填充颜色
        }
    }
    .bgimg {
        width: 100%;
        height: 11rem;
        position: fixed;
        z-index: -1;
        filter: blur(30px);
    }
}
</style>