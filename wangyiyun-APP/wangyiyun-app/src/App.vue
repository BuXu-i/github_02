<template>
    <FooterMusic />
    <!-- 路由占位符 -->
    <!-- 是to ：name="home"  -->
    <router-view />

</template>
<script>
import FooterMusic from "@/components/item/FooterMusic.vue"; //播放器
import { mapState } from "vuex";
// import iconfont from "../public/fonts.js";
export default {
    data() {
        return {};
    },
    watch: {
        ...mapState["isloginShow"], //根据值来确定全局播放器是否显示 未使用
    },
    components: {
        FooterMusic,
    },
};
</script>

<style lang="less">
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box; //怪异盒子 不会撑开其他盒子
}
.icon {
    width: 0.5rem;
    height: 0.5rem;
    vertical-align: -0.15em;
    fill: currentColor;
    overflow: hidden;
}
a {
    color: #000;
}
</style>

