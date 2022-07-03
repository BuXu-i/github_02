// 验证代码
// 字符串操作
var p = document.querySelector('.d .d-youce .d-1 .geren p');
p.innerHTML = mingzi;

// 共计五个区域需要可视效果
//a中下拉框的所有人的父亲
var aUl = document.querySelector(".a ul");
var aUl_1 = document.querySelector(".a ul li:nth-child(1) div");
var aUl_4 = document.querySelector(".a ul li:nth-child(4) div");
var aUl_6 = document.querySelector(".a ul li:nth-child(6) div");
var aUl_8 = document.querySelector(".a ul li:nth-child(8) div");
var aUl_9 = document.querySelector(".a ul li:nth-child(9) div");
//第一个
aUl.children[0].addEventListener('mouseover', a_1_over);

function a_1_over() {
    aUl_1.style.display = 'block';
}
aUl.children[0].addEventListener('mouseout', a_1_out);

function a_1_out() {
    aUl_1.style.display = 'none';
}
// 第二个
aUl.children[3].onmouseover = function() {
    aUl_4.style.display = 'block';
}
aUl.children[3].onmouseout = function() {
    aUl_4.style.display = 'none'
}
aUl.children[5].onmouseover = function() {
    aUl_6.style.display = 'block';
}
aUl.children[5].onmouseout = function() {
    aUl_6.style.display = 'none'
}
aUl.children[7].onmouseover = function() {
    aUl_8.style.display = 'block';
}
aUl.children[7].onmouseout = function() {
    aUl_8.style.display = 'none'
}
aUl.children[8].onmouseover = function() {
    aUl_9.style.display = 'block';
}
aUl.children[8].onmouseout = function() {
    aUl_9.style.display = 'none'
}

//上方的一个轮换图效果
var d_lun = document.querySelector('.d .d-zhong .d-lun');
var imgk = 0;
d_lun.onmouseover = function() {
    d_lun.children[1].style.display = 'block';
    d_lun.children[2].style.display = 'block';
}
d_lun.onmouseout = function() {
    d_lun.children[1].style.display = 'none';
    d_lun.children[2].style.display = 'none';
}

// 循环触发
var dinshiqi_a = null;

function fa() {
    dinshiqi_a = setInterval(img, 1000);
}
d_lun.children[3].children[0].style.background = 'red'; //刷新页面第一个便是红色
fa();


function lun(k) {
    // 更改图片和自定义属性序号
    d_lun.children[0].dataset.xuhao = k;
    d_lun.children[0].src = './images/' + k + '.jpg';
    // 更改小圆圈 1 2 3 4 5
    if (k == 1) {
        d_lun.children[3].children[4].style.background = 'white';
    } else
        d_lun.children[3].children[k - 2].style.background = 'white';
    d_lun.children[3].children[k - 1].style.background = 'red';
    var op = d_lun.children[3].children[k - 1].dataset.quan;
    d_lun.nextElementSibling.children[2].children[0].innerHTML = op;

}
// lun 函数的补充  点击左右箭头使用此函数 还原  用于 遍历还原 li小圆圈
//  任何时候 都可以使用该函数 来还原 圈圈！！！
function lunHY(k) {
    // 更改图片和自定义属性序号
    d_lun.children[0].dataset.xuhao = k;
    d_lun.children[0].src = './images/' + k + '.jpg';
    for (var key = 0; key < 5; key++) {
        d_lun.children[3].children[key].style.background = 'white';
    }
    d_lun.children[3].children[k - 1].style.background = 'red';
    var op = d_lun.children[3].children[k - 1].dataset.quan;
    d_lun.nextElementSibling.children[2].children[0].innerHTML = op;
}

function img() {
    if (imgk >= 5) {
        imgk = 1;
    } else {
        imgk++;
    }
    lun(imgk);
}
// 设计极其不合理
// 小箭头 和小圆圈的点击功能
var setkey = 0;
d_lun.children[1].onclick = function lunLR() {
    // setkey++;
    clearInterval(dinshiqi_a); //暂停计算
    if (imgk > 1)
        imgk--;
    else imgk = 5;
    lunHY(imgk); //补充函数 设置延迟调用 会出现多个计时器的问题
    fa();
}

d_lun.children[2].onclick = function lunLR() {
    clearInterval(dinshiqi_a); //暂停计算
    if (imgk < 5)
        imgk++;
    else imgk = 1;
    lunHY(imgk); //补充函数 设置延迟调用 会出现多个计时器的问题
    fa();
}

//小圆圈 效果实现  使用 获取被点击的子盒子。。。。 
//由于子盒子没有嵌套 所以点的是谁就是谁
d_lun.children[3].onmouseover = function(e) {
    var key = e.target.dataset.quan;
    clearInterval(dinshiqi_a); //暂停定时器 随时进行还原
    if (typeof(key) == "string") {
        imgk = key;
        lunHY(key);
    }
}
d_lun.children[3].onmouseout = function(e) {
    fa();
}

// 下方的一个轮换图效果

var d_xia = document.querySelector(".d .d-zhong .d-xia");
var d_a = d_xia.children[0].children[1];
var d_b = d_xia.children[1].children[1];

d_xia.onmouseover = function() {
    d_a.style.display = 'block';
    d_b.style.display = 'block';
}
d_xia.onmouseout = function() {
    d_a.style.display = 'none';
    d_b.style.display = 'none';
}
var d_bool = 1;

d_a.onclick = function() {
    d_AB();
}
d_b.onclick = function() {
    d_AB();
}

function d_AB() {
    // 没有加左右箭头识别 是因为只有两张图片
    if (d_bool == 1) {
        d_bool++;
    } else d_bool--;
    d_a.previousElementSibling.src = "./images/轮换AB/" + d_bool + "-A.png";
    d_b.previousElementSibling.src = "./images/轮换AB/" + d_bool + "-B.png";
}
setInterval(d_AB, 3000);
// 轮换图右侧效果实现
var d_you_ul = document.querySelector(".d .d-youce .d-2 ul");
var d_you_dinshiqi = null;
d_ayou_fa(); //启动
function d_ayou_fa() {
    d_you_dinshiqi = setInterval(d_you_img, 3000);
}

var d_you_img_boll = 2;
d_you_img();

function d_you_img() {
    d_you_ul.previousElementSibling.src = './images/右侧轮换/' + 'd-a-you-' + d_you_img_boll % 2 + '.png';
    d_you_ul.children[d_you_img_boll % 2].style.background = 'red';
    d_you_ul.children[++d_you_img_boll % 2].style.background = 'white';
}
// 右侧 小圆效果
d_you_ul.onmouseover = function(e) {
    clearInterval(d_you_dinshiqi);
    if (typeof e.target.dataset.quan == "string") {
        d_you_ul.previousElementSibling.src = './images/右侧轮换/' + 'd-a-you-' + e.target.dataset.quan + '.png'
        d_you_ul.children[e.target.dataset.quan].style.background = 'red';
        d_you_ul.children[1 - e.target.dataset.quan].style.background = 'white';
    }
}
d_you_ul.onmouseout = function() {
    d_ayou_fa(); //启用定时器
}

// 布局效果 实现

//1. 右侧
var juedui = document.querySelector('.juedui-r');
var dinbu = document.querySelector('.juedui-r ul li:nth-child(3)');
//2. 搜索框
var woyaofei = document.querySelector('.c ul .shousuo div');


jueduifa();
window.onscroll = jueduifa;
// 勉强完成 有些问题
function jueduifa() {
    if (scrollY > 800) {
        dinbu.style.display = 'block'; //当出现的时候 就不用动了
        woyaofei.className = '我要飞';
        console.log(scrollY);
        console.log(juedui.offsetTop + "top");
        if (1400 - scrollY > 46) {
            juedui.style.top = 1400 - scrollY + 'px';
        }
    } else {
        dinbu.style.display = 'none'; //消失的时候代表绝对定位在上方
        woyaofei.className = '';
        console.log(scrollY);
        console.log(juedui.offsetTop + "top");
    }
    //控制绝对定位的定位的定位的定位的定位的定位！！！！！！！！！！！！！！！！！！！！！
}

//3.其他效果  如缩小到一定程度时 轮换图隐藏 各个宽度改变自适应

//4. 两个页面信息交互 操作