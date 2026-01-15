#include <stdio.h>   // Header file for input and output functions

int main()
{
    int bt[20], wt[20], tat[20];   // Arrays for Burst Time, Waiting Time, and Turnaround Time
    int i, n;                      // i for loop counter, n for number of processes
    float wtavg = 0, tatavg = 0;   // Variables to store total waiting and turnaround times

    /* Input number of processes */
    printf("Enter the number of processes: ");
    scanf("%d", &n);               // Read number of processes

    /* Input burst time for each process */
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i); // Ask burst time
        scanf("%d", &bt[i]);        // Store burst time in array
    }

    /* First process */
    wt[0] = 0;                     // First process has zero waiting time
    tat[0] = bt[0];                // Turnaround time = burst time for first process

    /* Calculate waiting time and turnaround time for remaining processes */
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];   // Waiting time = previous waiting + previous burst
        tat[i] = tat[i - 1] + bt[i];     // Turnaround time = previous turnaround + current burst
    }

    /* Calculate total waiting time and turnaround time */
    for (i = 0; i < n; i++)
    {
        wtavg += wt[i];            // Add all waiting times
        tatavg += tat[i];          // Add all turnaround times
    }

    /* Display table header */
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    /* Display process details */
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i, bt[i], wt[i], tat[i]); // Print process info
    }

    /* Display average times */
    printf("\nAverage Waiting Time: %.2f", wtavg / n);       // Average waiting time
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n); // Average turnaround time

    return 0;   // End of program
}
