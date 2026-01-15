#include <stdio.h>

int main()
{
    int bt[20], wt[20], tat[20], pr[20];
    int i, j, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &bt[i]);

        printf("Enter Priority for Process %d: ", i);
        scanf("%d", &pr[i]);
    }

    /* Sorting using switch instead of if */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            switch (pr[i] > pr[j])
            {
            case 1:
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                break;

            case 0:
                break;
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
    }

    for (i = 0; i < n; i++)
    {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i, pr[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;
}
