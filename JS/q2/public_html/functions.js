
function chkPassword()
{
    var passwd = prompt("Please enter password: ");
    
    if(passwd == "root")
        return true;
    else
        return chkPassword();
}

