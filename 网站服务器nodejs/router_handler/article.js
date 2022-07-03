const { query } = require('express')
const express = require('express')
const router = express.Router()
const db = require('../db/index')

// //解析表单数据
// const multer = require('multer')
const path = require('path')
    // const uplaod = multer({ dest: path.join(__dirname, '../uploads') })

const SQLadd_article = 'insert into ev_articles set ?'
    // insert into ev_article_cate set ?
router.add_article = (req, res) => {
    console.log(req.body) //文本类型的数据
    console.log('分割线');
    console.log(req.file) //文件类型
    const articleInfo = {
        // 标题、内容、发布状态、所属分类的Id
        ...req.body,
        // 文章封面的存放路径
        cover_img: path.join('/uploads', req.file.filename),
        // 文章的发布时间
        pub_date: new Date(),
        // 文章作者的Id
        author_id: req.user.id,
    }
    db.query(SQLadd_article, articleInfo, (err, results) => {
        if (err) return res.cc(err)
        if (results.affectedRows !== 1) return res.cc('发布新文章失败！')
        res.cc('发布文章成功！', 0)
    })
}
module.exports = router