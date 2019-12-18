### modified to appreciate awk , use of NR

BEGIN{ }
{
    for( i=1 ; i<NR ; i++)
    {   
        if(line[i]==$0)
        {
           break
        }
    }      
    if(i==NR)
    {
        line[NR]=$0
           print $0
    }
}
END{ }