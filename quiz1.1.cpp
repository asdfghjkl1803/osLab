#include <stdio.h>      
#include <stdlib.h>   
#include <unistd.h>     
#include <sys/wait.h>  

int main(int argc, char *arg[])
{
    int pid1, pid2, pid3;  

    pid1 = fork();         

    if (pid1 < 0)          
    {
        printf("fork failed\n"); 
        exit(1);         
    }
    else if (pid1 == 0)     
    {
        printf("Process ID is: %d\n", getpid()); 
        exit(0);        
    }
    
    pid2 = fork();      

    if (pid2 < 0)       
    {
        printf("fork failed\n");
        exit(1);       
    }
    else if (pid2 == 0) 
    {
        printf("Process ID is: %d\n", getpid());
        exit(0);        
    }
    
    pid3 = fork(); 

    if (pid3 < 0)  
    {
        printf("fork failed\n"); 
        exit(1);   
    }
    else if (pid3 == 0) 
    {
        printf("Process ID is: %d\n", getpid()); 
        exit(0);   
    }
    else            
    {
        wait(NULL); 
        wait(NULL);
        wait(NULL); 
        exit(0);    
    }
}
