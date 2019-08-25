check()
{
    if test -s $fname
    then 
        echo "----------------------------------------------------------"
        menu
    else
        echo -e "\n\tTHE FILE YOU ENTERED IS NOT VALID "
        echo "----------------------------------------------------------"
    fi
}


menu()
{
    echo -e "\nFile Options : "
    echo -e "1.Display the file."
    echo -e "2.Display the permissions of the file."
    echo -e "3.Find a pattern in the file- ignoring case"
    echo -e "4.Find a pattern in the file- case sensitive"
    echo -e "5.Replace all letters 'e' by 'a'"
    echo -e "6.Exit"
    echo -en "\nEnter your choice : "
    read ch
    choice
    echo ""
}

choice()
{
    case $ch in
        1) 
        echo -e "\nYour file is-"
        echo "----------------------------------------------------------"
        cat $fname
        echo "----------------------------------------------------------"
        ;;
        
        2) echo -e "\nThe permissions of the file are-"
        ls -l $fname | cut -d " " -f1
        echo "----------------------------------------------------------"
        ;;	

        3) echo -e "\nEnter the pattern to be searched-"
        read patt
        echo "----------------------------------------------------------"
        grep -i $patt $fname
        echo "----------------------------------------------------------"
        ;;

        4) echo -e "\nEnter the pattern to be searched-"
        read patt
        echo "----------------------------------------------------------"
        grep $patt $fname 
        echo "----------------------------------------------------------"
        ;;

        5) echo -e "\nModified file is : "
        echo "----------------------------------------------------------"
        cat $fname | tr 'e' 'a' 
        echo "----------------------------------------------------------"
        ;;

        6) echo -e "\n\tUser requested exit , exiting ... "
        echo "----------------------------------------------------------"
        exit 0
        ;;

        *) echo -e "\nPlease enter a valid choice"
    esac

    menu
}

clear
echo "----------------------------------------------------------"
echo -e "\tPROGRAM TO INTERACT WITH FILE OPTIONS "
echo -en "\nEnter a filename : "
read fname
check
