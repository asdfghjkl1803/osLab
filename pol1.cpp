#include <stdio.h>

int main()
{
    int bt[20], rem_bt[20], wt[20], tat[20];
    int i, n, tq, time = 0;
    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while (1)
    {
        int done = 1;

        for (i = 0; i < n; i++)
        {
            switch (rem_bt[i] > 0)
            {
            case 1:
                done = 0;

                switch (rem_bt[i] > tq)
                {
                case 1:
                    time += tq;
                    rem_bt[i] -= tq;
                    break;

                case 0:
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                    break;
                }
                break;

            case 0:
                break;
            }
        }

        if (done)
            break;
    }

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
