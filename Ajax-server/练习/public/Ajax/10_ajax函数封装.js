function ajax(obj) {
    console.log('被调用 ')
    var defaults = {
        type: 'get',
        url: '',
        data: {},
        header: { 'Content-Type': 'application/x-www-form-urlencode' },
        success: function(data, xhr) {
            // console.log(data);
            // console.log(xhr);
            return data;
        },
        errer: function(data, xhr) {
            // console.log(data);
            // console.log(xhr);
            return data;
        }
    };
    //assign- [əˈsaɪn]-分配 defaults-[dɪˈfɔːlts]-默认设置
    // Object.assign 会覆盖相同的属性 obj 覆盖 defaults
    Object.assign(defaults, obj);
    var xhr = new XMLHttpRequest();
    var panms = '';
    //拼接传参
    for (key in defaults.data) {
        panms += key + '=' + defaults.data[key] + '&';
    }
    panms[panms.length - 1] = null;

    // panms.substring(0, panms.length-1);
    //判断请求类型
    if (defaults.type === 'get') {
        //重新封装 url地址
        defaults.url = defaults.url + '?' + panms;
    }
    xhr.open(defaults.type, defaults.url)
    if (defaults.type == 'post') {
        var ContentType = defaults.header['Content-Type'];
        //设置请求头(POST)
        console.log('**********')
        console.log(defaults.header['Content-Type']);
        xhr.setRequestHeader('Content-Type', defaults.header['Content-Type']);
        //判断post请求发送数据类型
        if (ContentType == 'application/json') {
            //转化为json数据字符串
            xhr.send(JSON.stringify(defaults.data));
        } else {
            // pams是一个准备好的字符串
            xhr.send(panms);
        }
    } else { //get 发送请求
        //设置请求体
        xhr.send();
    }
    //监听xhr对象下面的onload事件
    //当xhr对象接受完响应数据后触发
    xhr.onload = function() {
        //获取响应头的类型
        const contentType = xhr.getResponseHeader('Content-Type');
        //获取响应的数据
        var responseText = xhr.responseText;
        console.log('???????');
        console.log(xhr.responseText)
        console.log(typeof xhr.responseText)
        if (contentType.includes('application/json')) {
            console.log('????函数封装中解析porse--json数据???');
            responseText = JSON.parse(responseText);
            console.log(responseText);
            // console.log(typeof responseText['massge']);
            // console.log(responseText['massge'])
            // console.log(responseText['massge'].name)
        }
        //查看返回结果 码
        // console, log(xhr.status);
        if (xhr.status == 200 && xhr.readyState === 4) {
            console.log('成功  ' + xhr.readyState);
            //处理成功的函数
            // console.log(defaults.success(responseText, xhr));
            // console.log({ massge: 0, ajax: defaults.success(responseText, xhr) })
            return { massge: 0, ajax: defaults.success(responseText, xhr) };
        } else {
            //处理失败的函数
            console.log('失败')
            return { massge: 1, ajax: defaults.errer(responseText, xhr) };
        }
    }
}
// //调用ajax函数
// ajax({
//     //请求方式
//     type: 'post',
//     //请求地址 
//     url: 'http://127.0.0.1:3000/ajax/03_post_josn',
//     data: {
//         name: 'zhangsan',
//         age: 20
//     },
//     header: {
//         'Content-Type': 'application/json'
//     },
//     success: function(data, xhr) { //成功后调用
//         console.log('这里是success函数: ')
//         console.log(data);
//         console.log('A');
//         console.log(xhr);
//     },
//     errer: function(data, xhr) { //错误调用
//         console.log('这里是errer函数: ')
//         console.log(data);
//         console.log('B');
//         console.log(xhr);
//     },
//     // 考虑请求的各种方法  来设置不同的处理方式
//     //传入数据 使用对象数据来传参  ，便于后续处理成字符串等操作
// })