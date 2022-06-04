const { result } = require('@hapi/joi/lib/base')
const express = require('express')
const res = require('express/lib/response')

const db = require('../db/index')

//获取所有文章分类
const SQLarticleCates = 'select * from ev_article_cate where is_delete=0 order by id asc'
exports.getArticleCates = (req, rse) => {
    db.query(SQLarticleCates, (err, results) => {
        if (err) return rse.cc(err)
        rse.cc(results, 0)
    })
}

//文章分类
const SQLarticle = 'select * from ev_article_cate where name=? or alias=?' //查询语句
const SQLappLarticle = `insert into ev_article_cate set ?`

//`insert into ev_article_cate set ?`
exports.addArticleCates = (req, rse) => {
    db.query(SQLarticle, [req.body.name, req.body.alias], (err, results) => {
        if (err) return rse.cc(err)
        if (results.length === 1 && results[0].name === req.body.name) return rse.cc('name 被占用!')
        if (results.length === 1 && results[0].alias === req.body.alias) return rse.cc('alias 被占用!')
        db.query(SQLappLarticle, [req.body], (err, results) => {
            //console.log(results);
            if (err) return rse.cc(err)
            if (results.affectedRows !== 1) return rse.cc('数据库错误!插入失败!')
            rse.cc('上传文章成功!', 0)
        })
    })
}

//删除文章  需要删除文章的id
const SQLdelete_article = 'update ev_article_cate set is_delete=1 where id=?'
exports.delete_article = (req, res) => {
    db.query(SQLdelete_article, req.params.id, (err, results) => {
        if (err) return res.cc(err)
        if (results.affectedRows === 1) return res.cc('删除成功!', 0)
        return res.cc('删除失败!数据库错误!')
    })
}

//根据id获取相关的分类    文章分类
const SQLfind_article = 'select * from ev_article_cate where id=?'
exports.all_find_article = (req, res) => {
    console.log('出来');
    db.query(SQLfind_article, req.params.id, (err, results) => {
        if (err) return res.cc(err)
        if (results.length === 0) return res.cc('为查询到相关文章!')
        res.cc(results, 0)
    })
}

//根据id更新分类
const SQLupdateremoval = 'select * from ev_article_cate where id<>? and (name=? or alias=?)' //查询新name 和alias 是否有重名
const SQLupdatearticle = 'update ev_article_cate set ? where id=?' //查询文章是否存在
exports.update_article = (req, res) => {
    db.query(SQLfind_article, req.body.id, (err, results) => {
        if (err) return res.cc(err)
        if (results.length === 0) {
            return res.cc('未添加该分类!请直接添加')
                //还要查询是否有重名的 问题
        }
        db.query(SQLupdateremoval, [req.body.id, req.body.name, req.body.alias], (err, results) => {
            if (err) return res.cc(err)
            console.log(results.length);
            if (results.length === 2) return res.cc('name和alias有重名!')
            if (results.length === 1 && results[0].name === req.body.name) return res.cc('name 重名!')
            if (results.length === 1 && results[0].alias === req.body.alias) return res.cc('alias重名!')
            db.query(SQLupdatearticle, [req.body, req.body.id, ], (err, results) => {
                if (err) return res.cc(err)
                if (results.affectedRows !== 1) return res.cc('数据库影响函数不唯一!')
                return res.cc('更新该分类成功!', 0)
            })
        })
    })
}