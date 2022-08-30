<template >
    <van-popup v-model:show="isloginShow" position="top" :style="{ height: '100%' }">
        <svg class="icon liebiao" aria-hidden="true" @click="$router.push('/');updataLoginShow()">
            <use xlink:href="#icon-houtui"></use>
        </svg>
        <!-- 登录弹窗 -->
        <div v-if="data==1" class="box">
            <img :src="qr.qrurl" alt="">
            <div v-if="Bool.code == 800">
                <span>{{Bool.message}}</span>
                <svg class="icon" aria-hidden="true" @click="f5">
                    <use xlink:href=" #icon-shuaxin"></use>
                </svg>
            </div>
            <span>扫码登录</span>
        </div>
        <div v-if="data==2" class="box">
            <phonePassword @infologin='infologin()' />
        </div>
        <div v-if="data==3" class="box">
            <phoneCaptcha @infologin='infologin()' />
        </div>
        <div class="bottom">
            <span @click="data=1;updata()">
                <p>&nbsp;扫码登录&nbsp;</p>
            </span>&nbsp;&nbsp;&nbsp;
            <span @click="data=2;updata()">
                <p> &nbsp;密码登录&nbsp; </p>
            </span>&nbsp;&nbsp;&nbsp;
            <span @click="data=3;updata()">
                <p>&nbsp;验证码登录&nbsp;</p>
            </span>&nbsp;&nbsp;&nbsp;
        </div>
    </van-popup>
</template>

<script>
import { mapMutations, mapState, mapActions } from "vuex";
//子组件  电话密码  电话验证码
import phoneCaptcha from "./chileLogin/phoneCaptcha.vue";
import phonePassword from "./chileLogin/phonePassword.vue";

export default {
    data() {
        return {
            data: 1,
            qr: {},
            timer: "",
            Bool: {},
        };
    },
    components: {
        phoneCaptcha,
        phonePassword,
    },
    computed: {
        ...mapState(["isloginShow"]),
        //token路径 获取token
        ...mapState("modelueToken", ["token"]),
    },
    methods: {
        updata() {
            //当data 改变时触发 删除 二维码状态查询的定时器
            console.log("updata!!!");
            //侦听data的状态 控制是否发送二维码的请求
            if (this.data !== 1) {
                clearInterval(this.timer);
            } else {
                clearInterval(this.timer);
                this.Vxgetloginqr();
            }
        },
        Vxgetloginqr: function () {
            var _this = this;
            console.log(_this.qr.key);
            this.timer = setInterval(async function () {
                _this.Bool = await _this.Vxgetloginqr_3(_this.qr.key);
                if (_this.Bool.code == 800) {
                    //二维码过期
                    console.log("过期");
                    clearInterval(_this.timer);
                } else if (_this.Bool.code == 801) {
                    //等待扫码
                    console.log(_this.Bool.message);
                } else if (_this.Bool.code == 802) {
                    //待确认
                    console.log(_this.data.massage);
                } else if (_this.Bool.code == 803) {
                    //授权成功 返回cookie
                    console.log("授权成功 返回cookie");
                    console.log(_this.Bool);
                    console.log("我是分界线");
                    console.log(_this.Bool.message);
                    /////////  还需要存储  id 返回的个人信息最好都存储一下吧
                    document.cookie = this.Bool.cookie; //存储cookie
                    ////////查询登录状态
                    console.log("查询登录状态");
                    _this.infologin();
                    clearInterval(_this.timer);
                } else if ($store.state.isloginShow) {
                    clearInterval(_this.timer);
                } else {
                    console.log("未知");
                }
            }, 1000);
        },
        f5: async function () {
            //重新发送获取二维码
            clearInterval(this.timer);
            this.qr = {};
            this.Bool.message = "刷新中！";
            this.Bool.code = "1";
            this.qr = await this.Vxgetloginqr_1();
            this.Vxgetloginqr();
        },
        //查询登录状态
        async infologin() {
            let qr = await this.storeGetLonginStatus(); //获取登录状态
            console.log("我是登录状态 打印查询状态");
            console.log(qr);
        },
        ...mapMutations(["updataLoginShow"]),
        ...mapActions([
            "Vxgetloginqr_1", //生成二维码
            "Vxgetloginqr_3", //查询登录状态
            "Vxgetanonimous", //游客登陆 无名氏登录
            "storeGetLonginStatus", // //获取登录状态
        ]),
        //       路径    设置token   删除token
        ...mapMutations("modelueToken", ["settoken", "removeToken"]),
    },
    async mounted() {
        console.log("调用接口1");
        this.qr = await this.Vxgetloginqr_1();
        console.log("接受到？");
        console.log(this.qr);
        this.Vxgetloginqr();
    },
    beforeUnmount() {
        //销毁实例时候
        clearInterval(this.timer);
    },
    //查询登录状态
};
</script>

<style lang="less" scoped>
.liebiao {
    margin: 0.2rem 0.2rem;
}
.box {
    display: flex;
    flex-direction: column;
    align-items: center;
    width: 100%;
    height: 4rem;
    // height: 50%;
    margin-top: 50%;
    span {
        // width: 2rem;
        margin-top: 0.2rem;
    }
    img {
        width: 40%;
        height: 70%;
    }
}
.bottom {
    display: flex;
    justify-content: center;
    margin-top: 0.4rem;
    span {
        // width: 1.5rem;
        // margin: 0 auto;
        // align-content: center;
        border-radius: 0.3rem;
        background-color: rgb(152, 157, 160);
    }
}
</style>