### modified to appreciate awk , use of NR

BEGIN{ }
{
    arr[NR]=$0;
}
END{
    printf "\nOriginal array : "
    for(i=0 ; i<NR ; i++)
        print arr[i]

    for(i=0 ; i<NR ; i++)
    {    for( j=0; j<NR-i-1 ; j++)
        {
            if(arr[j]>arr[j+1])
            { 
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
            
    printf "\nSorted array : "
    for(i=0 ; i<NR ; i++)
        print arr[i]
        
        print ""
}


