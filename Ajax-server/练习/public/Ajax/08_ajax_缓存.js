var btn = document.querySelector('#btn')
console.log(btn);

btn.onclick = () => {
    var xhr = new XMLHttpRequest();
    // console.log(xhr); //Math.random() 返回一个随机 1到0 的值
    //低版本的ie浏览器需要每次请求不一样  不然不会发送请求至服务器，而是读取本地缓存
    xhr.open('get', 'http://127.0.0.1:3000/ajax/cache_08?+t=' + Math.random())

    xhr.onreadystatechange = function() {
        if (xhr.readyState === 4 && xhr.status === 200) {
            alert('响应成功!')
            alert(xhr.responseText) //响应内容
            console.log(xhr.responseText);
            // 这个只会返回 ok  错误 statusText
        };
        // console.log(xhr.readyS  tate)
    };
    xhr.send();
};

//解决方法 在每次请求的地址不同 由于请求地址不可变 则 ->
//在请求地址后面加请求参数，保证每一次请求中的请求参数的值不同