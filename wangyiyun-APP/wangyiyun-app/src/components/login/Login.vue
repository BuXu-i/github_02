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
                    _this.settoken(_this.Bool.cookie); //只会返回一个cookie
                    ////////查询登录状态
                    console.log("查询登录状态");
                    // 上传个人信息到store中   // _this.infologin(); //查询后会返回个人信息
                    _this.pushUserinfo(_this.infologin()); //会修改登录状态
                    //退回本应该回到的路由
                    _this.$router.go(-1);
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
            console.log(
                "我是登录状态 打印查询状态 需要查看是否能正确得到 用户信息 包括id"
            );
            console.log(qr);
            return { qr: qr.data.data.account };
        },
        ...mapMutations(["updataLoginShow"]),
        ...mapActions("modelueLogin", [
            //"modelueLogin", 加上路径会出错  未找出原因
            "Vxgetloginqr_1", //生成二维码
            "Vxgetloginqr_3", //查询登录状态
            "Vxgetanonimous", //游客登陆 无名氏登录
            "storeGetLonginStatus", // //获取登录状态
        ]), //login
        //       路径    设置token   删除token
        ...mapMutations("modelueToken", ["settoken", "removeToken"]), //utils
        //用户数据store保存  路径             用户信息   这里是上传用户信息
        ...mapMutations("modelueInfouser", ["pushUserinfo"]), //user
    },
    async mounted() {
        console.log("调用接口1");
        this.qr = await this.Vxgetloginqr_1();
        console.log("接受到？");
        console.log(typeof this.qr);
        if (typeof this.qr == "undefined") {
            console.log("为空 请刷新页面");
            return;
        }
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