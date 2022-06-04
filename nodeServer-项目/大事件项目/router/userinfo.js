const express = require('express')
    //require('express')
const router = express.Router()
const userinfo_handler = require('../router_handler/userinfo')

//cc函数已经预执行了

const expressJoi = require('@escook/express-joi')

const { reg_update_scheme, reg_password_scheme, update_avatar_schema } = require('../schema/user')

//查询数据库
router.get('/userinfo', userinfo_handler.getUserInfo)

//更新数据库 更改用户数据                  reg_update_scheme
router.post('/userinfo', expressJoi(reg_update_scheme), userinfo_handler.updateUserInfo)

//更新密码
router.post('/userinfouppassword', expressJoi(reg_password_scheme), userinfo_handler.update_password_scheme)

//更新用户头像
router.post('/updateavatar', expressJoi(update_avatar_schema), userinfo_handler.updateavatar)

module.exports = router