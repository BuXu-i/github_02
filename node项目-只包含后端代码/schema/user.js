const joi = require('@hapi/joi')
    //const joi = require('joi')

// /**
// * string() 值必须是字符串
// ★
// alphanum()值只能是包含a-zA-Z0-9 的字符串
// ★min(length)最小长度
// ★max(length) 最大长度
// ★required() 值是必填项，不能为undefined
// ★pattern( 正则表达式)值必须符合正则表达式的规则
// ★/


// const joi = require('joi') 
// router.post('/reguser', expressJoi(reg_login_schema), userHandler.regUser)
//字符串                最小  最大
const username = joi.string().alphanum().min(1).max(10)
    //字符串      正则表达式              不允许重复提交
const password = joi.string().pattern(/^[\S]{1,12}$/).alphanum().required()

exports.reg_login_schema = {
    body: {
        username,
        password
    },
}

// 定义 id, nickname, emial 的验证规则
const id = joi.number().integer().min(1).required()
const nickname = joi.string().required()
const email = joi.string().email().required()
exports.reg_update_scheme = {
    body: {
        id: id,
        nickname: nickname,
        email: email
    },
}

exports.reg_password_scheme = {
    body: {
        password,
        uppassword: password
    }
}

//头像的规则
const avatar = joi.string().required()
exports.update_avatar_schema = {
    body: {
        avatar
    }
}