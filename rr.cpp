#include <stdio.h>   // Header file for input and output

int main()
{
    int bt[20], rem_bt[20], wt[20], tat[20];  
    // bt = burst time, rem_bt = remaining burst time
    // wt = waiting time, tat = turnaround time

    int i, n, tq, time = 0;  
    // i = loop counter
    // n = number of processes
    // tq = time quantum
    // time = current CPU time

    float wtavg = 0, tatavg = 0;  
    // Variables to store total waiting and turnaround times

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);     // Store burst time
        rem_bt[i] = bt[i];       // Set remaining burst time equal to burst time
        wt[i] = 0;               // Initialize waiting time to zero
    }

    // Input time quantum
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Scheduling Algorithm
    while (1)
    {
        int done = 1;  
        // Flag to check if all processes are finished

        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)   // If process still has burst time left
            {
                done = 0;        // At least one process is not finished

                if (rem_bt[i] > tq)   // If remaining time is greater than time quantum
                {
                    time += tq;       // Increase current time by time quantum
                    rem_bt[i] -= tq;  // Reduce remaining burst time
                }
                else   // If remaining time is less than or equal to time quantum
                {
                    time += rem_bt[i];        // Add remaining time to total time
                    wt[i] = time - bt[i];     // Calculate waiting time
                    rem_bt[i] = 0;            // Process is finished
                }
            }
        }

        if (done == 1)   // If all processes are finished
            break;       // Exit the loop
    }

    // Calculate turnaround time and total averages
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];   // Turnaround time = burst time + waiting time
        wtavg += wt[i];           // Add waiting time to total
        tatavg += tat[i];         // Add turnaround time to total
    }

    // Display output table
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    // Display average waiting and turnaround times
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;   // End of program
}
