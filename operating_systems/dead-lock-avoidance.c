#include<stdio.h>
#include<conio.h>

void main() {
    int allocation[10][10],maximum[10][10],need[10][10];
    int available[10],work[10];
    int finish[10];
    int safeSequence[10];
    int n,m;
    int i,j,k,count=0;
    int found;

    clrscr();

    printf("BANKER'S ALGORITHM - DEADLOCK AVOIDANCE\n");
    printf("---------------------------------------\n");

    printf("\nEnter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resource types: ");
    scanf("%d",&m);

    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d",&maximum[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i=0;i<m;i++) {
        scanf("%d",&available[i]);
    }

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            need[i][j]=maximum[i][j]-allocation[i][j];
        }
    }

    printf("\nNeed Matrix:\n");

    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++) {
        work[i]=available[i];
    }

    for(i=0;i<n;i++) {
        finish[i]=0;
    }

    while(count<n) {
        found=0;

        for(i=0;i<n;i++) {
            if(finish[i]==0) {
                for(j=0;j<m;j++) {
                    if(need[i][j]>work[j]) {
                        break;
                    }
                }

                if(j==m) {
                    for(k=0;k<m;k++) {
                        work[k]=work[k]+allocation[i][k];
                    }

                    safeSequence[count]=i;
                    count++;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(found==0) {
            break;
        }
    }

    printf("\n---------------------------------------\n");

    if(count==n) {
        printf("SYSTEM IS IN SAFE STATE\n");
        printf("\nSafe Sequence:\n");

        for(i=0;i<n;i++) {
            printf("P%d",safeSequence[i]);

            if(i!=n-1) {
                printf(" -> ");
            }
        }
    } else {
        printf("SYSTEM IS NOT IN SAFE STATE\n");
        printf("Deadlock may occur.\n");
    }

    getch();
}