const express = require('express')
const router = express()
const router_handler = require('../router_handler/ajax')

// get请求
router.get('', router_handler.ajax);

// post 请求
router.post('', router_handler.location);

//post_02
router.post('/post_02', router_handler.post_02);
//post_03 josn 请求
router.post('/03_post_josn', router_handler.post_json_03);

//./Ajax/06_ajax_readystate.js 的运行
router.get('/readyState', router_handler.readstate);

//07_ajax错误请求的处理
router.get('/errer_07', router_handler.errer_07);

//低版本浏览器缓存问题的函数
router.get('/cache_08', router_handler.cache_08);


module.exports = router