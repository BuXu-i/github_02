import {
    getloginqr_1,
    getloginqr_2,
    getloginqr_3,
    getanonimous,
    getloginphone, //电话密码
    getloginphone_captcha, //发送验证码
    getloginphonecaptcha, //验证验证码
    getLonginStatus, //查询登录状态
    outLongin, //退出登录
} from "@/request/api/login.js";
export const modelueLogin = {
    namespaced: true,
    state: {},
    actions: {
        //二维码登录  得到key   再调用接口 生成  二维码
        async Vxgetloginqr_1() {
            console.log("正在生成key值");
            let qr = await getloginqr_1();
            let key = qr.data.data.unikey;
            let qr2 = await getloginqr_2(key);
            console.log("二维码数据");
            console.log(qr);
            console.log(qr2);
            return { qrurl: qr2.data.data.qrimg, key }; //返回数据给调用调用者
        },
        //二维码登录  得到二维码
        async Vxgetloginqr_2(context, key) {
            console.log("得到二维码");
            let qr = await getloginqr_2(key);
            console.log(qr.data.data.qrurl);
            return qr.data.data.qrimg; //返回数据给调用调用者
        },

        //二维码登录  查询登录状态
        async Vxgetloginqr_3(context, key) {
            console.log("查询登录状态");
            let qr = await getloginqr_3(key);
            console.log(qr.data);
            return qr.data; //返回数据给调用调用者
        },
        //游客登陆 无名氏登录
        async Vxgetanonimous(context, key) {
            console.log("游客登陆");
            let qr = await getanonimous(key);
            console.log(qr);
            return qr; //返回数据给调用调用者
        },
        //电话登录 传入电话和密码
        async Vxgetloginphone(context, phonePassword) {
            console.log("仓库 电话密码登录中");
            console.log(phonePassword);
            let qr = await getloginphone(phonePassword);
            console.log(phonePassword);
            return qr; //返回数据给调用调用者
        },
        //发送验证码  传入电话
        async Vxloginpphone_captcha(context, phone) {
            let qr = await getloginphone_captcha(phone);
            console.log(qr);
            return qr;
        },
        //验证验证码  传入 电话和验证码
        async Vxloginphonecaptcha(context, phoneCaptcha) {
            let qr = await getloginphonecaptcha(phoneCaptcha);
            return qr;
        },
        //获取登录状态时 会直接将获取的用户信息 有id 存储到store/user 中
        async storeGetLonginStatus(context) {
            //此处调用
            console.log("获取登录状态 此处是longin");
            var qr = await getLonginStatus();
            // pushUserinfo 上传用户信息的函数
            console.log("得到的数据 存储到user");
            await context.commit(
                // 第一个参数为方法名，第二个为传的值，第三个root值为true
                "modelueInfouser/pushUserinfo",
                { qr: qr.data.data.account },
                { root: true }
            );

            return qr;
        },
        //退出登录
        async storeOutLongin() {
            console.log("仓库中调用了退出函数");
            let qr = await outLongin();
            return qr;
        },
    },
};
