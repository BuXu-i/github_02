var a = document.querySelector('.a');
var button = document.querySelector('.zhuce');
var button1 = document.querySelector('.fanhui');
var button2 = document.querySelector('.qingchu');
console.log(a.children[2].children[1].value);
button.onclick = function() {
    if (a.children[0].children[1].value != '' && a.children[1].children[1].value != '' && a.children[2].children[1].value != '') {
        if (localStorage.getItem(a.children[1].children[1].value)) {
            alert('账户已存在!')
            return;
        }
        window.localStorage.setItem(a.children[1].children[1].value, a.children[2].children[1].value + '&' + a.children[0].children[1].value);
        alert('注册成功!');
    } else {
        alert('不允许注册!请填写完整!')
    }
}
button1.onclick = function() {
    window.location.href = '../登路页面/登路页面.html';
}
button2.onclick = function() {
    window.localStorage.clear();
    alert('清除成功!')
}