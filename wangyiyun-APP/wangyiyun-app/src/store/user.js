import {
    userDetail, //获取用户详情
    userAccount, //获取账号信息
    userSubcount, //获取用户信息 , 歌单，收藏，mv, dj 数量
    userPlaylist, // 获取用户歌单
} from "@/request/api/user";
export const modelueInfouser = {
    state: {
        id: "", //用户Id
    },
    mutations: {
        //上传id
        uodataid(state, id) {
            state.id = id;
        },
    },
    actions: {
        async storeUserDetail(context, id) {
            //获取用户详情
            return await userDetail(id);
        },
        async storeUserAccount(context) {
            return await userAccount(); //获取账号信息
        },
        async storeUserSubcount(context) {
            return await userSubcount(); //获取用户信息 , 歌单，收藏，mv, dj 数量
        },
        async storeUserPlaylist(context, id) {
            return await userPlaylist(id); // 获取用户歌单
        },
    },
};
