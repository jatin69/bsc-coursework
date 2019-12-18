check1()
{
    if !(test -s $fname1) 
    then
        echo -e "\nTHIS FILE DOES NOT EXISTS , please Retry\n"
        echo "----------------------------------------------------------"
    exit 1
    fi
}


check2()
{
    if !(test -s $fname2)
    then
        echo -e "\nTHE SECOND FILE DOES NOT EXISTS , please Retry\n"
        echo "----------------------------------------------------------"
        exit 1
    fi
}


compare()
{
    echo ""	
    cmp $fname1 $fname2
    status=`echo $?`
    if [ $status -eq 0 ]	#the files are same
    then
        echo -e "Second file is duplicate , Removing second file .. "
        rm -f $fname2
        echo "----------------------------------------------------------"
    else
        echo -e "\nContents are not same "
        echo "----------------------------------------------------------"
    fi
}

checksame()
{
    if [ "$fname1" = "$fname2" ]
    then
        echo -e "\nError : same file passed at both places , please Retry\n"
        echo "----------------------------------------------------------"
        exit 1
    fi
}

echo "----------------------------------------------------------"
echo -e "\t \"PROGRAM TO DELETE DUPLICATE FILE\" \n"
echo -n "Enter name of the 1st file : "
read fname1
check1
echo -ne "\nEnter name of the 2nd file : "
read fname2
check2
echo ""
checksame
compare
