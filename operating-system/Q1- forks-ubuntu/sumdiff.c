/*
sum and difference code 0:
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int a=4,b=5;
    pid_t pid;
    pid= fork();
    if(pid<0)
    {
        printf("\nError !! Process not created successfully.\n");
    }
    else if( pid == 0)
    {
        int a=30,b=10;
        printf("\nHI PAPA !! and my PID is : %d\n",getpid());
        //scanf("%d",&a);
        
        printf("sum is : %d",a+b);
        //execlp("/home/jatin/Documents/os/testcase","testcase",NULL);
    }
    else if(pid >0)
    {
        wait(NULL);
        printf("\nI am your PAPA !! and my PID is : %d\n\n",getpid());
                printf("Diff is : %d\n\n",a-b);
    }
        return 0;
}