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
        echo " THE FILE YOU ENTERED IS NOT VALID , please retry"
        echo "----------------------------------------------------------"
        exit 1
    fi
}

run()
{
    echo -e "\nMENU"
    echo "1. display contents of the file"
    echo "2. Overwrite contents of the file ( press ENTER and CTRL+D to save the file )"
    echo "3. Append contents in the file    ( press ENTER and CTRL+D to save the file )"
    echo "4. exit"
    echo -ne "\nEnter your choice :"
    read choice
    echo ""
    action
}

action()
{
    case $choice in 
        1)
        echo "----------------------------------------------------------"
        cat $filename
        echo "----------------------------------------------------------"
        run
        ;;
        2)
        echo "----------------------------------------------------------"
        cat > $filename
        echo "----------------------------------------------------------"
        echo -e "\n File contents successfully overwritten !!\n"
        run
        ;;
        3)
        echo "----------------------------------------------------------"
        cat >> $filename
        echo "----------------------------------------------------------"
        echo -e "\n File successfully appended !!\n"
        run
        ;;
        4)
        echo " User requested exit , program exiting now "
        echo "----------------------------------------------------------"
        exit 0
        ;;
        *) 
        echo "please enter a valid option" 
        ;;
    esac
}

echo "----------------------------------------------------------"
echo -e "\t \"PROGRAM TO MODIFY THE FILE CONTENTS\" \n"
ask
