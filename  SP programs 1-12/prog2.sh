ask()
{
    echo -n "Enter your filename : "
    read filename
    echo ""
    check
}

check ()
{
    if test -s $filename
    then
        run
    else
        echo " THE FILE YOU ENTERED IS NOT VALID FOR THE OPERATION"
        echo " Retry later , program exiting now "
        echo "----------------------------------------------------------"
        exit 1
    fi
}

run()
{
    cat $filename | tr -t "\t" " " |tr -s " "| tr -s "\n"    > tempfilebyprog2.txt
    echo "Modified file is : "
    cat tempfilebyprog2.txt
    echo "----------------------------------------------------------"
    rm tempfilebyprog2.txt
    exit 0
}

echo "----------------------------------------------------------"
echo " \"PROGRAM TO REMOVE MULTIPLE SPACES AND EMPTY LINES\" "
echo ""
ask

