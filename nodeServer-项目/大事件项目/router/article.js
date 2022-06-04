const router_handler = require('../router_handler/article')
const express = require('express')
const router = express.Router()
const expresssjoi = require('@escook/express-joi')
const { add_article } = require('../schema/article')


const multer = require('multer')
const path = require('path')

const uplaod = multer({ dest: path.join(__dirname, '../uploads') })

// 发布新文章的路由
// upload.single() 是一个局部生效的中间件，用来解析 FormData 格式的表单数据
// 将文件类型的数据，解析并挂载到 req.file 属性中
// 将文本类型的数据，解析并挂载到 req.body 属性中, expresssjoi(add_article)
// 导入验证数据的中间件
const expressJoi = require('@escook/express-joi')
    //导入需要验证的对象
const { add_article_schema } = require('../schema/article')
    //发布文章的路由
router.post('/add_article', uplaod.single('cover_img'), expressJoi(add_article_schema), router_handler.add_article)
    //简约简约 简约  简约简约 简约 简约见鳄鱼  好きだ
module.exports = router