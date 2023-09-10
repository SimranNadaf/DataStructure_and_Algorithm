#include<stdio.h>

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d  ",A[i]);
    }
    printf("\n");
}

void Merge(int *A, int low, int mid, int high){

    int i,j,k;
    int B[100];
    i=low;
    j=mid + 1;
    k=low;

    while ( i <= mid && j <= high)
    {
        if(A[i] < A[j]){
            B[k] = A[i];
            k++; i++;
        }
        else{
            B[k] = A[j];
            k++; j++;
        }
    }

    while(i <= mid){
        B[k] = A[i];
        k++; i++;
    }
    
    while( j <= high ){
        B[k] = A[j];
        k++; j++;
    }

    for (int i = 0; i <= high ; i++)
    {
        A[i] = B[i];
    }
    

}

void MergeSort(int *A, int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}

int main(){

    int A[]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    printArray(A, n);
    MergeSort(A, 0, 9);
    printArray(A, n);
    return 0;
}