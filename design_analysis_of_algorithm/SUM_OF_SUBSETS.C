#include <stdio.h>
#include <conio.h>

int w[10], x[10], n, target;

void subset(int sum,int k){
    if(sum==target){
        for(int i=1;i<=n;i++)
            if(x[i]==1) printf("%d ",w[i]);
        printf("\n");
        return;
    }

    if(k>n || sum>target) return;

    x[k]=1;
    subset(sum+w[k],k+1);

    x[k]=0;
    subset(sum,k+1);
}

void main(){
    clrscr();

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);

    printf("Enter target sum: ");
    scanf("%d",&target);

    subset(0,1);

    getch();
}