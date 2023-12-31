#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    if (i >= j)
    {
        temp = A[j];
        A[j] = A[low];
        A[low] = temp;
    }

    return j;
}

void QuickSort(int A[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        QuickSort(A, partitionIndex + 1, high);
        QuickSort(A, low, partitionIndex - 1);
    }
}

int main()
{
    int A[] = {5, 8, 1, 2, 7, 10, 6, 4, 3, 9};
    int n = 10;
    printf("Before Quick Sorting \n");
    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printf("After Quick Sorting \n");
    printArray(A, n);
    return 0;
}