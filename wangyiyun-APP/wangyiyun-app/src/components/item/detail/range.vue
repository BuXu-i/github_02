
<template>
    <!-- 进度条 -->
    <div>
        <input type="range" class="range" :min="0" :max="alltime" v-model="currentime" step="0.01">
    </div>
</template>

<script>
import { mapState, mapMutations } from "vuex";
export default {
    data() {},
    computed: {
        //当前时间  总时间  时间改变
        ...mapState(["currentime", "alltime"]),
    },
    methods: {
        ...mapMutations(["updateCurrentime"]),
    },
    mounted() {
        console.log("我是进度条");
        console.log(this.$parent); //
    },
};
</script>

<style lang="less" scoped>
.range {
    width: 100%;
    color: rgb(128, 249, 249);
}
</style>