#include <stdio.h>
#include <conio.h>

int x[10], n;

int place(int k,int i){
    for(int j=1;j<k;j++)
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
            return 0;
    return 1;
}

void nqueen(int k){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                for(int j=1;j<=n;j++)
                    printf("%d ",x[j]);
                printf("\n");
            }
            else nqueen(k+1);
        }
    }
}

void main(){
    clrscr();
    printf("Enter number of queens: ");
    scanf("%d",&n);
    nqueen(1);
    getch();
}