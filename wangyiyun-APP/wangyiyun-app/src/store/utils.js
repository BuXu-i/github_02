import { getToken, setToken, removeToken } from "../utils/index";

export const modelueToken = {
    namespaced: true,
    state: {
        token: getToken(),
    },
    mutations: {
        //设置token
        settoken(state, token) {
            setToken(token);
        },
        //删除token
        removeToken(state) {
            removeToken();
        },
    },
};
