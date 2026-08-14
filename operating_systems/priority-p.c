#include<stdio.h>
#include<conio.h>

void main()
{
    int at[20], bt[20], rt[20], pr[20];
    int wt[20], tat[20], ct[20];
    int n, i, time=0, completed=0;
    int highest, minPriority;
    float avgwt=0, avgtat=0;

    clrscr();

    printf("PREEMPTIVE PRIORITY SCHEDULING\n");

    printf("\nEnter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nProcess P%d\n",i+1);

        printf("Arrival Time : ");
        scanf("%d",&at[i]);

        printf("Burst Time : ");
        scanf("%d",&bt[i]);

        printf("Priority : ");
        scanf("%d",&pr[i]);

        rt[i]=bt[i];
    }

    printf("\n\nGANTT CHART\n");

    while(completed<n)
    {
        highest=-1;
        minPriority=9999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(pr[i]<minPriority)
                {
                    minPriority=pr[i];
                    highest=i;
                }
            }
        }

        if(highest==-1)
        {
            printf("| Idle ");
            time++;
            continue;
        }

        printf("| P%d ",highest+1);

        rt[highest]--;
        time++;

        if(rt[highest]==0)
        {
            completed++;
            ct[highest]=time;
        }
    }

    printf("|\n");

    for(i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];

        avgwt+=wt[i];
        avgtat+=tat[i];
    }

    printf("\nProcess\tAT\tBT\tPriority\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);

    getch();
}