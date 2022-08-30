<template >
    <!-- 电话密码 -->
    <span>电话:<input v-model="phone" type="text" style="display: inline;" @keydown.enter="login()"></span>
    <span>密码:<input v-model="password" type="password" style="display: inline;" @keydown.enter="login()"></span><br>
    <button @click="login()">登录</button>
</template>

<script>
import { mapActions, mapMutations } from "vuex";
import md5 from "js-md5"; //md5 加密
export default {
    data() {
        return {
            phone: "",
            password: "",
            regexp: new RegExp(/^[1]+[3-8]+\d{9}$/),
        };
    },
    emits: ["infologin"],
    methods: {
        ...mapActions([
            "Vxgetloginphone", //电话登录 传入电话和密码
        ]),
        async login() {
            console.log(
                this.phone +
                    " " +
                    this.password +
                    " " +
                    this.regexp.test(this.phone)
            );
            if (
                this.phone == "" ||
                this.password == "" ||
                !this.regexp.test(this.phone)
            ) {
                console.log("检查输入");
            } else {
                // 判断电话格式;
                let qr = await this.Vxgetloginphone({
                    phone: this.phone,
                    password: md5(this.password),
                }); //电话登录 传入电话和密码
                console.log("请求完成");
                console.log(qr);
                console.log("子组件查询登录状态是否完成 正在调用查询函数");
                this.$emit("infologin");
            }
        },
    },
};
</script>

<style lang="less" scoped>
span {
    // width: 2rem;
    margin-top: 0.2rem;
}
</style>