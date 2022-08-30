<!-- //歌词部分 -->
<template>
    <div class="musicLyric" ref="musicLyric">
        <p v-for="(iemt) in lyric" :key="iemt.id" :class="{'active':currentime>iemt.time&&currentime<iemt.back}">
            {{iemt.lrc}}
            <!-- {{currentime}} -->
        </p>
    </div>
</template>

<script>
import { mapState } from "vuex";
export default {
    data() {
        return {
            arr: [],
        };
    },
    computed: {
        ...mapState(["lyricList", "currentime"]),
        //从store中获取歌词 并进行处理 分割
        lyric: function () {
            console.log("处理歌词*lyric*部分");
            if (this.lyricList) {
                this.arr = this.lyricList.lyric
                    .split(/[(\r\n)\r\n]+/)
                    //集合
                    .map((item) => {
                        //会依次传入map集合中做出处理
                        let min = parseInt(item.slice(1, 3)); //分
                        let sec = parseInt(item.slice(4, 6)); //秒
                        let mill = parseInt(item.slice(7, 11)); //分
                        // let lrc = item.slice(11);
                        let lrc = item.slice(item.lastIndexOf("]") + 1).trim();
                        //parseInt会尽量解析 只要第一个非空格是数字 即不会返回nan
                        let time = min * 60 * 1000 + sec * 1000 + mill;
                        return {
                            min,
                            sec,
                            mill,
                            lrc,
                            time,
                            back: 0,
                        };
                    });
            }
            //载入结束时间
            this.arr.forEach((key, index) => {
                if (index == this.arr.length - 1) {
                    console.log("相等的时候");
                } else {
                    key.back = this.arr[index + 1].time;
                }
            });
            console.log(this.arr);
            return this.arr;
        },
    },
    watch: {
        currentime(newvlu, oldvlu) {
            var p = document.querySelector(".musicLyric .active");
            // console.log({ p });
            // console.log(p.offsetTop);
            // console.log(this.$refs.musicLyric.scrollTop);
            if (p) {
                //避免没拿到 p 导致出错
                if (p.offsetTop > 270) {
                    //开始歌词滚动
                    //给个定时器 在刷新时间内  逐步 完成距离top 的变化
                    this.$refs.musicLyric.scrollTop = p.offsetTop - 250;
                }
            }
        },
    },
    mounted() {
        console.log("我是歌词部分的渲染结束");
    },
};
</script>

<style lang="less" scoped>
.musicLyric {
    width: 100%;
    height: 100%;
    display: flex;
    flex-direction: column;
    align-items: center;
    margin-top: 0.2rem;
    font-size: 0.36rem;
    overflow: scroll; //溢出滚动
    // transition: all 6s;
    p {
        color: #000;
        margin-bottom: 18px;
        // transition: all 0.5s;
    }
    .active {
        color: #fff;
        // font-size: 0.5rem;
        //使用tuansfrom 来变化属性 与其他元素无关
        transform: scale(1.5);
        transition: all 0.5s;
    }
}
</style>