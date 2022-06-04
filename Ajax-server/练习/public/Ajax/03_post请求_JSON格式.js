var xhr = new XMLHttpRequest()

// 未测试过  应该是没有问题的 
console.log(xhr.readyState)
xhr.open('post', 'http://localhost:3000/ajax/post_02');
//请求头  application--应用  Content--容纳 
xhr.setRequestHeader('Content-Type', 'application/json');
//表单
var jsonApplication = JSON.stringify({ name: 'zhansan', age: 20 });
console.log(jsonApplication);
xhr.send(jsonApplication);
xhr.onload = (e) => {
    var readyState = xhr.responseText;
    console.log(readyState);
    readyState = JSON.parse(readyState);
    console.log(readyState);
}