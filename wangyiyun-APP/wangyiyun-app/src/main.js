import { createApp } from "vue";
import App from "./App.vue";
import router from "./router";
import store from "./store";
//引入vant组件库的js文件
import vant from "../src/plugins/index";
const app = createApp(App);
// vant();
app.use(vant); //UI
app.use(store); //仓库 vuex 全局
app.use(router); //路由
app.mount("#app"); //挂载
