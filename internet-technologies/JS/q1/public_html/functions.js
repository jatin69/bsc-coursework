function validate() {
    
   // return var y = (validateRollNo() && validateName() && validateAge() && validateCourse() && validateZip());
    var x= validateRollNo() & validateName() & validateAge() & validateCourse() & validateZip();
   
    if(x==0)
        return false;
    else
        return true;
}

/* Roll no. length: 7 */
function validateRollNo() {

    var rollno = document.getElementById("rollno").value;
    var regexRollNo = /^[0-9][0-9]{6}$/;
   // var regexRollNo=/[0-9]{2}[A-Z]{3}[0-9]{4}/;

    if (regexRollNo.test(rollno))
    {
        document.getElementById("rollnoE").style.visibility = "hidden";
        return true;
    }
    else
    {
        document.getElementById("rollnoE").style.visibility = "visible";
        return false;
    }
}

/* Max name length: 30 chars */
function validateName() {

    var name = document.getElementById("name").value;
    var regexName = /^[a-zA-Z][a-zA-Z ]{0,29}$/;

    if (regexName.test(name))
    {
        document.getElementById("nameE").style.visibility = "hidden";
        return true;
    }
    else
    {
        document.getElementById("nameE").style.visibility = "visible";
        return false;
    }
}

/* Age should be between 15 and 25 */
function validateAge() {

    var age = document.getElementById("age").value;

    if (age >= 15 && age <= 25)
    {
        document.getElementById("ageE").style.visibility = "hidden";
        return true;
    }
    else
    {
        document.getElementById("ageE").style.visibility = "visible";
        return false;
    }
}

function validateCourse() {

    var course = document.getElementById("course").value;

    if (course === "default")
    {
        document.getElementById("courseE").style.visibility = "visible";
        return false;
    }
    else
    {
        document.getElementById("courseE").style.visibility = "hidden";
        return true;
    }
}

function validateZip() {

    var zip = document.getElementById("zip").value;
    var regex = /^[1-9][0-9]{5}$/;

    if (regex.test(zip))
    {
        document.getElementById("zipE").style.visibility = "hidden";
        return true;
    }
    else
    {
        document.getElementById("zipE").style.visibility = "visible";
        return false;
    }
}
