<template >
    <ltemMusicTop :playlist="playlist" />
    <!-- :ItemList="state.itemList 歌单详情 不包括歌曲详细信息 :subscribedCount='state.subscribedCount' 收藏数 -->
    <ltemMusicList :itemList="itemList " :subscribedCount='playlist.subscribedCount' />
</template>

<script>
// 在setup中获取路由实例需要导入
import { useRoute } from "vue-router";
import { computed, onMounted, reactive, ref, toRefs } from "vue";
//服务器获取数据 接口
import { getMusicItemList, getItemList } from "@/request/api/itme";
//子组件
import ltemMusicTop from "@/components/item/ltemMusicTop.vue";
import ltemMusicList from "@/components/item/ltemMusicList.vue";

export default {
    setup() {
        const state = reactive({
            playlist: {}, //
            itemList: [], //歌单的详情数据
        });
        onMounted(async () => {
            let id = useRoute().query.id; //获取当前活跃的路由实例 的id 下面传入自定义axsoi获取数据
            let res = await getMusicItemList(id); //获取第一次数据
            console.log("获取第一次数据");
            // console.log(res.data.playlist);
            state.playlist = res.data.playlist;
            //在页面刷新时 数据丢失
            //此处已经在渲染时 数据还未传入
            //导致子组件拿不到数据 报错
            //解决 在第一次进入页面时 将数据存储起来
            //下次在未找到get数据时直接读取本地存储
            let result = await getItemList(id); //获取第二次数据
            console.log("打印歌单详情，获取第二次数据");
            // console.log(result); //.subscribedCount 找不到这个 收藏个数
            state.itemList = result.data.songs; //给歌单里获取的歌曲
            //使用sessionStorage 保存
            sessionStorage.setItem("itemDetail", JSON.stringify(state));
            console.log(state);
            console.log("路由结束");
            //导入vuex 歌单
        });
        console.log("出去");

        return { ...toRefs(state) };
    },
    components: {
        ltemMusicTop,
        ltemMusicList,
    },
};
</script>

<style lang="less" scoped>
</style>