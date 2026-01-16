
// Program: Shortest Job First (SJF) CPU Scheduling Algorithm
// This program calculates waiting time and turnaround time for processes using SJF scheduling

// Include standard input/output library
#include <stdio.h>

// Main function
int main()
{
    // Arrays to store process numbers, waiting times, and turnaround times
    int p[20], wt[20], tat[20];
    // Array to store burst times (execution time) for each process
    float bt[20];
    // Variables for loop counters and temporary storage
    int i, j, n;
    // Temporary variable for sorting burst times
    float temp;
    // Temporary variable for sorting process numbers
    int itemp;
    // Variables to store average waiting time and turnaround time
    float wtavg = 0, tatavg = 0;

    // Prompt user to enter number of processes
    printf("Enter the number of processes: ");
    // Read the number of processes
    scanf("%d", &n);

    // Loop to initialize process numbers and read burst times
    for (i = 0; i < n; i++)
    {
        // Assign process number (0, 1, 2, ... n-1)
        p[i] = i;
        // Prompt user to enter burst time for current process
        printf("Enter Burst Time for Process P%d: ", i);
        // Read burst time for process
        scanf("%f", &bt[i]);
    }

    // Create sorted arrays for processes and burst times
    int p_sorted[20];
    float bt_sorted[20];
    // Copy original data to sorted arrays
    for (i = 0; i < n; i++)
    {
        p_sorted[i] = p[i];
        bt_sorted[i] = bt[i];
    }

    // Bubble sort: arrange processes in ascending order of burst time
    for (i = 0; i < n - 1; i++)
        // Inner loop for comparing adjacent elements
        for (j = i + 1; j < n; j++)
            // If current burst time is greater than next burst time, swap
            if (bt_sorted[i] > bt_sorted[j])
            {
                // Swap burst times
                temp = bt_sorted[i];
                bt_sorted[i] = bt_sorted[j];
                bt_sorted[j] = temp;

                // Swap corresponding process numbers
                itemp = p_sorted[i];
                p_sorted[i] = p_sorted[j];
                p_sorted[j] = itemp;
            }

    // Arrays to store waiting times and turnaround times for sorted processes
    float wt_sorted[20], tat_sorted[20];
    // First process has zero waiting time
    wt_sorted[0] = 0;
    // Turnaround time = waiting time + burst time
    tat_sorted[0] = bt_sorted[0];

    // Calculate waiting time and turnaround time for remaining processes
    for (i = 1; i < n; i++)
    {
        // Waiting time = previous waiting time + previous burst time
        wt_sorted[i] = wt_sorted[i - 1] + bt_sorted[i - 1];
        // Turnaround time = waiting time + burst time
        tat_sorted[i] = wt_sorted[i] + bt_sorted[i];
    }

    // Map sorted results back to original process order
    for (i = 0; i < n; i++)
    {
        // Find position of original process in sorted array
        for (j = 0; j < n; j++)
        {
            // If process matches
            if (p[i] == p_sorted[j])
            {
                // Assign waiting time from sorted array
                wt[i] = wt_sorted[j];
                // Assign turnaround time from sorted array
                tat[i] = tat_sorted[j];
                break;
            }
        }
        // Add waiting time to total
        wtavg += wt[i];
        // Add turnaround time to total
        tatavg += tat[i];
    }

    // Print table header
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    // Print details for each process
    for (i = 0; i < n; i++)
        printf("P%d\t%.2f\t\t%.2f\t\t%.2f\n", p[i], bt[i], (float)wt[i], (float)tat[i]);

    // Print average waiting time
    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    // Print average turnaround time
    printf("\nAverage Turnaround Time = %.2f", tatavg / n);

    // Return 0 to indicate successful program execution
    return 0;
}