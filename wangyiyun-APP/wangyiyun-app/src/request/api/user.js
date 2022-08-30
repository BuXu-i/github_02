//获取用户详情
import servece from "..";

//获取用户详情
export function userDetail(id) {
    return servece({
        method: "get",
        url: `/user/detail?uid=${id}`,
    });
}

//获取账号信息
export function userAccount() {
    return servece({
        methch: "get",
        url: `/user/account`,
    });
}

// 获取用户信息 , 歌单，收藏，mv, dj 数量
export function userSubcount() {
    return servece({
        method: "get",
        url: `/user/subcount`,
    });
}
// 获取用户歌单
export function userPlaylist(id) {
    return servece({
        method: "get",
        url: `/user/playlist?uid=${id}`,
    });
}
