#storing arguments for further use
argv=$*
argc=$#

# checking for parameter
if [ $argc -lt 1 ]
then
    echo -e "\nError : At least one argument is required\n"
    exit 1
fi

# initialising an empty string 
rev=" "

for((i=1 ; i<= argc ; i++))
do
    #calculating the amount of shift required
    ((n=argc-i))
    # left shift the environment variables by 'n'
    shift $n
    # appending the resultant in 'rev'
    rev="$rev $1"
    # RESET the environment variables , as the previous ones are now lost 
    set $argv
done

#printing the reversed string
echo $rev
