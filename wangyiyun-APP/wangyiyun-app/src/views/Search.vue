<template>
    <div class="searchTop">
        <svg class="icon" aria-hidden="true" @click="$router.go(-1)">
            <use xlink:href="#icon-houtui"></use>
        </svg>
        <input type="text" placeholder="奥特曼" ref="inputref" @keydown.enter="enterKey($event.target.value)" @input="inputKey($event.target.value)" @focus="focusKey($event.target.value)" @blur="blurKey()">
        <!-- 点击搜索 -->
        <svg class="icon" aria-hidden="true" @click="clickKey(this.$refs.inputref.value,this.$refs.inputref.placeholder)">
            <use xlink:href="#icon-sousuoleimu"></use>
        </svg>
    </div>
    <!-- 显示历史记录 判断条件是是否获得热搜的数据  搜索辅助显示与否-->
    <template v-if="searchHot[0]&&SuggestcHotshow||1">
        <!-- 属性:         //历史结果和搜索建议切换         关键字搜索建议             热搜,                   历史记录               方法: 删除所有历史记录                 //点击后搜索            -->
        <searchHotHistory :Historyshow="Historyshow" :searchSuggestc="searchSuggestc" :searchHot='searchHot' :keyWorldList="keyWorldList" @deleteHistory='deleteHistory' @clickKey='clickKey' />
    </template>
    <!-- 显示热搜结果 -->
    <template v-if="searchHotDetail[0]">
        <!-- 属性:详细热搜  搜索结果  方法: 点击搜索事件 -->
        <searchHotDetail :searchHotDetail='searchHotDetail' :searchKeywords='searchKeywords' @clickKey='clickKey' />
    </template>
</template>

<script>
//搜索结果在本页面处理就好 不需要vuex
import {
    getsearchKeywords, //search 关键字 返回搜索结果
    getsearchSuggestc, // 搜索建议
    getsearchHot, //热搜列表
    getsearchHotDetail, //详细的热搜列表
} from "@/request/api/search.js"; //api导入
//子组件  所有子组件使用数据在此页面处理好  子组件只需使用即可
import searchHotDetail from "@/components/search/searchHotDetail.vue";
import searchHotHistory from "@/components/search/searchHotHistory.vue";
//歌曲导入播放队列
import { mapState, mapMutations } from "vuex";

export default {
    data() {
        return {
            keyWorldList: ["孤勇者", "画"],
            Historyshow: true, //历史结果和搜索结果切换
            SuggestcHotshow: false, //搜索辅助(即热搜前十和搜索建议) 反之不显示搜索辅助  在本页面由聚焦与否控制
            // HotDetailshow: false, //详细的热搜 和Historyshow结果切换
            // searchHotshow: true, //热搜和关键字搜索的显示开关  //好像不需要 先留着 ！！！
            timer: "",
            blurtimer: "",
            searchKeywords: {}, //search 关键字 搜索结果
            searchSuggestc: {}, // 搜索建议
            searchHot: {}, //热搜列表
            searchHotDetail: {}, //详细的热搜列表
        };
    },
    components: {
        searchHotDetail,
        searchHotHistory,
    },
    methods: {
        //vuex中导入和播放队列有关的函数
        ...mapMutations([""]),
        //回车键搜索
        enterKey(value) {
            console.log("回车");
            console.log(value);
            if (!value) return;
            this.fungetsearchKeywords(value); //关键字
        },
        //检测到输入后 近似搜索 需要做锁
        inputKey(value) {
            console.log("检测到输入");
            var _this = this;
            clearTimeout(_this.timer); //清除定时器
            if (!value) {
                this.Historyshow = true;
                return;
            }
            this.timer = setTimeout(function () {
                _this.fungetsearchSuggestc(value);
            }, 700);
        },
        // 聚焦后搜索
        focusKey(value) {
            console.log("聚焦后");
            console.log(value);
            this.SuggestcHotshow = true; //搜索辅助
            if (!value) {
                //value为空 调用热搜接口 获取热搜数据 并显示
                console.log("调用热搜接口");
                this.fungetsearchHot(); //显示热搜列表
            } else {
                console.log("聚焦后 输入框有值 调用了关键字搜索");
                //聚焦后 输入框中有数据 则 将其替换成关键字搜索
                //聚焦后  输入框仍有数据
                // this.searchHot = {}; //删除热搜列表 显示关键字
                this.fungetsearchSuggestc(value); //聚焦后直接关键字搜索 不需要节流
            }
        },
        //失去焦点
        blurKey() {
            console.log("失去焦点");
            clearTimeout(this.blurtimer);
            this.blurtimer = setTimeout(() => {
                //因为搜索辅助消失太快 历史记录检测不到点击
                this.SuggestcHotshow = false; //搜索辅助
            }, 100);
        },
        //点击后搜索 这里是直接出搜索结果
        clickKey(value, placeholder) {
            console.log("点击");
            if (value) {
                console.log(value);
                this.fungetsearchKeywords(value);
            } else {
                console.log(placeholder);
                this.fungetsearchKeywords(placeholder); //关键字
            }
        },
        /*********************************************** */
        // 返回结果处理
        prse(obj) {
            console.log(obj);
            // 热搜和 (建议和结果) 返回的josn数据格式不一样
            if (obj.data.result) {
                console.log("prse中::");
                console.log(obj.data.result.songs);
                console.log(obj.data.result.hots);
                console.log(this.Historyshow);
                return obj.data.result.songs
                    ? obj.data.result.songs
                    : obj.data.result.hots;
            }
        },
        //search 关键字 返回搜索结果
        async fungetsearchKeywords(value) {
            console.log("搜索结果");
            this.searchKeywords = this.prse(await getsearchKeywords(value));
            console.log(this.searchKeywords);
        },
        // 搜索建议 返回搜索结果
        async fungetsearchSuggestc(value) {
            console.log("搜索建议: " + value);
            // 执行time关键字  //Historyshow 历史结果和搜索结果切换
            this.Historyshow = value ? false : true; //执行搜索 显示关键字搜索结果
            if (value)
                this.searchSuggestc = this.prse(await getsearchSuggestc(value));
        }, //热搜列表 返回搜索结果
        async fungetsearchHot() {
            this.searchHot = this.prse(await getsearchHot());
            console.log(this.searchHot);
        }, //详细的热搜列表 返回搜索结果
        async fungetsearchHotDetail() {
            console.log("获取详细数据");
            let result = await getsearchHotDetail();
            this.searchHotDetail = result.data.data;
            console.log(this.searchHotDetail);
        },
        // 搜索后存入浏览器存储
        //删除所有搜索浏览器历史
        deleteHistory() {},
    },
    mounted() {
        console.log("详细的热搜列表 获取后直接显示显示");
        //详细的热搜列表
        this.fungetsearchHotDetail(); //获取
        //本地存储浏览器存储中的数据  转化为数组后导入
        // this.keyWorldList += localStorage.getItem("keyWorldList");
        // console.log(this.keyWorldList);
    },
};
</script>

<style lang="less" scoped>
.searchTop {
    width: 100%;
    height: 1rem;
    padding: 0 0.2rem;
    display: flex;
    align-items: center;

    input {
        width: 60%;
        margin-left: 0.2rem;
        border: none;
        border-bottom: 1px solid rgb(160, 160, 160);
    }
}
</style>