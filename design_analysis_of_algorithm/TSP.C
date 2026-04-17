#include <stdio.h>
#include <conio.h>
#include <limits.h>

#define SIZE 10

int n;
int dist[SIZE][SIZE];
int dp[1024][SIZE];

int min(int a,int b){
    if(a<b) return a;
    else return b;
}

int tsp(int mask,int pos){
    int city,ans=INT_MAX;

    if(mask==(1<<n)-1)
        return dist[pos][0];

    if(dp[mask][pos]!=-1)
        return dp[mask][pos];

    for(city=0;city<n;city++){
        if((mask&(1<<city))==0){
            int newAns=dist[pos][city]+tsp(mask|(1<<city),city);
            ans=min(ans,newAns);
        }
    }

    dp[mask][pos]=ans;
    return ans;
}

void main(){
    int i,j,result;

    clrscr();

    printf("Enter number of cities: ");
    scanf("%d",&n);

    printf("Enter distance matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&dist[i][j]);

    for(i=0;i<1024;i++)
        for(j=0;j<SIZE;j++)
            dp[i][j]=-1;

    result=tsp(1,0);

    printf("Minimum travelling cost = %d",result);

    getch();
}