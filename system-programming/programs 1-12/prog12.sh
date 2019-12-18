argc=$#

if [ $argc -gt 1  ] || [ $argc -eq 0 ]
then
    echo "---------------------------------------------------------------"
    echo -e "\nError : The argument format must ONLY be- jan...mar\n";
    echo "---------------------------------------------------------------"
    exit 1
fi

arg=$1
range=`echo $arg | tr -s "."`

month1=`echo $range | cut -d "." -f1`
month2=`echo $range | cut -d "." -f2`

set `date` ; year=$6

# THE BELOW METHOD CAN ALSO BE USED - 
# year=`date | tr " " ":" | tr -s ":" |cut -d ":" -f8`

case $month1 in
	jan*|Jan*|JAN*) val1=1 ;;
	feb*|Feb*|FEB*) val1=2 ;;
	mar*|Mar*|MAR*) val1=3 ;;
	apr*|Apr*|APR*) val1=4 ;;
	may|May|MAY)    val1=5 ;;
	jun*|Jun*|JUN*) val1=6 ;;
	jul*|Jul*|JUL*) val1=7 ;;
	aug*|Aug*|AUG*) val1=8 ;;
	sep*|Sep*|SEP*) val1=9 ;;
	oct*|Oct*|OCT*) val1=10;;
	nov*|Nov*|NOV*) val1=11;;
	dec*|Dec*|DEC*) val1=12;;
esac

case $month2 in
	jan*|Jan*|JAN*) val2=1 ;;
	feb*|Feb*|FEB*) val2=2 ;;
	mar*|Mar*|MAR*) val2=3 ;;
	apr*|Apr*|APR*) val2=4 ;;
	may|May|MAY)    val2=5 ;;
	jun*|Jun*|JUN*) val2=6 ;;
	jul*|Jul*|JUL*) val2=7 ;;
	aug*|Aug*|AUG*) val2=8 ;;
	sep*|Sep*|SEP*) val2=9 ;;
	oct*|Oct*|OCT*) val2=10;;
	nov*|Nov*|NOV*) val2=11;;
	dec*|Dec*|DEC*) val2=12;;
esac

if [ $val1 -gt  $val2 ]
then
    echo "---------------------------------------------------------------"
    echo -e "\nError : entered range is invalid \n";
    echo "---------------------------------------------------------------"
    exit 1
fi

echo "---------------------------------------------------------------"
for((i=val1;i<=val2;i++))
do
cal $i $year
done
echo "---------------------------------------------------------------"
