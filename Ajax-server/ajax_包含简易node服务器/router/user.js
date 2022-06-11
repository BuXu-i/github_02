const express = require('express')
const router = express.Router()
const user_handler = require('../router_handler/user')

// 导入验证规则
const expressJoi = require('@escook/express-joi')
const { reguser_schema, login_schema } = require('../schema/user')

// 注册
router.post('/reguser', expressJoi(reguser_schema), user_handler.reguser)

// 登录
router.post('/login', expressJoi(login_schema), user_handler.login)


module.exports = router