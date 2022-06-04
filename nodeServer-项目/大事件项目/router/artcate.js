//文章分类路由
const express = require('express')
const router = express.Router()
const artcate_handler = require('../router_handler/artcate')

const expressJoi = require('@escook/express-joi')

const { add_cate_scheme_scheme, delete_article_scheme, all_find_article_schema, update_article_schema } = require('../schema/artcate')
    //                    
    //获取所有的文章分类
router.get('/cates', artcate_handler.getArticleCates)

//上传创建新的文章分类
router.post('/addcates', expressJoi(add_cate_scheme_scheme), artcate_handler.addArticleCates)

//文章分类删除
router.get('/delete/:id', expressJoi(delete_article_scheme), artcate_handler.delete_article)

//根据id 查询文章 分类                       all_find_article_schema
router.get('/allfind/:id', expressJoi(all_find_article_schema), artcate_handler.all_find_article)

//http://127.0.0.1:3070/artcate/delete/:3
router.post('/updatecate', expressJoi(update_article_schema), artcate_handler.update_article)

module.exports = router