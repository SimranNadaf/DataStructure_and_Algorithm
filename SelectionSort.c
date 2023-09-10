#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void SelectonSort(int *A, int n)
{
    printf("Selection sort is Running ......\n");
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{

    int A[] = {12, 5, 2, 0, 4};
    int n = 5;
    printArray(A, n);
    SelectonSort(A, n);
    printArray(A, n);
    return 0;
}