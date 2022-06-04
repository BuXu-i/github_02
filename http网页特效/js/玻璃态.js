const kami = document.querySelector('.garasu>.kami')
const box_frist = document.querySelectorAll('.garasu>.box_frist>li')
console.log(kami);
console.log(box_frist);

function box_back(obj) {
    // console.log(obj);
    kami.style.marginLeft = obj.offsetLeft + 10 + 'px'
        // console.log(obj.offsetLeft);
}
box_frist.forEach(link => {
    link.addEventListener('mouseover', (e) => {
        console.log(link);
        box_back(link)
    })
})