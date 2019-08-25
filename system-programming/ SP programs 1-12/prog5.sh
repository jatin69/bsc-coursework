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
    echo -e "2.Display last n lines of the file."
    echo -e "3.Sort the file in ascending order."
    echo -e "4.Sort the file in descending order."
    echo -e "5.Exit"
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
            
        2)
        echo -ne "\nEnter n : "
        read n
        echo -e "\n The last $n lines of the file are : "
        echo "----------------------------------------------------------"
        tail -$n $fname
        echo "----------------------------------------------------------"
        ;;
    
        3)
        echo -e "File sorted in ascending order is :"
        echo "----------------------------------------------------------"
        sort $fname
        echo "----------------------------------------------------------"   
        ;;
                
        4)
        echo -e "File sorted in descending order is :"
        echo "----------------------------------------------------------"
        sort -r $fname
        echo "----------------------------------------------------------"   
        ;;
            
        5)
        echo "----------------------------------------------------------"
        echo -e "\n\tUser requested exit , exiting ... "
        echo "----------------------------------------------------------"
        exit 0
        ;;

        *) echo -e "\nPlease enter a valid choice"
    esac

    menu
}

clear
echo "----------------------------------------------------------"
echo -e "\tPROGRAM TO INTERACT WITH FILE SORT OPTIONS "
echo -en "\nEnter a filename : "
read fname
check
