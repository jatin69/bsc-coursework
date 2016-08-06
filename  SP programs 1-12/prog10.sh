sortandmerge()
{
    sort -m $fname1 $fname2 $fname3 > merge.txt
    echo -e "\nMerged and sorted file :-"
    echo "----------------------------------------------------------"
    sort merge.txt | more
    echo -e "----------------------------------------------------------\n"
    rm merge.txt
}



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
        echo -e "\nTHIS FILE DOES NOT EXISTS , please Retry\n"
        echo "----------------------------------------------------------"
        exit 1
    fi
}



check3()
{
    if !(test -s $fname3)
    then
        echo -e "\nTHIS FILE DOES NOT EXISTS , please Retry\n"
        echo "----------------------------------------------------------"
        exit 1
    fi
}

clear
echo "----------------------------------------------------------"
echo -e "\t \"PROGRAM TO SORT & MERGE GIVEN FILES\" \n"
echo -n "Enter name of the 1st file : "
read fname1
check1
echo -ne "\nEnter name of the 2nd file : "
read fname2
check2
echo -ne "\nEnter name of the 3rd file : "
read fname3
check3
echo ""
sortandmerge
