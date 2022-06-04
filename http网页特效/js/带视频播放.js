const thead = document.getElementsByClassName('thead')

const tuki = document.querySelector('.right-top .tuki')

const mask = document.querySelector('.mask')
tuki.addEventListener('click', (e) => {
    if (mask.className === 'mask') {
        mask.className = mask.className + ' mask_tuki'
        tuki.children[0].innerHTML = '<use xlink:href="#icon-taiyang_sun61">'
        second_B.style.color = thead[0].style.color = 'pink'
        second_B.style.backgroundColor = '#504f4f'
    } else {
        mask.className = 'mask'
        tuki.children[0].innerHTML = '<use xlink:href="#icon-yejing">'
        second_B.style.color = thead[0].style.color = ''
        second_B.style.backgroundColor = '#fff' //给另一个页面也变黑
    }
})

const hannme = document.querySelector('.hannme')
const second_B = document.querySelector('.second_B')
const first_A = document.querySelector('.first_A')
const hannme_logo = document.querySelector('.right-top .hannme')

hannme.addEventListener('click', (e) => {
    if (hannme.dataset.pp === 'true') {
        hannme.dataset.pp = 'false'
        second_B.style.left = 0 + 'px'
        hannme_logo.children[0].innerHTML = '<use xlink:href="#icon-arrow_left_fat">'
    } else {
        second_B.style.left = -100 + '%'
        hannme_logo.children[0].innerHTML = '<use xlink:href="#icon-arrow_right_fat">'
        hannme.dataset.pp = 'true'
    }
})


//hannme 点击事件
// 动画 定时器
// const tiam = setTimeout()

// 使用定时器来渐变   可以直接家效果 
// var pp = true //阀门
// function tekiru(obj, tarset, spito) {
//     if (!pp)
//         return;
//     if (spito > 0) {
//         pp = false
//         var time_A = setInterval((e) => {
//             obj.style.left = obj.offsetLeft + spito + 'px';
//             if (obj.offsetLeft > tarset) {
//                 pp = true
//                 obj.style.left = tarset + 'px'
//                     //让first_A不显示
//                 first_A.style.display = 'none'
//                 clearTimeout(time_A)
//             }
//         }, 10);
//     } else {
//         first_A.style.display = ''
//         pp = false
//         var key = 0
//         var time_B = setInterval((e) => {
//             obj.style.left = - ++key + '%';
//             if (key === 100) {
//                 pp = true
//                 clearTimeout(time_B)
//             }
//         }, 10);
//     }
// }
// hannme.addEventListener('click', (e) => {
//     if (hannme.dataset.pp === 'true') {
//         hannme.dataset.pp = 'false'
//         tekiru(second_B, 0, 10)
//     } else {
//         hannme.dataset.pp = 'true'
//         tekiru(second_B, '100%', -10)
//     }
// })