/*Write a c program to take input number in A2×2 and B2×2 matrix. Find the sum of A and B and store in C2×2 matrix. Print A, B and C*/
#include <stdio.h>

void inputMatrix(int A[2][2])
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}

void addMatrix(int A[2][2], int B[2][2], int C[2][2])
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void printMatrix(int A[2][2])
{
    int i, j;

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int A[2][2], B[2][2], C[2][2];

    printf("Enter elements of Matrix A:\n");
    inputMatrix(A);

    printf("Enter elements of Matrix B:\n");
    inputMatrix(B);

    addMatrix(A, B, C);

    printf("\nMatrix A:\n");
    printMatrix(A);

    printf("\nMatrix B:\n");
    printMatrix(B);

    printf("\nMatrix C (A + B):\n");
    printMatrix(C);

    return 0;
}