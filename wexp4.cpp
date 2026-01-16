 // Include standard input/output library
#include <stdio.h>   

// Main function
int main()
{
    // Declare arrays to store burst time, remaining burst time, waiting time, and turnaround time
    float bt[20], rem_bt[20], wt[20], tat[20];  

    // Declare loop variable i, number of processes n, current time, and time quantum tq
    int i, n, time = 0;
    float tq;  

    // Declare variables to store average waiting time and average turnaround time
    float wtavg = 0, tatavg = 0;  

    // Prompt user to enter number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Loop through each process to get burst time
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%f", &bt[i]);    
        rem_bt[i] = bt[i];      // Initialize remaining burst time with burst time
        wt[i] = 0;              // Initialize waiting time to 0
    }

    // Prompt user to enter time quantum for round robin scheduling
    printf("Enter Time Quantum: ");
    scanf("%f", &tq);

    // Main scheduling loop
    while (1)
    {
        int done = 1;           // Flag to check if all processes are completed

        // Check each process in round robin fashion
        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)   // If process still has burst time remaining
            {
                done = 0;        // Mark that at least one process is not done

                if (rem_bt[i] > tq)   // If remaining time exceeds time quantum
                {
                    time += tq;       // Add time quantum to current time
                    rem_bt[i] -= tq;  // Reduce remaining burst time by time quantum
                }
                else   // If remaining time is less than or equal to time quantum
                {
                    time += rem_bt[i];        // Add remaining time to current time
                    wt[i] = time - bt[i];     // Calculate waiting time
                    rem_bt[i] = 0;            // Mark process as completed
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1)  
            break;     
    }

    // Calculate turnaround time and accumulate averages
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];   // Turnaround time = burst time + waiting time
        wtavg += wt[i];           // Sum all waiting times
        tatavg += tat[i];         // Sum all turnaround times
    }

    // Print table header
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    // Print results for each process
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%.2f\t\t%.2f\t\t%.2f\n", i, bt[i], wt[i], tat[i]);
    }

    // Print average waiting time
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    // Print average turnaround time
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    // Return 0 to indicate successful execution
    return 0;  
}

