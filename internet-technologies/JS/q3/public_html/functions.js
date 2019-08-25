
/* global arr */
/* global num */

function enterN() {

    num = prompt("Enter number of elements: ");

    if (num > 0) {
        document.getElementById("nButton").style.display = "none";
        document.getElementById("div1").innerHTML = "Number of elements: " + num;
        document.getElementById("eleButton").style.visibility = "visible";
    }
    else
    {
        alert("Number of elements should be greater than 0!");
        enterN();
    }

}

function enterElements() {

    arr = [];
    var str = "Elements                   :\n";
    for (i = 0; i < num; i++) {
        arr[i] = parseInt(prompt("Enter element arr[" + i + "]: "));
        str = str + arr[i] + " ";
    }

    document.getElementById("eleButton").style.display = "none";
    document.getElementById("div2").style.visibility = "visible";
    document.getElementById("div2").innerHTML = str;

    document.getElementById("sortButton").style.visibility = "visible";
}

function bubbleSort() {

    for(i=0; i<num-1; i++)
    {
        for(j=0; j<num-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                var temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    var str = "Sorted elements       : ";
    for (i = 0; i < num; i++) {
        str = str + arr[i] + " ";
    }
    
    document.getElementById("sortButton").style.display = "none";
    document.getElementById("div3").style.visibility = "visible";
    document.getElementById("div3").innerHTML = str;
}


