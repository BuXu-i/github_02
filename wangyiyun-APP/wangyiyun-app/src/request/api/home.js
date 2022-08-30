import servece from "../index";

//获取轮播banner 数据
export function getBanner() {
    console.log("axios请求");
    return servece({
        method: "GET",
        url: "/banner?type=2",
    });
}
// musicContent 数据
export function getMusicList() {
    console.log("获取getMusicList 数据");
    return servece({
        method: "GET",
        url: "/personalized?limit=10",
    });
}
