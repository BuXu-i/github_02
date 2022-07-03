const express = require('express')
const router = express()

router.ajax = (req, res) => {
    console.log('处理请求中... + get请求')
    res.cc('返回请求+get请求', 0)
};
router.location = (req, res) => {
    console.log('处理请求中...')
    res.cc(req.user, 0)
    console.log('处理请求中... + post请求')
};

//post_02
router.post_02 = (req, res) => {
    console.log('处理请求中... + 06_readstate + get请求')
    console.log(req.body);
    res.send({ massge: req.body, errer: 0 })
};
//post_json_03
router.post_json_03 = (req, res) => {
    console.log('处理请求中... + 06_readstate + get请求')
    console.log(req.body);
    res.send({ massge: req.body, errer: 0 })
}
router.readstate = (req, res) => {
    console.log('处理请求中... + 06_readstate + get请求')
    res.cc('返回请求+get请求', 0)
};

router.errer_07 = (req, res) => {
    console.log('处理请求中... + errer_07+ get请求')
    res.cc('返回请求+get请求', 0)
};

//低版本ie浏览器 的缓存问题
var fs = require('fs') //读取文本文件
var path = require('path')
router.cache_08 = (req, res) => {
    console.log('处理中')
    var spath = path.join(__dirname, '../public/text.txt');
    console.log(spath)
    fs.readFile(spath, 'utf-8', (err, result) => {
        if (err) return res.cc(err)
        console.log(result);
        return res.send(result)
    })
}
module.exports = router