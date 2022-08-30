<template >
    <div class="head">
        <!-- 详细热搜还是搜索结果 -->
        <!--  有则展示 搜索结果 searchKeywords单独这个无论是否有数据都被判断为true 所以使用searchKeywords[0] -->
        <div v-if="!searchKeywords[0]">
            <img :src="searchHotDetail[0].iconUrl" alt=""><br>
            <span v-for="item in searchHotDetail" :key="item.id">
                <div @click="$emit('clickKey',item.searchWord)">
                    <p style="color:rgb(211, 208, 208);">{{item.searchWord}}</p>&nbsp;&nbsp;
                    <p style="color:rgb(202, 151, 151);">指数:{{item.score}}&nbsp;!</p><br>
                    &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <p style="color: rgb(139, 108, 108);">{{item.content}}</p><br>
                </div>
            </span>
        </div>
        <div v-else>
            <p>搜索结果</p>
            <!-- @click="updatePlayList()" -->
            <span v-for="item in searchKeywords" :key="item.id" class="" @click="updatePlayList(item);getLytic({index:0,id:item.id});updateIsbtnShow(true)">
                <div>
                    &nbsp;&nbsp;&nbsp; <p>《{{item.name}}》</p><br>
                    &nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<p>专辑：{{item.album.name}}</p><br>
                </div>
            </span>
        </div>
    </div>

</template>

<script>
import { mapMutations, mapActions } from "vuex";
export default {
    data() {
        return {};
    }, // 详细热搜  搜索结果展示
    props: ["searchHotDetail", "searchKeywords"],
    emits: ["clickKey"],
    methods: {
        ...mapMutations(["updatePlayList", "updateIsbtnShow"]),
        ...mapActions(["getLytic"]),
    },
    mounted() {
        console.log("打印传入的详细热搜");
        if (this.searchKeywords) {
            console.log(true);
        } else console.log(false);
        console.log(this.searchKeywords);
    },
};
</script>

<style lang="less" scoped>
.head {
    width: 100%;
    height: 80%;
    img {
        width: 0.8rem;
        height: 0.8rem;
        // background: pink;
    }
    span {
        display: block;
        margin-top: 0.2rem;
        font-size: 0.34rem;
        background-color: rgb(175, 177, 178);
        border-radius: 0.4rem;
        p {
            border-bottom: 1px solid rgb(210, 96, 96);
            display: inline-block;
        }
    }
}
</style>