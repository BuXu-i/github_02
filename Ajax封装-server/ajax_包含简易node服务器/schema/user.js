const joi = require('@hapi/joi')

// * string() 值必须是字符串
// ★
// alphanum()值只能是包含a-zA-Z0-9 的字符串
// ★min(length)最小长度
// ★max(length) 最大长度
// ★required() 值是必填项，不能为undefined
// ★pattern( 正则表达式)值必须符合正则表达式的规则
// ★/

const nickname = joi.string().required()
const username = joi.string().alphanum().min(1).max(10)
const email = joi.string().email().required()
const password = joi.string().pattern(/^[\S]{1,12}$/).alphanum().required()
exports.reguser_schema = {
    body: {
        nickname,
        password,
        username,
        email
    }
}
exports.login_schema = {
    body: {
        password,
        username,
    }
}