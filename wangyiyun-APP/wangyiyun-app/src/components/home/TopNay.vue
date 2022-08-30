<template>
    <div class="topNav">
        <svg class="icon" aria-hidden="true">
            <use xlink:href="#icon-bofang-"></use>
        </svg>
        <div class="topComtent">
            <span @click="$router.push('/infoUser')">我的</span>
            <span class="active">发现</span>
            <span>云村未写</span>
            <span>视频未写</span>
        </div>
        <!-- 跳转路由 search -->
        <div class="topRight" @click="$router.push('/search')">
            <!-- 搜索按钮 -->
            <svg class="icon" aria-hidden="true">
                <use xlink:href="#icon-laohu"></use>
            </svg>
        </div>
    </div>
</template>

<script>
export default {
    data() {
        return {};
    },
    methods: {},
};
</script>

<style lang="less" scoped>
.topNav {
    width: 100%;
    height: 50px;
    padding: 10px;
    display: flex;
    justify-content: space-between;
    align-items: center;
    .topComtent {
        //层级选择器
        width: 70%;
        height: 100%;
        display: flex;
        justify-content: space-around;
        align-content: center;
        font-size: 0.36rem;
        .active {
            font-weight: 900;
        }
    }
}
</style>