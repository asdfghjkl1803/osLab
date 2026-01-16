#include <stdio.h>

int main()
{
    int p[20], wt[20], tat[20];
    float bt[20];
    int i, j, n;
    float temp;
    int itemp;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        p[i] = i;
        printf("Enter Burst Time for Process P%d: ", i);
        scanf("%f", &bt[i]);
    }

    int p_sorted[20];
    float bt_sorted[20];
    for (i = 0; i < n; i++)
    {
        p_sorted[i] = p[i];
        bt_sorted[i] = bt[i];
    }

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (bt_sorted[i] > bt_sorted[j])
            {
                temp = bt_sorted[i];
                bt_sorted[i] = bt_sorted[j];
                bt_sorted[j] = temp;

                itemp = p_sorted[i];
                p_sorted[i] = p_sorted[j];
                p_sorted[j] = itemp;
            }

    float wt_sorted[20], tat_sorted[20];
    wt_sorted[0] = 0;
    tat_sorted[0] = bt_sorted[0];

    for (i = 1; i < n; i++)
    {
        wt_sorted[i] = wt_sorted[i - 1] + bt_sorted[i - 1];
        tat_sorted[i] = wt_sorted[i] + bt_sorted[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (p[i] == p_sorted[j])
            {
                wt[i] = wt_sorted[j];
                tat[i] = tat_sorted[j];
                break;
            }
        }
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%.2f\t\t%.2f\t\t%.2f\n", p[i], bt[i], (float)wt[i], (float)tat[i]);

    printf("\nAverage Waiting Time = %.2f", wtavg / n);
    printf("\nAverage Turnaround Time = %.2f", tatavg / n);

    return 0;
}
