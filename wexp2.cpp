#include <stdio.h>  

int main()
{
    int bt[20], wt[20], tat[20];   // Arrays to store burst time, waiting time, and turnaround time
    int i, n;                      // Loop counter and number of processes
    float wtavg = 0, tatavg = 0;  // Variables to store average waiting and turnaround times

    printf("Enter the number of processes: ");
    scanf("%d", &n);              // Read number of processes from user

    // Input burst times for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i); 
        scanf("%d", &bt[i]);       // Store burst time for process i
    }

    // Initialize first process: waiting time is 0, turnaround time is burst time
    wt[0] = 0;                    
    tat[0] = bt[0];              

    // Calculate waiting and turnaround times for remaining processes
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];   // Waiting time = previous process's waiting time + its burst time
        tat[i] = tat[i - 1] + bt[i];     // Turnaround time = previous turnaround time + current burst time
    }

    // Sum up all waiting and turnaround times for average calculation
    for (i = 0; i < n; i++)
    {
        wtavg += wt[i];            // Accumulate waiting times
        tatavg += tat[i];          // Accumulate turnaround times
    }

    // Print table header
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    // Print process details
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i, bt[i], wt[i], tat[i]); // Display process number, burst time, waiting time, turnaround time
    }

    // Print average times
    printf("\nAverage Waiting Time: %.2f", wtavg / n);        // Average waiting time = total / number of processes
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);  // Average turnaround time = total / number of processes

    return 0;   // End program successfully
}