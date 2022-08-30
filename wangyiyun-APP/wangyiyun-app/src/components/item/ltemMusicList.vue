<template >
    <div v-if="Bool==true">
        <div>
            歌单详情嘿嘿 收藏数 ar 里面是数组
            {{changeCount(subscribedCount)}}
            <!-- {{itemList}} -->
        </div>
        <div v-for="(list, index) in itemList" :key="list.id" @click="getLytic({index,id:list.id});
        updatePlayList(itemList);
        updateIsbtnShow(true);
        ">
            <img :src="list.al.picUrl" alt="" class="_img">
            <span>{{list.name}} </span>&emsp;
            <span>{{list.ar[0].name}}</span>
        </div>
    </div>
</template>

<script>
import { mapState, mapMutations, mapActions } from "vuex";
export default {
    // props: {
    //     itemList: null, //歌单歌曲详情
    //     subscribedCount: Number, //歌单的收藏个数  父 组件传来
    // },
    data() {
        return {
            Bool: false,
        };
    },
    props: ["itemList", "subscribedCount"],
    watch: {
        itemList: function (newval, oldval) {
            this.Bool = true;
            console.log("捕获到BOOL改变2");
            console.log(this.itemList);
            deep: true;
        },
    },
    methods: {
        changeCount(subscribedCount) {
            if (subscribedCount >= 100000000) {
                //toFixed(1) 小数点后个数
                return (subscribedCount / 100000000).toFixed(1) + "亿";
            } else if (subscribedCount >= 10000) {
                return (subscribedCount / 10000).toFixed(1) + "万";
            }
        },
        // listIndex(Index) {
        //     //点击后更改播放数组的下标
        //     console.log("更改播放下标");
        //     this.playlistIndex = Index;
        // },
        // AudioupShow() {
        //     this.updateIsbtnShow(true);
        //     this.$nextTick(() => {
        //         console.log(this.$refs);
        //         // this.$refs.audio.play();
        //     });
        // },
        ...mapMutations(["updatePlayList", "updateIsbtnShow", "listIndex"]),
        ...mapActions(["getLytic"]),
    },
    mounted() {
        console.log("子组件获取的歌单数据");
        console.log("此处为空是因为 子组件渲染要早于获取数据 ");
        console.log(this.itemList);
        console.log(this.subscribedCount);
        // console.log(props.ItemList[0].al.picUrl);
    },
    computed: {
        ...mapState(["playList", "playlistIndex", "isbtnShow"]),
    },
};
</script>

<style lang="less" scoped>
img {
    width: 1rem;
    height: 1rem;
}
</style>