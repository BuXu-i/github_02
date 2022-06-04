const joi = require('@hapi/joi')
    //上传文章规则
const name = joi.string().required()
const alias = joi.string().alphanum().required()
exports.add_cate_scheme_scheme = {
    body: {
        name,
        alias
    }
}

//删除文章规则
const id = joi.number().integer().min(1).required()
exports.delete_article_scheme = {
    params: {
        id
    }
}

//查询文章规则
exports.all_find_article_schema = {
    params: {
        id
    }
}

exports.update_article_schema = {
    body: {
        id,
        name,
        alias
    }
}