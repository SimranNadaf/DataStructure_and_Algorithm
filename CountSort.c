#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int Max(int *A, int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}
void CountSort(int *A, int n)
{
    int max = INT_MIN;
    max = Max(A, n);
    int *B = (int *)malloc(sizeof(int) * max + 1);

    // initialize array B with 0
    for (int i = 0; i <= max; i++)
    {
        B[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        B[A[i]] = B[A[i]] + 1;
    }

    int i = 0; // couter for couter array (B)
    int j = 0; // couter for given array (A)

    for (i = 0; i <= max; i++)
    {

        while (B[i] > 0)
        {
            A[j] = i;
            j++;
            B[i] = B[i] - 1;
        }
    }
}

int main()
{
    int A[] = {2, 12, 4, 8, 12, 1, 22, 11, 0};
    int n=9
    ;
    printArray(A, n);
    CountSort(A, n);
    printArray(A, n);

    return 0;
}