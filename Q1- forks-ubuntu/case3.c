/*
case 3 :
    Parent and child execute same program but different piece of code
    and parent process waits for child process to execute. 
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
    else if( pid == 0)
    {
         printf("\nHI PAPA and my PID is : %d\n\n",getpid());
        
    }
    else if(pid >0)
    {
        wait(NULL);
         printf("\nI am your PAPA !! and my PID is : %d\n\n",getpid());
    }
        return 0;
}