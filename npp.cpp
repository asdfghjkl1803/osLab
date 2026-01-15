#include <stdio.h>   // Header file for input and output functions

int main()
{
    int bt[20], wt[20], tat[20], pr[20];
    // bt = burst time, wt = waiting time
    // tat = turnaround time, pr = priority

    int i, j, n, temp;
    // i, j = loop counters
    // n = number of processes
    // temp = temporary variable for swapping

    float wtavg = 0, tatavg = 0;
    // Variables to store total waiting time and turnaround time

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);      // Store burst time

        printf("Enter Priority for Process %d: ", i);
        scanf("%d", &pr[i]);      // Store priority
    }

    // Sort processes based on priority (Non-Preemptive)
    // Lower number means higher priority
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])    // Compare priorities
            {
                // Swap priorities
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // Swap burst times to match priority order
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // First process
    wt[0] = 0;            // First process has no waiting time
    tat[0] = bt[0];       // Turnaround time equals burst time

    // Calculate waiting time and turnaround time for remaining processes
    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];   // Waiting time calculation
        tat[i] = tat[i - 1] + bt[i];     // Turnaround time calculation
    }

    // Calculate total waiting and turnaround times
    for (i = 0; i < n; i++)
    {
        wtavg += wt[i];     // Add waiting time
        tatavg += tat[i];   // Add turnaround time
    }

    // Display table header
    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");

    // Display process details
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               i, pr[i], bt[i], wt[i], tat[i]);
    }

    // Display average waiting time and turnaround time
    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;   // End of program
}
