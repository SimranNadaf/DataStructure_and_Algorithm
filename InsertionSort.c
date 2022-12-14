#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void insertionSort(int *A, int n)
{
    int key, j;
    // loop for passes
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

int main()
{
    int A[] = {2, 4, 8, 12, 0, 1};
    int n = 6;
    printf("Before Sorting \n");
    printArray(A, n);
    insertionSort(A, n);
    printf("After Sorting \n");
    printArray(A, n);
    return 0;
}