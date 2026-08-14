#include<stdio.h>
#include<conio.h>

void main()
{
    int at[20], bt[20], rt[20], wt[20], tat[20], ct[20];
    int gantt[100], gtime[101];
    int n, i, time = 0, complete = 0;
    int shortest, min, g = 0;
    float awt = 0, atat = 0;

    clrscr();

    printf("Enter Number of Processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter Arrival Time of P%d: ",i+1);
        scanf("%d",&at[i]);

        printf("Enter Burst Time of P%d: ",i+1);
        scanf("%d",&bt[i]);

        rt[i]=bt[i];
    }

    while(complete<n)
    {
        shortest=-1;
        min=9999;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && rt[i]>0)
            {
                if(rt[i]<min)
                {
                    min=rt[i];
                    shortest=i;
                }
            }
        }

        if(shortest==-1)
        {
            if(g==0 || gantt[g-1]!=-1)
            {
                gantt[g]=-1;
                gtime[g]=time;
                g++;
            }
            time++;
            continue;
        }

        if(g==0 || gantt[g-1]!=shortest)
        {
            gantt[g]=shortest;
            gtime[g]=time;
            g++;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest]==0)
        {
            complete++;
            ct[shortest]=time;
            tat[shortest]=ct[shortest]-at[shortest];
            wt[shortest]=tat[shortest]-bt[shortest];

            if(wt[shortest]<0)
                wt[shortest]=0;
        }
    }

    gtime[g]=time;

    printf("\n\nSJF Preemptive (SRTF) Gantt Chart\n\n");

    printf(" ");
    for(i=0;i<g;i++)
        printf("-------");
    printf("-\n|");

    for(i=0;i<g;i++)
    {
        if(gantt[i]==-1)
            printf(" ID  |");
        else
            printf(" P%d  |",gantt[i]+1);
    }

    printf("\n ");
    for(i=0;i<g;i++)
        printf("-------");
    printf("-\n");

    for(i=0;i<=g;i++)
        printf("%-7d",gtime[i]);

    printf("\n\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],ct[i],wt[i],tat[i]);

        awt += wt[i];
        atat += tat[i];
    }

    printf("\nAverage Waiting Time    = %.2f",awt/n);
    printf("\nAverage Turnaround Time = %.2f",atat/n);

    getch();
}