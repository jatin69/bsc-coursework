count = 0;

function func() {

    setTimeout(function () {
        document.getElementById("p1").style.color = "red";
    }, 4000);

    setInterval(function () {
        var x = count % 6;
        if (x == 0)
            document.getElementById("img").style.left = 500 + "px";
        else if (x == 1)
            document.getElementById("img").style.left = 1000 + "px";
        else if (x == 2)
            document.getElementById("img").style.top = 200 + "px";
        else if (x == 3)
            document.getElementById("img").style.left = 500 + "px";
        else if (x == 4)
            document.getElementById("img").style.left = 0 + "px";
        else
            document.getElementById("img").style.top = 0 + "px";

        count++;
    }, 1200);
}



