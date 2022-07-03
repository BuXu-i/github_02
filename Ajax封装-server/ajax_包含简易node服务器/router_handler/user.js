const express = require('express')
const router = express.Router()
const db = require('../db/index')
const bcrypt = require('bcryptjs') //加密密码
const config = require('../config') //导入加密token字符串的一些方式
const jwt = require('jsonwebtoken') //加密token字符串

// //存储用户信息
// //参数列表(明文密码,随机盐的长度)  //加密
// // userinfo.password = bcrypt.hashSync(userinfo.password, 10)
// 验证
//验证                   对比的body密码       数据库中查询密码
//if (bcrypt.compareSync(userinfo.password, results[0].password)) {
//注册                                       db_ajax_user
const SQLreguser_login_find = `select * from db_ajax_user where email=? or username=? or nickname=?`
const SQLreguser_insert = `insert into db_ajax_user set ?`
router.reguser = (req, res) => {
    const userinfo = req.body
    userinfo.password = bcrypt.hashSync(userinfo.password, 10)
    db.query(SQLreguser_login_find, [userinfo.email, userinfo.username, userinfo.nickname], (err, results) => {
        if (err) return res.cc(err)
        if (results.length !== 0) return res.cc('已被使用!' + results.length)
        db.query(SQLreguser_insert, {...userinfo }, (err, results) => {
            if (err) res.cc(err)
            return res.cc('注册成功！', 0)
        })
    })
}

//登录 只需要查找账号即可
const SQLlogin = `select * from db_ajax_user where username=?`
router.login = (req, res) => {
    db.query(SQLlogin, req.body.username, (err, results) => {
        if (err) return res.cc(err)
        if (results.length !== 1) {
            return res.cc(results)
        }
        if (bcrypt.compareSync(req.body.password, results[0].password)) {
            const user = {...results[0], password: '', username: '' }
            const token = jwt.sign(user, config.jwrSerekey, { expiresIn: config.expresin })
            return res.send({ stutac: 0, massge: '登录成功', token: 'Beaber ' + token })
        }
    })
}



module.exports = router