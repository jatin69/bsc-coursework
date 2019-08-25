# this question can also be done by using the if elif ladder

# extract current hour
hour=`date | tr " " ":" | tr -s ":" |cut -d ":" -f4`

echo -e "----------------------------------------------------------\n"

case $hour in
    0[0-9]|1[0-1] ) echo -e "\nGood Morning" ;; 
    1[2-5]) echo -e "\nGood Afternoon" ;;
    1[6-9]) echo -e "\nGood Evening" ;;
    *) echo -e "\nGood Night";; 
esac

echo -e "\n----------------------------------------------------------"

