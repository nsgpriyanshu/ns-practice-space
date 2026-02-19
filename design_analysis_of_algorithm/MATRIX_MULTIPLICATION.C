#include <stdio.h>
#include <conio.h>

void main()
{
    int A[10][10], B[10][10], C[10][10];
    int rowA, colA, rowB, colB;
    int i, j, k;

    clrscr();

    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &rowA, &colA);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &rowB, &colB);

    if (colA != rowB)
    {
        printf("Matrix multiplication not possible.");
        getch();
        return;
    }

    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < rowA; i++)
    {
        for (j = 0; j < colA; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < rowB; i++)
    {
        for (j = 0; j < colB; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < rowA; i++)
    {
        for (j = 0; j < colB; j++)
        {
            C[i][j] = 0;
        }
    }

    for (i = 0; i < rowA; i++)
    {
        for (j = 0; j < colB; j++)
        {
            for (k = 0; k < colA; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    printf("\nResultant Matrix:\n");
    for (i = 0; i < rowA; i++)
    {
        for (j = 0; j < colB; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    getch();
}
