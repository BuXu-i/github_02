<template>
    <TopNay />
    <SwpierTop />
    <lconList />
    <MusicList />
</template>

<script>
// @ is an alias to /src  别名
// import HelloWorld from "@/components/HelloWorld.vue";
import TopNay from "@/components/home/TopNay.vue";
import SwpierTop from "@/components/home/SwpierTop.vue";
import lconList from "@/components/home/lconList.vue";
import MusicList from "@/components/home/MusicList.vue";
export default {
    name: "HomeView",
    components: {
        TopNay,
        SwpierTop,
        lconList,
        MusicList,
    },
};
</script>
