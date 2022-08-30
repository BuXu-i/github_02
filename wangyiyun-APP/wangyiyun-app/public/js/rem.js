//对移动端做一个窗口的适配
//rem 依据根元素的字体大小决定rem尺寸大小
function remSize() {
    //获取设备宽度
    var deviceWidth = document.documentElement.clientWidth || window.innerWidth;
    if (deviceWidth > 750) {
        deviceWidth = 750;
    }
    if (deviceWidth <= 320) {
        deviceWidth = 320;
    }
    //750px--->1rem=100px 375px-->1rem=50px
    document.documentElement.style.fontSize = deviceWidth / 7.5 + "px";
    //字体大小
    document.querySelector("body").style.fontSize = 0.3 + "rem";
}
remSize();
//当窗口发生变化时 进行适配
window.onresize = function () {
    remSize(); //但窗口发生变化时 同样进行一个适配
};
