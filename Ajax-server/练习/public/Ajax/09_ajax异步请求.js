// 1.创建Ajax对象
var xhr = new XMLHttpRequest()

// 2.发送怎样的请求
xhr.open('get', 'http://127.0.0.1:3000/ajax')

// 发送请求
xhr.send()

// 获取服务器响应的数据
xhr.onload = function() {
    console.log('2')
    console.log(xhr.responseText)

}
console.log('1')