#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
using namespace std;

int main()
{
    int pid1 = fork();
    
    if (pid1 < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    else if (pid1 == 0)
    {
        printf("Child Process 1 ID: %d\n", getpid());
        
        int pid2 = fork();
        
        if (pid2 < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }
        else if (pid2 == 0)
        {
            printf("Child Process 2 ID: %d\n", getpid());
        }
        else
        {
            wait(NULL);
        }
        exit(0);
    }
    else
    {
        printf("Parent Process ID: %d\n", getpid());
        wait(NULL);
    }
    
    return 0;
}