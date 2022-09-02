<!-- 个人信息展示 -->
<template>
    asdasd
    {{Detail}}
    {{Userinfo}}
    -----------------------------
    <div>
        <svg class="icon liebiao" aria-hidden="true" @click="$router.go(-1);">
            <use xlink:href="#icon-houtui"></use>
        </svg>
        <!-- <button @click="storeUserDetail()">我是按钮</button> -->
    </div>
</template>

<script>
import { mapState, mapMutations, mapActions } from "vuex";
export default {
    data() {
        return {
            Detail: null, //获取用户详细信息
            Account: null, //获取账号信息
            Subcount: null, //获取用户信息  , 歌单，收藏，mv, dj 数量
            Playlist: null, //获取用户歌单
        };
    },
    computed: {
        ...mapState("modelueInfouser", ["Userinfo"]),
    },
    methods: {
        //获取用户信息的store
        ...mapActions("modelueInfouser", [
            "storeUserDetail",
            "storeUserAccount",
            "storeUserSubcount",
            "storeUserPlaylist",
        ]),
    },
    async mounted() {
        //获取用户详细信息
        this.Detail = await this.storeUserDetail();
        console.log("嘿嘿1");
        console.log(this.Detail);
        //获取账户信息
        this.Account = await this.storeUserAccount();
        console.log("嘿嘿2");
        console.log(this.Account);
        //获取用户信息  , 歌单，收藏，mv, dj 数量
        this.Subcount = await this.storeUserSubcount();
        console.log("嘿嘿3");
        console.log(this.Subcount);
        ////获取用户歌单
        this.Playlist = await this.storeUserPlaylist();
        console.log("嘿嘿4");
        console.log(this.Playlist);
    },
};
</script>

<style lang="less" scoped>
</style>