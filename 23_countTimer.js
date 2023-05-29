
const daysElement = document.querySelector(".days");
const hoursElement = document.querySelector(".hours");
const minutesElement = document.querySelector(".minutes");
const secondsElement = document.querySelector(".seconds");


const second = 1000,
    minute = 60 * second,
    hour = 60 * minute,
    day = 24 * hour;


const timerFunction = () => {

    setInterval(() => {
        const timer = new Date("05/30/2023").getTime();

        const today = new Date().getTime();

        const difference = timer - today;

        const leftDay = Math.floor((difference / day));
        const leftHour = Math.floor((difference % day) / hour);
        const leftMinute = Math.floor((difference % hour) / minute);
        const leftSecond = Math.floor((difference % minute) / second);

        daysElement.innerText = leftDay;
        hoursElement.innerText = leftHour;
        minutesElement.innerText = leftMinute;
        secondsElement.innerText = leftSecond;

        // console.log(`${leftDay}:${leftHour}:${leftMinute}:${leftSecond}`);

        // console.log(timer);
        // console.log(today);
        // 
        // console.log();
        // console.log();
        // console.log();
    }, 0);

}


timerFunction();
