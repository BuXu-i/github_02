<template>
    <div class="box">
        <div v-for="(item,index) in playList" :key="item" :class="{'index':playlistIndex==index}" @click="getLytic({index,id:item.id}) ">
            <span>{{index+1}} {{item.al.name}}</span>
            <svg class="icon" aria-hidden="true" @click.stop="delpalyList(index)">
                <use xlink:href="#icon-shanchu"></use>s
            </svg>
        </div>
    </div>
</template>

<script>
import { mapState, mapActions, mapMutations } from "vuex";
export default {
    data() {
        return {};
    },
    computed: {
        //播放队列  当前播放下标
        ...mapState(["playList", "playlistIndex"]),
    },
    methods: {
        //获取歌词 //删除当前歌曲
        ...mapMutations(["delpalyList"]),
        ...mapActions(["getLytic"]),
    },
    mounted() {
        console.log("播放列表");
        console.log(this.playList);
    },
};
</script>

<style lang="less" scoped>
.box {
    // width: 200px;
    height: 4rem;
    position: fixed;
    top: 60%;
    left: 40%;
    border-radius: 0.4rem;
    padding: 0 0.2rem;
    background-color: rgb(99, 103, 103);
    overflow: scroll;
    .index {
        background-color: rgb(165, 167, 170);
    }
    div {
        margin: 0.08rem 0;
        padding: 0 0.1rem;
        border-radius: 0.4rem;
        background-color: aqua;
    }
}
</style>