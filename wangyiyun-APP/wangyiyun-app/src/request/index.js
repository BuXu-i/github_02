//配置 axios 的默认请求
import axios from "axios";
let servece = axios.create({
    baseURL: "http://localhost:3000",
    timeout: 3000, //请求时间限制
    // headers: { "X-Custom-Header": "foobar" },
    //该项目中全部是get请求
});
export default servece;
