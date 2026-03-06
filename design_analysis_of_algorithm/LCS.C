#include <stdio.h>
#include <conio.h>
#include <string.h>

#define SIZE 20

void main()
{
    char X[SIZE], Y[SIZE], lcs[SIZE];
    int m, n, i, j, index;
    int L[SIZE][SIZE];

    clrscr();

    printf("Enter first string: ");
    scanf("%s", X);

    printf("Enter second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
            {
                if(L[i-1][j] > L[i][j-1])
                    L[i][j] = L[i-1][j];
                else
                    L[i][j] = L[i][j-1];
            }
        }
    }

    printf("\nLCS Matrix:\n");

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
            printf("%d ", L[i][j]);
        printf("\n");
    }

    index = L[m][n];
    lcs[index] = '\0';

    i = m;
    j = n;

    while(i > 0 && j > 0)
    {
        if(X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }
        else if(L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    printf("\nLength of LCS = %d", L[m][n]);
    printf("\nLCS = %s", lcs);

    getch();
}