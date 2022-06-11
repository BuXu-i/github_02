var xhr = new XMLHttpRequest()


console.log(xhr.readyState)
xhr.open('get', 'http://localhost:3000/ajax/readyState')

//监听状态码的改变  change-改变
xhr.onreadystatechange = () => {
    // 2.请求已经发送
    //3.已经接受到了服务器端的部分数据
    //4.服务器的响应数据已经接受完成
    console.log(xhr.readyState)
    if (xhr.readyState === 4) {
        // 回答
        console.log(xhr.responseText)
    }
}

// 发送请求必须得在事件之后
xhr.send()