/*
case 2 :
    Parent and child execute same program but different piece of code
    
    Uncomment code to see working.
    parent comes, call fork(), child created -> assigned a new working pid,
    jumps to child -> goes to fork() call -> gets pid 0 -> starts execution just after fork() call, finish execution,
    comes back to parent and finishes execution
 */

#include <stdio.h>
//#include <sys/types.h>
#include <unistd.h>

int main()
{
   //     printf("\nJust got papa pid is%d\n\n",getpid());

    pid_t pid;
    pid= fork();
   //     printf("\nJust got pid is%d\n\n",pid);
    if(pid<0)
    {
        printf("\nError !! Process not created successfully.\n");
    }
    else if( pid == 0)
    {
        printf("\nHI PAPA and my PID is : %d\n\n",getpid());
    }
    else if(pid >0)
    {wait(NULL);
        printf("\nI am your PAPA !! and my PID is : %d\n\n",getpid());
    }
        return 0;
}