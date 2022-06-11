const expressJoi = require('@escook/express-joi')
const express = require('express')
const router = express.Router()

//注册新用户
const userHeader = require('../router_handler/user')

//导入需要验证的规则对象
const { reg_login_schema } = require('../schema/user')

//回调函数是 访问导入模块的属性
// 注册新用户
// 3. 在注册新用户的路由中，声明局部中间件，对当前请求中携带的数据进行验证
// 3.1 数据验证通过后，会把这次请求流转给后面的路由处理函数
// 3.2 数据验证失败后，终止后续代码的执行，并抛出一个全局的 Error 错误，进入全局错误级别中间件中进行
//处理
//router.get('/getinfo', userHeader)
router.post('/reguser', expressJoi(reg_login_schema), userHeader.regUrser)

//登录时不需要jwt 验证的 
router.post('/login', expressJoi(reg_login_schema), userHeader.login)

module.exports = router