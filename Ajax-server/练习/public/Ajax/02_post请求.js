var xhr = new XMLHttpRequest()


console.log(xhr.readyState)
xhr.open('post', 'http://localhost:3000/ajax/post_02');
//请求头  application--应用  Content--容纳
xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
//表单
xhr.send('name=zhangsan&age=20');
xhr.onload = (e) => {
    var readyState = xhr.responseText;
    console.log(readyState);
    readyState = JSON.parse(readyState);
    console.log(readyState);
}