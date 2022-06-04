var bnt = document.querySelector('.bnt');
var emailTest = /^[A-Za-z0-9\u4e00-\u9fa5]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$/;
var alret = document.querySelector('#alret');
var email = document.querySelector('.email');
// event--事件 list列表 listemer列表器
// console.log(email);
console.log(email)
email.addEventListener('blur', () => {
    if (emailTest.test(email.value)) {
        var Ajax = ajax({
            url: 'http://127.0.0.1:3000/ajax//readyState',
            date: { email: email.value },
        });
        // 这里有问题   在服务器还未返回数据时 已经往下先运行了
        // for (var i = 1; i == 1;) {
        //     if (typeof Ajax !== undefined) {
        //         console.log('?')
        //         console.log(Ajax)
        //         i++;
        //     }
        // }typeof Ajax != undefined
        console.log(typeof Ajax)
        if (typeof Ajax == undefined) {
            console.log('修改页面')
            console.log(typeof Ajax)
            var html = template('tpl', {
                username: 'zhansan',
                age: '24'
            })
            alret.innerHTML = html;
        } else {
            console.log('服务器返回数据不正确改页面')
            alret.className = 'sueccsse'
        }
    } else {
        alret.innerHTML = '格式不正确';
        alret.style.display = '';
        alret.className = 'errer';
        console.log('错误!');
    }
})