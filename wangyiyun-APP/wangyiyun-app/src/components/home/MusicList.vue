<template>
    <div class="musicList">
        <div class="musicTop">
            <div class="title">发现好歌单</div>
            <div class="more">查看更多</div>
        </div>
    </div>
    <div class="musicContent">
        <van-swipe :loop="false" :width="150" :show-indicators="false" class="my-swipe">
            <!-- vue2 语法中不给key 会报错 -->
            <van-swipe-item v-for="item in state.musicList" :key="item" class="op">
                <router-link :to="{path:'/ltemMusic',query:{id:item.id}}">
                    <img :src="item.picUrl" alt="" />
                    <span class="playCount">
                        <svg class="icon" aria-hidden="true">
                            <use xlink:href="#icon-laohu"></use>
                        </svg>
                        {{changeCount(item.playCount)}}
                    </span>
                </router-link>
            </van-swipe-item>
        </van-swipe>
    </div>
</template>

<script>
import { getMusicList } from "@/request/api/home.js";
import { onMounted, ref, reactive, methods } from "vue";
export default {
    //vue3 setup
    setup() {
        const state = reactive({
            musicList: [],
        });
        onMounted(async () => {
            let res = await getMusicList();
            console.log("vue3setup");
            console.log(res);
            state.musicList = res.data.result;
        });
        function changeCount(num) {
            if (num >= 100000000) {
                //toFixed(1) 小数点后个数
                return (num / 100000000).toFixed(1) + "亿";
            } else if (num >= 10000) {
                return (num / 10000).toFixed(1) + "万";
            }
        }
        return { state, changeCount };
    },
    // //使用vue2 进行渲染
    // data() {
    //     return {
    //         musicList: [],
    //     };
    // },
    // methods: {
    //     async getGneden() {
    //         let res = await getMusicList();
    //         console.log(res);
    //         this.musicList = res.data.result;
    //     },
    //     changeCount: function (num) {
    //         if (num >= 100000000) {
    //             //toFixed(1) 小数点后个数
    //             return (num / 100000000).toFixed(1) + "亿";
    //         } else if (num >= 10000) {
    //             return (num / 10000).toFixed(1) + "万";
    //         }
    //     },
    // },
    // mounted() {
    //     this.getGneden();
    // },
};
</script>

<style lang="less" scoped>
.musicList {
    width: 100%;
    // height: 5rem;
    padding: 0.2rem;
    .musicTop {
        width: 100%;
        height: 0.6rem;
        display: flex;
        justify-content: space-between;
        margin-bottom: 10px;
        .title {
            font-size: 0.3rem;
            font-weight: 900;
        }
        .more {
            border: 1px solid #ccc;
            text-align: center;
            line-height: 0.6rem;
            padding: 0 0.2rem;
            border-radius: 0.4rem;
        }
    }
}
.musicContent {
    width: 100%;
    height: 4rem;
    .my-swipe {
        width: 100%;
        height: 3rem;
        .van-swipe__track {
            .van-swipe-item {
                margin-left: 10px;
                img {
                    width: 100%;
                    height: 80%;
                }
            }
        }
    }
}
</style>