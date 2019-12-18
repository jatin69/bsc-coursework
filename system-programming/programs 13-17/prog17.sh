# as done in class -- "tee" used

if [  $# -eq 2 ]
    then
    ls -l $1 $2 | cut -d" " -f1 | tr '\n' ' ' > t1.txt
    awk '$1==$2 { print "Permisions are identical"}' t1.txt | tee t2.txt
    if [ ! -s t2.txt ]
        then
        echo "Permissions are different "
    fi
else
    echo "Please provide two arguments"
fi
if test -s t1.txt
then
    rm t1.txt t2.txt
fi
    