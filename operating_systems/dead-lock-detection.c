#include<stdio.h>
#include<conio.h>

void main() {
    int allocation[10][10],request[10][10];
    int available[10],work[10],finish[10];
    int deadlock[10];
    int numberOfProcesses,numberOfResources;
    int i,j,k,count=0,found,deadlockCount=0;

    clrscr();

    printf("DEADLOCK DETECTION ALGORITHM\n");
    printf("----------------------------\n");

    printf("\nEnter number of processes: ");
    scanf("%d",&numberOfProcesses);

    printf("Enter number of resource types: ");
    scanf("%d",&numberOfResources);

    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<numberOfProcesses;i++) {
        for(j=0;j<numberOfResources;j++) {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\nEnter Request Matrix:\n");
    for(i=0;i<numberOfProcesses;i++) {
        for(j=0;j<numberOfResources;j++) {
            scanf("%d",&request[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i=0;i<numberOfResources;i++) {
        scanf("%d",&available[i]);
    }

    for(i=0;i<numberOfResources;i++) {
        work[i]=available[i];
    }

    for(i=0;i<numberOfProcesses;i++) {
        finish[i]=0;
    }

    while(count<numberOfProcesses) {
        found=0;

        for(i=0;i<numberOfProcesses;i++) {
            if(finish[i]==0) {
                for(j=0;j<numberOfResources;j++) {
                    if(request[i][j]>work[j]) {
                        break;
                    }
                }

                if(j==numberOfResources) {
                    for(k=0;k<numberOfResources;k++) {
                        work[k]=work[k]+allocation[i][k];
                    }

                    finish[i]=1;
                    count++;
                    found=1;
                }
            }
        }

        if(found==0) {
            break;
        }
    }

    for(i=0;i<numberOfProcesses;i++) {
        if(finish[i]==0) {
            deadlock[deadlockCount]=i;
            deadlockCount++;
        }
    }

    printf("\n----------------------------\n");

    if(deadlockCount==0) {
        printf("NO DEADLOCK DETECTED");
    } else {
        printf("DEADLOCK DETECTED\n");
        printf("Deadlocked Processes: ");

        for(i=0;i<deadlockCount;i++) {
            printf("P%d ",deadlock[i]);
        }
    }

    getch();
}