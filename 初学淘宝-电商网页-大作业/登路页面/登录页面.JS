var deng = document.querySelector('.deng');
var zhu = document.querySelector('.zhu');
var mima = document.querySelector('#mima');
var zhanghu = document.querySelector('#zhanghu');
// 验证密码账户
deng.onclick = function() {
    if (!mima.value || !zhanghu.value) {
        alert('填写完整!');
        return;
    }
    var mimasql = localStorage.getItem(zhanghu.value);
    if (mimasql) //注意非空会报错
        mimasql = mimasql.split('&');
    else {
        alert('账户不存在!')
        return;
    }
    if (mimasql[0] == mima.value) {
        window.location.href = "../首页.html?" + mimasql[1];
    } else {
        alert('输入密码不正确!');
    }
}
zhu.onclick = function() {
    location.href = '../注册页面/注册.html';
}