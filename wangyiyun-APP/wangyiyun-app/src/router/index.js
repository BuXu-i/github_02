import { createRouter, createWebHistory } from "vue-router";
import HomeView from "../views/HomeView.vue";
import store from "@/store/index.js";
const routes = [
    {
        path: "/",
        name: "home",
        component: HomeView,
    },
    {
        path: "/ltemMusic",
        name: "ltemMusic",
        // route level code-splitting
        // this generates a separate chunk (about.[hash].js) for this route
        // which is lazy-loaded when the route is visited.
        component: () =>
            import(/* webpackChunkName: "about" */ "../views/ltemMusic.vue"),
    },
    {
        path: "/search",
        name: "search",
        component: () => import("../views/Search.vue"),
    },
    {
        path: "/infoUser",
        name: "infoUser",
        beforeEnter: (to, from, next) => {
            if (store.state.islogin) {
                next();
            } else {
                //
                // store.mutations.
                // store.commit("updataLoginShow");
                router.push("/login");
            }
        },
        component: () => import("../views/InfoUser.vue"),
    },
    {
        path: "/login", //登录路由
        name: "login",
        beforeEnter: (to, from, next) => {
            store.commit("updataLoginShow");
            next();
        },
        component: () => import("../views/Login.vue"),
    },
];

const router = createRouter({
    history: createWebHistory(process.env.BASE_URL),
    routes,
});

export default router;
