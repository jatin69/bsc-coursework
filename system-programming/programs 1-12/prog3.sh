<<"COMMENT"

No argument is passed :
# current month is taken up as "Jan"
# current year is taken up as "2015"

One argument is passed :
# month name is passed as "jan/Jan/JAN" OR "12"  THEN current year is taken up as "2015"
OR
# year is passed as "2015" 

Two arguments are passed :
# month name is passed as "jan/Jan/JAN" OR "12"
AND
# year is passed as "2015" 

COMMENT

case $# in
    0) # use current month and current year
    set `date` ; m=$2 ; y=$6    
    ;;

    1) # use current year 
    m=$1 ; set `date` ; y=$6
    ;;

    2)
    m=$1 ; y=$2
    ;;

    *)
    echo "--------------------------------------------------------"
    echo -e "\nMaximum no of arguments are 2\n"
    echo "--------------------------------------------------------"
    exit 1
esac

case $m in
        jan*|Jan*|JAN*) m=01 ;;
	feb*|Feb*|FEB*) m=02 ;;
	mar*|Mar*|MAR*) m=03 ;;
	apr*|Apr*|APR*) m=04 ;;
	may|May|MAY   ) m=05 ;;
	jun*|Jun*|JUN*) m=06 ;;
	july|Jul*|JUL*) m=07 ;;
	aug*|Aug*|AUG*) m=08 ;;
	sep*|Sep*|SEP*) m=09 ;;
	oct*|Oct*|OCT*) m=10 ;;
	nov*|Nov*|NOV*) m=11 ;;
        dec*|Dec*|DEC*) m=12 ;;
	
	[1-9]|1[0-2])  ;;  # numeric month passed
	
	*) y=$m; m="" ;;   # plain year passed
esac

echo -e "--------------------------------------------------------\n"
cal $m $y
echo -e "\n--------------------------------------------------------"
