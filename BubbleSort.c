#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void BubblesortAdaptive(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("Pass : %d \n", i + 1);
        int isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // for comparasions of each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            // break;
            return;
        }
    }
}

void Bubblesort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("Pass : %d \n", i + 1);

        for (int j = 0; j < n - 1 - i; j++) // for comparasions of each pass
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int A[] = {7, 14, 2, 6, 13, 3};
    // int A[] = {1, 2, 4, 6, 8, 10};
    int n = 6;
    printArray(A, n);
    Bubblesort(A, n);
    // BubblesortAdaptive(A, n);
    printArray(A, n);
    return 0;
}