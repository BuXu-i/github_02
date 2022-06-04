var btn = document.querySelector('#btn')
console.log(btn);

btn.onclick = () => {
    var xhr = new XMLHttpRequest();
    // console.log(xhr);
    xhr.open('get', 'http://127.0.0.1:3000/ajax/errer_07')
    xhr.send();
    xhr.onload = () => {
        console.log('?');
        // console.log(xhr.responseText)
        // status获取状态码
        console.log(xhr.status)
        console.log(typeof xhr.status)
        if (xhr.status === 400) {
            alert('请求出错!  400')
        } else if (xhr.status === 404) {
            alert('未找到该请求! 404 found')
        } else if (xhr.status === 500) {
            alert('服务器错误! 500')
        } else {
            alert('成功！！')
        }
        // ajax状态码:表示Ajax请求的过程状态 ajax对象返回的
        //http状态码:表示请求的处理结果 是服务器端返回的
    };
    // 但断网时 会触发 onerror事件
    xhr.onerror = () => {
        alert('网络中断!检查网络!')
    };
}