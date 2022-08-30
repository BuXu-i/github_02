const { defineConfig } = require("@vue/cli-service");
//vant 配置插件
const { VantResolver } = require("unplugin-vue-components/resolvers");
const ComponentsPlugin = require("unplugin-vue-components/webpack");
module.exports = defineConfig({
    transpileDependencies: true,
    // configureWebpack是vant需要导入的文件
    configureWebpack: {
        plugins: [
            ComponentsPlugin({
                resolvers: [VantResolver()],
            }),
        ],
    },
    devServer: {
        // 中转服务器
        proxy: {
            //通过代理实现跨域
            // 所有的/path都会替换成 http://localhost:3000
            "/path": {
                target: "https://music.163.com", //表示我要替换的服务端地址
                changeOrigin: true, //开启代理，允许跨域
                rewrite: (path) => path.replace(/^\/path$/, ""), //设置重写路径
            },
        },
    },
});
