echo -e "---------------------------------------------------------\n"

# get all unique users in a text file
who | tr -s " " | cut -d" " -f1 | sort | uniq > unique_users.txt
echo -e "All the unique users are : "
cat unique_users.txt

# get the count of unique users
count=`cat unique_users.txt | wc -l`

# modify the file , replacing "\n" by " " , so as to use 'cut' command on the file
cat unique_users.txt | tr "\n" " " > spaced_users.txt

for((i=1;i<=count;i++))
do
    patt=`cat spaced_users.txt | cut -d" " -f$i`
    no_of_times=`who | grep -c "$patt"`
    echo -e "\nThe user \"$patt\" logged in $no_of_times times."
done

rm spaced_users.txt
rm unique_users.txt

echo -e "\n--------------------------------------------------------"
