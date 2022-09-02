const clock = document.getElementById('clock')

const showTime = () => {

const date = new Date()
const hour = date.getHours()
const min = date.getMinutes()
const sec = date.getSeconds()

const time = `${date.getHours()} : ${date.getMinutes()} : ${date.getSeconds()}`

/* Trial for 2 digit time format
if(hour>9 && min>9 && sec>9 ){
    const time = `${date.getHours()} : ${date.getMinutes()} : ${date.getSeconds()}`
}
else if (hour<10) {
    const time = `0 ${date.getHours()} : ${date.getMinutes()} : ${date.getSeconds()}`
}
else if (min<10){
    const time = `${date.getHours()} : 0 ${date.getMinutes()} : ${date.getSeconds()}`
}
else {
    const time = `${date.getHours()} : ${date.getMinutes()} : 0 ${date.getSeconds()}`
}
*/


clock.innerHTML = time
}

a = setInterval(showTime,1)

const btn = document.getElementById('stop')

c = 0
btn.addEventListener('click', () => {
    if (c==0) {
        clearInterval(a)
        c = 1
    }
    else {
        a = setInterval(showTime,1)
        c = 0
    }
    })

/*
c = True
 btn.addEventListener('click', () => {
    c = !c
    if (c) {
        clearInterval(a)
    }
    else {
        a = setInterval(showTime,1)
    }
    })
*/