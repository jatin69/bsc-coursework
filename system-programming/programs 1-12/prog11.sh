argc=$#

if [ $argc -eq 0 ]
then
    echo "----------------------------------------------------------"
    echo -e "\nError : Please provide a month name as argument "
    echo "----------------------------------------------------------"
    exit
fi

# extract current year
year=`date | tr " " ":" | tr -s ":" |cut -d ":" -f8`

echo -e "----------------------------------------------------------\n"

for arg in $*
{		
    case $arg in
	jan*|Jan*|JAN*) val=1 ;;
	feb*|Feb*|FEB*) val=2 ;;
	mar*|Mar*|MAR*) val=3 ;;
	apr*|Apr*|APR*) val=4 ;;
	may|May|MAY)    val=5 ;;
	jun*|Jun*|JUN*) val=6 ;;
	jul*|Jul*|JUL*) val=7 ;;
	aug*|Aug*|AUG*) val=8 ;;
	sep*|Sep*|SEP*) val=9 ;;
	oct*|Oct*|OCT*) val=10;;
	nov*|Nov*|NOV*) val=11;;
	dec*|Dec*|DEC*) val=12;;
	*) echo -e "\n Error : '$arg' is not a month, Please try again \n"
        echo "----------------------------------------------------------"
        exit 1
    esac

cal $val $year
}

echo "----------------------------------------------------------"

