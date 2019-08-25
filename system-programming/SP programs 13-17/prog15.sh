check()
{
    if test -e $fname
    then 
        echo "----------------------------------------------------------"
        action 
        else
        echo -e "\n\tTHE FILE YOU ENTERED IS NOT VALID , please try again"
        exit 1
    fi
}

action()
{
    awk 'BEGIN{ UB=30;}
    {
    n= length($0)
    i=1
    while(n>=0)
    {
        str= substr($0,i,UB);
        print str;
        n=n-UB;
        i=i+UB;
    }
} ' $fname
}

echo "----------------------------------------------------------"
echo "Enter the filename"
read fname
check
echo "----------------------------------------------------------"
     