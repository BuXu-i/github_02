import servece from "..";
//获取歌单详情页的数据
export function getMusicItemList(id) {
    return servece({
        method: "get",
        url: `/playlist/detail?id=${id}`,
    });
}
//获取歌单的所有歌曲
export function getItemList(id) {
    return servece({
        method: "get", //可选参数 limit 获取歌曲数量 offset 默认值为0 获取服务器歌单序号的起始+1 即(1到10 )
        url: `/playlist/track/all?id=${id}&limit=8&offset=1`,
    });
}
export function getmusicLyric(id) {
    console.log("正在处理返回歌词");
    return servece({
        method: "get",
        url: `/lyric?id=${id}`,
    });
}
