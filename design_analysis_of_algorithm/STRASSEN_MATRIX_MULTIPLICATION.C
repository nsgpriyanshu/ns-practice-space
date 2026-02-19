#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int** allocateMatrix(int n);
void addMatrix(int **A, int **B, int **C, int n);
void multiplyMatrix(int **A, int **B, int **C, int n);
void printMatrix(int **M, int n);

int** allocateMatrix(int n)
{
    int **mat;
    int i;

    mat = (int**)malloc(n * sizeof(int*));
    for(i = 0; i < n; i++)
        mat[i] = (int*)malloc(n * sizeof(int));

    return mat;
}

void addMatrix(int **A, int **B, int **C, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void multiplyMatrix(int **A, int **B, int **C, int n)
{
    int i, j;
    int half;

    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **C11, **C12, **C21, **C22;
    int **T1, **T2;

    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    half = n / 2;

    A11 = allocateMatrix(half);
    A12 = allocateMatrix(half);
    A21 = allocateMatrix(half);
    A22 = allocateMatrix(half);

    B11 = allocateMatrix(half);
    B12 = allocateMatrix(half);
    B21 = allocateMatrix(half);
    B22 = allocateMatrix(half);

    C11 = allocateMatrix(half);
    C12 = allocateMatrix(half);
    C21 = allocateMatrix(half);
    C22 = allocateMatrix(half);

    T1 = allocateMatrix(half);
    T2 = allocateMatrix(half);

    for(i = 0; i < half; i++)
    {
        for(j = 0; j < half; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+half];
            A21[i][j] = A[i+half][j];
            A22[i][j] = A[i+half][j+half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+half];
            B21[i][j] = B[i+half][j];
            B22[i][j] = B[i+half][j+half];
        }
    }

    multiplyMatrix(A11, B11, T1, half);
    multiplyMatrix(A12, B21, T2, half);
    addMatrix(T1, T2, C11, half);

    multiplyMatrix(A11, B12, T1, half);
    multiplyMatrix(A12, B22, T2, half);
    addMatrix(T1, T2, C12, half);

    multiplyMatrix(A21, B11, T1, half);
    multiplyMatrix(A22, B21, T2, half);
    addMatrix(T1, T2, C21, half);

    multiplyMatrix(A21, B12, T1, half);
    multiplyMatrix(A22, B22, T2, half);
    addMatrix(T1, T2, C22, half);

    for(i = 0; i < half; i++)
    {
        for(j = 0; j < half; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j+half] = C12[i][j];
            C[i+half][j] = C21[i][j];
            C[i+half][j+half] = C22[i][j];
        }
    }
}

void printMatrix(int **M, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void main()
{
    int **A, **B, **C;
    int n, i, j;

    clrscr();

    printf("Enter matrix size (2 or 4 recommended): ");
    scanf("%d", &n);

    A = allocateMatrix(n);
    B = allocateMatrix(n);
    C = allocateMatrix(n);

    printf("Enter elements of matrix A:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    multiplyMatrix(A, B, C, n);

    printf("Resultant matrix:\n");
    printMatrix(C, n);

    getch();
}
