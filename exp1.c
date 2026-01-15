#include <stdio.h>      // For printf()
#include <stdlib.h>     // For exit()
#include <unistd.h>     // For fork(), execlp(), getpid()
#include <sys/wait.h>   // For wait()

int main(int argc, char *arg[])
{
    int pid;            // Variable to store the process ID

    pid = fork();       // Create a new process (child process)

    if (pid < 0)        // If fork() returns a negative value
    {
        printf("fork failed\n"); // Fork failed
        exit(1);        // Exit the program with error
    }
    else if (pid == 0)  // If fork() returns 0, this is the child process
    {
        execlp("whoami", "1s", NULL); // Replace child process with "whoami" command
        exit(0);        // Exit child process after execution
    }
    else                // If fork() returns a positive value, this is the parent process
    {
        printf("\nProcess ID is: %d\n", getpid()); // Print parent process ID
        wait(NULL);     // Parent waits for child process to finish
        exit(0);        // Exit parent process
    }
}
