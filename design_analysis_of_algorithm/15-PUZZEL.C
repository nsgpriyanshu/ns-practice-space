#include <stdio.h>
#include <conio.h>

int goal[4][4] = {
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,0}
};

int h(int a[4][4])
{
    int i,j,count=0,k=1;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(a[i][j]!=0 && a[i][j]!=k)
                count++;
            k++;
        }
    return count;
}

void main()
{
    int a[4][4], i, j;

    clrscr();

    printf("Enter initial state:\n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            scanf("%d",&a[i][j]);

    printf("Heuristic (misplaced tiles) = %d", h(a));

    getch();
}