
/* global stck, stckTop */


function initialize() {
    stck = [];
    stckTop = -1;

    document.getElementById("stackState").innerHTML = "Stack empty.";
}

function stackState() {
    if (stckTop == -1)
        document.getElementById("stackState").innerHTML = "Stack empty.";
    else
    {
        var str = "Stack: ";
        for (var i = stckTop; i >= 0; i--)
        {
            str = str + " " + stck[i];
        }
        document.getElementById("stackState").innerHTML = str;
    }
}

function push() {

    var ele = prompt("Enter element to be pushed: ");

    if (stckTop == -1)
    {
        document.getElementById("popbtn").style.visibility = "visible";
    }

    stckTop++;
    stck[stckTop] = ele;
    stackState();
}

function pop() {

    var ele = stck[stckTop];
    stckTop--;
    if (stckTop == -1)
    {
        document.getElementById("popbtn").style.visibility = "hidden";
    }
    alert("Element popped: " + ele);
    stackState();

}

