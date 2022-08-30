<template>
    <div class="searchHistory" v-if="Historyshow">
        <span class="searchSpan">历史</span>
        <!-- 点击后删除所有历史 deleteHistory(this.$refs.inputref.value)-->
        <svg class="icon" aria-hidden="true" @click="$emit('deleteHistory',this.$refs.inputref.value)">
            <use xlink:href="#icon-shanchu"></use>
        </svg>
        <!-- @click="clickKey(this.$refs.inputref.value)"  历史记录 clickKey($event.target.innerHTML)-->
        <!-- 这里还可以加一个点击事件 将搜索框内内容变为点击的历史记录 -->
        历史记录
        <span v-for="item in keyWorldList" :key="item.id" class="spanKey" @click="$emit('clickKey',$event.target.innerHTML) ">
            {{item}}
        </span>
        <!-- 热搜榜  这个不用更新 只需要获取一遍 -->
        热搜榜
        <p v-for="item in searchHot" :key="item.id" class="classHot" @click="$emit('clickKey',item.first) ">
            {{item.first}}
        </p>
    </div>
    <div v-else class="searchHistory">
        <!-- //服务端返回搜索 搜索建议-->
        <p>搜索建议:</p>
        <span v-for="item in searchSuggestc" :key="item.id" class="sugg" @click="$emit('clickKey',item.name) ">
            &nbsp;&nbsp;&nbsp;<p>{{item.name}} </p>
        </span>
    </div>
</template>

<script>
export default {
    data() {
        return {};
    },
    props: ["Historyshow", "searchSuggestc", "searchHot", "keyWorldList"],
    emits: ["deleteHistory", "clickKey"],
};
</script>

<style lang="less" scoped>
.searchHistory {
    width: 100%;
    padding: 10px;
    position: relative;
    .searchSpan {
        // font-size: .4rem;
        font-weight: 800; //加粗
    }
    .spanKey {
        padding: 0.1rem 0.2rem;
        background-color: rgb(159, 156, 156);
        border-radius: 0.4rem;
        margin: 0.1rem 0.2rem;
        color: #000;
    }
    .icon {
        width: 0.3rem;
        height: 0.3rem;
        position: absolute;
        right: 0.2rem;
    }
    .classHot {
        width: 100%;
        height: 0.5rem;
        background-color: rgb(138, 138, 185);
    }
    //搜索建议中
    .sugg {
        display: block;

        p {
            padding: 0 0.08rem;
            background-color: rgb(175, 177, 178);
            border-radius: 0.4rem;
            border-bottom: 1px solid rgb(210, 96, 96);
            margin-top: 0.2rem;
            display: inline-block;
        }
    }
}
</style>