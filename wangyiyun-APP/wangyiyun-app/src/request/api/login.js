import servece from "..";
//二维码登录  得到key
export function getloginqr_1() {
    console.log("生成key值中");
    return servece({
        method: "get",
        url: `/login/qr/key?timerstamp=${new Date().getTime()}`,
    });
}

// 2. 二维码生成接口
export function getloginqr_2(key) {
    console.log("已生成key值中");
    console.log(key);
    return servece({
        method: "get",
        url: `/login/qr/create?key=${key}&qrimg=true&timerstamp=${new Date().getTime()}`,
    });
}
// 3. 二维码检测扫码状态接口
//轮询此接口可获取二维码扫码状态,
//800 为二维码过期,801 为等待扫码,802 为待确认,
//803为授权登录成功(803 状态码下会返回 cookies)
export function getloginqr_3(key) {
    console.log("检测扫码");
    console.log(new Date().getTime());
    console.log(Date.now());
    return servece({
        method: "get",
        url: `/login/qr/check?key=${key}&timerstamp=${new Date().getTime()}`, //给一个毫秒时间戳
    });
}
//游客登陆 会返回以个kookie
export function getanonimous() {
    console.log("游客登陆");
    return servece({
        method: "get",
        url: `/register/anonimous`,
    });
}
//电话号码 密码 登录
export function getloginphone(phonePassword) {
    console.log("axis 电话密码登录中");
    console.log(phonePassword);
    console.log(phonePassword.phone);
    return servece({
        method: "get",
        url: `/login/cellphone?phone=${phonePassword.phone}&password=${phonePassword.password}`,
    });
}
//电话号码 发送验证码 登录
export function getloginphone_captcha(phone) {
    console.log("getloginphone_captcha");
    return servece({
        method: "get",
        url: `/captcha/sent?phone=${phone}`,
    });
}

//电话号码 验证电话验证码 登录
export function getloginphonecaptcha(phoneCaptcha) {
    console.log("getloginphonecaptcha+正在请求");
    console.log(phoneCaptcha);
    return servece({
        method: "get",
        url: `/captcha/verify?phone=${phoneCaptcha.phone}&captcha=${phoneCaptcha.captcha}`,
    });
}

//获取登录状态
export function getLonginStatus() {
    return servece({
        method: "get",
        url: `/login/status`,
    });
}
//退出登录
export function outLongin() {
    return servece({
        method: "get",
        url: `/logout`,
    });
}
