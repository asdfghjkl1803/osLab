#include <stdio.h>      // Include standard input/output library
#include <stdlib.h>     // Include standard library for exit()
#include <unistd.h>     // Include POSIX API for fork() and getpid()
#include <sys/wait.h>   // Include wait() function for process synchronization

int main(int argc, char *arg[])  // Main function with command line arguments
{
    int pid1, pid2, pid3;  // Declare variables to store process IDs

    pid1 = fork();         // Create first child process; returns child PID to parent, 0 to child

    if (pid1 < 0)          // Check if fork() failed
    {
        printf("fork failed\n");  // Print error message
        exit(1);           // Exit with error code
    }
    else if (pid1 == 0)    // If this is the first child process
    {
        printf("Process ID is: %d\n", getpid());  // Print child's own process ID
        exit(0);           // Child exits with success
    }
    
    pid2 = fork();         // Create second child process (parent only)

    if (pid2 < 0)          // Check if fork() failed
    {
        printf("fork failed\n");  // Print error message
        exit(1);           // Exit with error code
    }
    else if (pid2 == 0)    // If this is the second child process
    {
        printf("Process ID is: %d\n", getpid());  // Print child's process ID
        exit(0);           // Child exits with success
    }
    
    pid3 = fork();         // Create third child process (parent only)

    if (pid3 < 0)          // Check if fork() failed
    {
        printf("fork failed\n");  // Print error message
        exit(1);           // Exit with error code
    }
    else if (pid3 == 0)    // If this is the third child process
    {
        printf("Process ID is: %d\n", getpid());  // Print child's process ID
        exit(0);           // Child exits with success
    }
    else                   // Parent process reaches here after all forks
    {
        wait(NULL);        // Wait for first child to terminate
        wait(NULL);        // Wait for second child to terminate
        wait(NULL);        // Wait for third child to terminate
        exit(0);           // Parent exits with success
    }
}

