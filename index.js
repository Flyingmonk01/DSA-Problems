
const zodiac = document.getElementById("zodiac");

const body = document.body;

const changeBackground = () => {
    switch (zodiac.value) {
        case "aries":
            body.style.backgroundColor = "violet";
            break;
        case "tarus":
            body.style.backgroundColor = "indigo";
            break;
        case "gemini":
            body.style.backgroundColor = "blue";
            break;
        case "cancer":
            body.style.backgroundColor = "green";
            break;
        case "virgo":
            body.style.backgroundColor = "yellow";
            break;
        case "libra":
            body.style.backgroundColor = "orange";
            break;
        case "scorpio":
            body.style.backgroundColor = "red";
            break;
        case "saggitarius":
            body.style.backgroundColor = "black";
            break;
        case "aquarius":
            body.style.backgroundColor = "purple";
            break;
        case "capricorn":
            body.style.backgroundColor = "pink";
            break;
        case "pisces":
            body.style.backgroundColor = "burlywood";
            break;
        default:
            body.style.backgroundColor = "#fff";
            break;
    }
}