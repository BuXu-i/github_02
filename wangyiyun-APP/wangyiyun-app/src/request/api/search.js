import servece from "../index";
//search 关键字 返回搜索结果
export function getsearchKeywords(value) {
    return servece({
        method: "get",
        url: `/search?keywords=${value}`,
    });
}
//热搜列表
export function getsearchHot() {
    return servece({
        method: "get",
        url: `/search/hot`,
    });
}
//详细的热搜列表
export function getsearchHotDetail() {
    return servece({
        method: "get",
        url: `/search/hot/detail`,
    });
}
// 搜索建议
// 说明 : 调用此接口 , 传入搜索关键词可获得搜索建议 , 搜索结果同时包含单曲 , 歌手 , 歌单信息
// 可选参数 : type : 如果传 'mobile' 则返回移动端数据
// 调用例子 : /search/suggest?keywords=海阔天空 /search/suggest?keywords=海阔天空&type=mobile
export function getsearchSuggestc(value) {
    return servece({
        method: "get",
        url: `/search/suggest?keywords=${value}`,
    });
}
