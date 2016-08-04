/*
case 1 :
    Parent and child execute same piece of code
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    pid= fork();
    if(pid<0)
    {
        printf("\nError !! Process not created successfully.\n");
    }
    else 
    {
        printf("\nHere I AM !!\n\n");
    }
        return 0;
}
