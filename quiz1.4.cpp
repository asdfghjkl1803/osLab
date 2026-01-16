#include <stdio.h>   

int main()
{
    float bt[20], rem_bt[20], wt[20], tat[20];  

    int i, n, time = 0;
    float tq;  

    float wtavg = 0, tatavg = 0;  

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%f", &bt[i]);    
        rem_bt[i] = bt[i];      
        wt[i] = 0;              
    }

    printf("Enter Time Quantum: ");
    scanf("%f", &tq);

    while (1)
    {
        int done = 1;  

        for (i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)   
            {
                done = 0;        

                if (rem_bt[i] > tq)   
                {
                    time += tq;       
                    rem_bt[i] -= tq; 
                }
                else   
                {
                    time += rem_bt[i];        
                    wt[i] = time - bt[i];     
                    rem_bt[i] = 0;           
                }
            }
        }

        if (done == 1)  
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
        printf("P%d\t%.2f\t\t%.2f\t\t%.2f\n", i, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wtavg / n);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg / n);

    return 0;  
}

