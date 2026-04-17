#include <stdio.h>
#include <conio.h>

int g[10][10], x[10], n, m;

char *colors[] = {"","Red","Green","Blue","Yellow","Orange"};

int place(int k, int i)
{
    int j;
    for(j = 1; j <= n; j++)
    {
        if(g[k][j] == 1 && x[j] == i)
            return 0;
    }
    return 1;
}

void color(int k)
{
    int i, j;

    for(i = 1; i <= m; i++)
    {
        if(place(k, i))
        {
            x[k] = i;

            if(k == n)
            {
                for(j = 1; j <= n; j++)
                    printf("V%d-%s ", j, colors[x[j]]);
                printf("\n");
            }
            else
                color(k + 1);
        }
    }
}

void main()
{
    int i, j;

    clrscr();

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }

    printf("Enter number of colors: ");
    scanf("%d", &m);

    color(1);

    getch();
}