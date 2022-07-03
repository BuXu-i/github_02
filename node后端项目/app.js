const express = require('express')
const app = express()

//支持跨域访问
const cors = require('cors')
app.use(cors())



//解析表单数据

// app.use(express.urlencoded({ extended: false }))

const bodyParser = require('body-parser')
app.use(bodyParser.urlencoded({
    extended: false
}))

//app.use(bodyParser.urlencoded({ extended: true }))
//开始时会调用此全局中间件，里面是函数不会执行 在后续代码中可以调用该函数来执行改代码
app.use((req, res, next) => {
    // status = 0 为成功； status = 1 为失败； 默认将 status 的值设置为 1，方便处理失败的情况
    res.cc = function(err, status = 1) {
        console.log(err + " " + status);
        res.send({
            // 状态
            status,
            // 状态描述，判断 err 是 错误对象 还是 字符串
            message: err instanceof Error ? err.message : err,
        })
    }
    next()
})
const expressJWT = require('express-jwt')
const config = require('./config')
app.use(expressJWT({ secret: config.jwrSecrekey }).unless({ path: config.path })) //会解析token字符串 挂在到user上

//导入路由模块
const userRouter = require('./router/user')
app.use('/api', userRouter) //导入写好的路由模块

//访问头部加  Authorization 
const userinfo = require('./router/userinfo')
app.use('/my', userinfo)

//文章管理类 路由
const artcate = require('./router/artcate')
app.use('/my/artcate', artcate)

//解析fromdate表单路由

//文章内容管理 路由
const article = require('./router/article')
app.use('/my/article', article)

//const joi = require('@hapi/joi') 
const joi = require('joi')

//全局的错误中间件  在路由之后
app.use((err, req, res, next) => {
    //数据验证失败
    if (err instanceof joi.ValidationError) {
        console.log('joi');
        return res.cc(err)
    }
    //token验证失败
    if (err.name === 'UnauthorizedError') {
        return res.cc(err)
    }
    console.log({ 1: req.params.id, 2: req.url });
    //未知错误
    res.cc(err)
})
app.listen(3007, (req, res) => {
    console.log('启动服务器:http://127.0.0.1:3007');
})