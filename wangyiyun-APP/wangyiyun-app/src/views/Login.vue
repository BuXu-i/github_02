<template>
    <!-- <router-view name="login" /> -->
    <!-- isloginShow  直接使用 会if不显示 有时候报错 渲染期间访问 未在实例上定义
没反应 使用store直接访问则可以 -->
    <div v-if="$store.state.isloginShow">
        <Login />
    </div>
</template>

<script>
import Login from "@/components/login/Login.vue";
export default {
    data() {
        return {};
    },
    methods: {},
    components: {
        Login,
    },
};
</script>

<style lang="less" scoped>
</style>