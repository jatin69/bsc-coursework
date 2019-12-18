
BEGIN{ UB=30;}
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
}


