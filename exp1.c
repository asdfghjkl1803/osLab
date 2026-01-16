#include <stdio.h>      // For printf()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For fork(), execlp(), getpid()
#include <sys/wait.h>   // For wait()

int main(int argc, char *arg[])
{
    int pid1, pid2, pid3;   // Variables to store process IDs

    pid1 = fork();          // Create first child process

    if (pid1 < 0)           // If fork() returns a negative value
    {
        printf("fork failed\n"); // Fork failed
        exit(1);            // Exit the program with error
    }
    else if (pid1 == 0)     // If fork() returns 0, this is the first child process
    {
        printf("Child 1 Process ID is: %d\n", getpid()); // Print child 1 process ID
        exit(0);            // Exit child 1 process
    }
    else                    // Parent process continues
    {
        pid2 = fork();      // Create second child process

        if (pid2 < 0)       // If fork() returns a negative value
        {
            printf("fork failed\n"); // Fork failed
            exit(1);        // Exit the program with error
        }
        else if (pid2 == 0) // If fork() returns 0, this is the second child process
        {
            printf("Child 2 Process ID is: %d\n", getpid()); // Print child 2 process ID
            exit(0);        // Exit child 2 process
        }
        else                // Parent process continues
        {
            pid3 = fork();  // Create third child process

            if (pid3 < 0)   // If fork() returns a negative value
            {
                printf("fork failed\n"); // Fork failed
                exit(1);    // Exit the program with error
            }
            else if (pid3 == 0) // If fork() returns 0, this is the third child process
            {
                printf("Child 3 Process ID is: %d\n", getpid()); // Print child 3 process ID
                exit(0);    // Exit child 3 process
            }
            else            // Parent process
            {
                printf("Parent Process ID is: %d\n", getpid()); // Print parent process ID
                wait(NULL); // Wait for first child
                wait(NULL); // Wait for second child
                wait(NULL); // Wait for third child
                exit(0);    // Exit parent process
            }
        }
    }
}
