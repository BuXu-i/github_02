//将函数 以属性的方式向外挂载 
//exports有多个属性，这样写是不会覆盖先前写的向外暴露的函数
const db = require('../db/index') //导入数据库模块
const sqly = `select * from ev_users where username=?` //查询语句
const sqlinset = 'insert into ev_users set ?' //插入语句
const sqlfied = 'select * from ev_users where username=?' //查询语句
const bcrypt = require('bcryptjs') //引入加密 密码包
const config = require('../config') //导入token加密字符串
const jwt = require('jsonwebtoken') //加密token字符串


exports.regUrser = (req, res) => {
    const userinfo = req.body
    db.query(sqly, [userinfo.username], function(err, results) {
        if (err) {
            return res.cc(err)
        }
        // 验证用户名是否被使用
        if (results.length > 0) {
            return res.cc('同名：' + results.length)
        }
        //存储用户信息
        //参数列表(明文密码,随机盐的长度)  //加密
        userinfo.password = bcrypt.hashSync(userinfo.password, 10)
        db.query(sqlinset, { username: userinfo.username, password: userinfo.password }, function(err, results) {
                if (err) {
                    return res.cc('错误，请稍后再试')
                }
                return res.cc('注册成功', 0)
            })
            //res.send('注册成功', 0)
    })

}

//登录
exports.login = (req, res) => {
    console.log('进入');
    const userinfo = req.body
    db.query(sqlfied, [userinfo.username], function(err, results) {
        console.log('查询:' + results);
        if (err) {
            return res.cc('查询失败!')
        }
        if (results.length === 1) {
            //验证                    对比的body密码       数据库中查询密码
            if (bcrypt.compareSync(userinfo.password, results[0].password)) {
                const user = {...results[0], password: '', user_pic: '' } //生成token字符串返回
                    //  console.log(user);   加密字符串    有效时间  expires过期
                const tokenStr = jwt.sign(user, config.jwrSecrekey, { expiresIn: config.expresin })
                    // console.log(tokenStr);
                return res.send({ status: 0, message: '登陆成功', token: 'Bearer' + tokenStr })
                    // return res.cc(0)
            }
            return res.cc('密码错误!')
        }
        res.cc('数据库错误!')
    })
}