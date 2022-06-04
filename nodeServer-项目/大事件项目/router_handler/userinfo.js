const express = require('express')
const res = require('express/lib/response')
const router = express.Router()
const db = require('../db/index')
const SQLgetUserInfo = `select id, username, nickname, email, user_pic from ev_users where id=?`
const SQLuserinfo = `update ev_users set ? where id=?`

router.getUserInfo = (req, rse) => {
        //user 是jwt解析后里面的字符串  里面有登录时从数据库中拿到的信息
        db.query(SQLgetUserInfo, req.user.id, (err, results) => {
            console.log("???get")
            if (err) {
                return rse.cc(err)
            }
            if (results.length !== 1) {
                return rse.cc('数据库数据错误')
            }
            return rse.send({
                status: 0,
                message: '正在返回结果',
                data: results[0]
            })
        })
    }
    //每次修改 
router.updateUserInfo = (req, rse) => {
    console.log("???")
    db.query(SQLuserinfo, [req.body, req.body.id], (err, results) => {
        if (err) {
            rse.cc(err)
        }
        if (results.affectedRows !== 1) {
            return rse.cc('数据库错误!')
        }
        console.log(req.body);
        console.log(results);
        console.log(results[0]);
        // fieldCount: 0,  现场计数：0，
        // affectedRows: 1,  受影响的行为：1，
        // insertId: 0,  插入ID:0，
        // serverStatus: 2,服务器状态：2，
        // warningCount: 0,警告计数：0，
        // message: '(Rows matched: 1  Changed: 0  Warnings: 0',消息：'（匹配的行数：1已更改：0警告：0'
        // protocol41: true,协议41：是的，
        // changedRows: 0,changedRows:0 变形金刚??
        rse.cc('修改成功!', 0)
    })
}

//修改密码  根据id查询用户是存在  2.判断新旧密码 3.bcrypt 加密 4.更新数据库
//查询ID是否存在 并匹配密码 
const SQLuserId_Password = `select * from ev_users where id=?`
    //`select * from ev_users where id=?`

//修改
const SQLupdatepassword = 'update ev_users set password=? where id=?'
    //`update ev_users set password=? where id=?`

const bcryptjs = require('bcryptjs') //导入加密模块

router.update_password_scheme = (req, rse) => {
    console.log('??? 最初进入' + req.user.id);
    db.query(SQLuserId_Password, req.user.id, (err, results) => {
        console.log("初次查询后" + err);
        if (err) {
            return rse.cc(err)
        }
        if (results.length !== 1) {
            return rse.cc('数据库错误!')
        }
        if (!bcryptjs.compareSync(req.body.password, results[0].password)) {
            return rse.cc('旧密码不符')
        } //需要修改的旧密码   uppassword  并加密旧密码
        req.body.uppassword = bcryptjs.hashSync(req.body.uppassword, 10)
        console.log('??? 加密密码后');
        db.query(SQLupdatepassword, [req.body.uppassword, req.user.id], (err, results) => {
            if (err) {
                return rse.cc('err')
            }
            if (results.affectedRows != 1) {
                return rse.cc('数据库错误!')
            }
            return rse.cc('修改成功!')
        })

    })
}

//更新头像  //敏感操作需要验证密码  更换头像就不用的了吧0.0
const SQLupdateavatar = 'update ev_users set user_pic=? where id=?'
router.updateavatar = (req, rse) => {
    console.log('avatar');
    db.query(SQLupdateavatar, [req.body.avatar, req.user.id], (err, results) => {
        if (err) {
            return rse.cc(err)
        }
        if (results.affectedRows === 1) {
            return rse.cc('更新成功!')
        }
        return rse.cc('更新失败,数据库错误!')
    })
}

module.exports = router