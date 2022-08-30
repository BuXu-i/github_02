<template>
    <div id="SwipierTop">
        <van-swipe :autoplay="1000" lazy-render>
            <van-swipe-item v-for="image in state.images" :key="image">
                <img :src="image.pic" />
            </van-swipe-item>
        </van-swipe>
    </div>
</template>


<script type="module">
import { getBanner } from "@/request/api/home"; //封装的 axios请求 //轮播图数据 banner
import { onMounted, reactive } from "vue";
export default {
    data() {
        return {};
    },
    methods: {},
    setup() {
        const state = reactive({
            images: [
                "https://fastly.jsdelivr.net/npm/@vant/assets/apple-1.jpeg",
                "https://fastly.jsdelivr.net/npm/@vant/assets/apple-2.jpeg",
            ],
        }); //属于异步请求
        onMounted(async () => {
            //直接使用axios 来获取数据
            // axios.get("http://localhost:3000/banner?type=2").then((res) => {
            //     console.log(res);
            //     state.images = res.data.banners;
            //     console.log(state.images);
            //     console.log(getBanner());
            // });
            //使用axios自定义模块化请求
            // console.log(getBanner());
            let res = await getBanner();
            state.images = res.data.banners;
            // console.log(res);
        });
        return { state };
    },
};
</script>

<style lang="less" scoped>
#SwipierTop {
    .van-swipe {
        width: 100%;
        padding: 0.3rem;
        .van-swipe__track {
            padding: 0 0.2rem;
            .van-swipe-item {
                img {
                    width: 100%;
                    height: 100%;
                    border-radius: 0.2rem;
                }
            }
        }
    }
}
</style>