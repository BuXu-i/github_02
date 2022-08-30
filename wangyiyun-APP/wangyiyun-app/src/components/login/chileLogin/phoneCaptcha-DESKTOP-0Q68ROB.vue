<template>
    <!-- 电话验证码 -->
    <span>电话:<input v-model="phone" type="text" style="display: inline;" @keydown.enter="login()"></span>
    <span>验证码:<input v-model="captcha" style="display: inline;" @keydown.enter="login()">
    </span>
    <br>
    <div>
        <button @click="loginCaptcha()">获取验证码</button>
        <!-- 计时器 -->
        <span v-if="timeCap">{{timeCap}}</span>
    </div>
    <button @click="login()">登录</button>
</template>

<script>
import { mapState, mapActions } from "vuex";

export default {
    data() {
        return {
            timeCap: false, //倒计时
            time: false, //定时器
            phone: "", //电话
            captcha: "", //验证码
            regexp: new RegExp(/^[1]+[3-8]+\d{9}$/),
        };
    },
    emits: ["infologin"],
    computed: {
        ...mapState[("modelueInfouser", "id")], //user子仓库中中的id属性 第一个参数是路径
    },
    methods: {
        ...mapActions([
            "Vxloginpphone_captcha", //发送验证码  传入电话
            "Vxloginphonecaptcha", //验证验证码  传入 电话和验证码
            "storeOutLongin", //退出登录
        ]),
        loginCaptcha() {
            //发送验证码  传入电话
            console.log(this.phone);
            // var regexp = /^[3-8]+\d{9}$/;
            console.log(this.regexp);
            console.log(this.regexp.test(this.phone));
            if (
                this.phone == "" ||
                !this.regexp.test(this.phone) ||
                this.timeCap > 0
            ) {
                console.log("检查输入电话");
            } else {
                this.Vxloginpphone_captcha(this.phone);
                this.timeCap = 60;
                let _this = this;
                clearInterval(this.time);
                this.time = setInterval(() => {
                    if (--_this.timeCap == 0) {
                        //计时结束
                        clearInterval(_this.time);
                    }
                }, 1000);
            }
        },
        async login() {
            //验证验证码  传入 电话和验证码
            console.log({
                phone: this.phone,
                captcha: this.captcha,
            });
            if (
                this.phone == "" ||
                this.captcha == "" ||
                !this.regexp.test(this.phone)
            ) {
                console.log("检查输入");
            } else {
                let qr = await this.Vxloginphonecaptcha({
                    phone: this.phone,
                    captcha: this.captcha,
                });
                console.log(qr);
                this.id;
                console.log("子组件查询登录状态是否完成 正在调用查询函数1");
                this.$emit("infologin");
                // await this.storeOutLongin(); //退出登录
                console.log("子组件查询登录状态是否完成 正在调用查询函数2");
                this.$emit("infologin");
            }
        },
    },
};
</script>

<style lang="less" scoped>
.captcha {
    padding: 0 2px;
    border: 1px solid #000;
    border-radius: 0.3rem;
    background-color: rgb(152, 157, 160);
}
span {
    // width: 2rem;
    margin-top: 0.2rem;
}
</style>