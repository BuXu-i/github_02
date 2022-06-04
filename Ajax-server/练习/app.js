const express = require('express')
const app = express()

//跨域访问
const cors = require('cors')
app.use(cors())

//解析表单数据  location-地方  parser解析器   extended扩展的
//挂载到  body上
const bodyParser = require('body-parser')
app.use(bodyParser.urlencoded({
    extended: false
}));
// 处理json传入解析
app.use(bodyParser.json());
app.use((req, res, next) => {
    res.cc = function(err, status = 1) {
        res.send({
            status,
            messge: err instanceof Error ? err.messge : err,
        })
    }
    next()
});

// 挂载静态资源
const path = require('path');
app.use('/index', express.static(path.join(__dirname, 'public'))) //访问静态资源服务


const expressJWT = require('express-jwt');
const config = require('./config');

//会解析token字符串 挂在到user上          , { path: [/^\/ajax\//] }, { path: [/^\/index\//] }
app.use('/op', expressJWT({ secret: config.jwrSerekey }).unless({ path: config.path }))

// 登录和注册中间件
const user = require('./router/user');
app.use('/api', user);


/******************************************* */
//Ajax请求
const ajax = require('./router/ajax');
app.use('/ajax', ajax);


/*************************************** */

const joi = require('joi'); // 全局错误中间件
app.use((err, req, res, next) => {
    //数据验证失败
    if (err instanceof joi.ValidationError) {
        console.log('A');
        return res.cc(err)
    };
    //token验证失败
    if (err.name === 'UnauthorizedError') {
        console.log(err);
        return res.cc(err)

    }
    console.log({ 1: req.body, 2: req.url });
    console.log(err);
    //未知错误
    res.cc(err)
});

app.listen(3000, (req, rse) => {
    console.log('http://127.0.0.1:3000/index');
});