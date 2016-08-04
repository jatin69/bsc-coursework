/*
case 4 :
    Parent and child execute different program
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
        printf("\nHI PAPA, let me call test case and my PID is : %d\n\n",getpid());
        execlp("/home/jatin/Documents/os/testcase","testcase",NULL);
    }
    else if(pid >0)
    {
        wait(NULL);
        printf("\nI am your PAPA !! and my PID is : %d\n\n",getpid());
    }
        return 0;
}