# with use of single file -- "tee" not used

if [  $# -eq 2 ]
then
    ls -l $1 $2 | cut -d" " -f1 | tr "\n" " " > t1.txt
    awk '{
    if($1==$2)  
        print "Permisions are identical"; 
    else
        print "Permisions are different";
    }' t1.txt
    
else
    echo "Please provide two arguments"
fi

if test -s t1.txt
then
    rm t1.txt
fi
