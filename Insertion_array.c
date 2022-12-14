#include<stdio.h>

void display(int arr[], int n)
{
    //Travelsal Array
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");
}

int indInsertion(int arr[],int index, int element, int size, int capacity){
    //Insertion Operation of Array
    if(size>=capacity){
        return -1;
    }
    for(int i=size+1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}

int indDeletion(int arr[], int size, int index){
    //Deletion Operation of Array
    if(size==0){
        return -1;
    }
    for(int i=index; i<size-1; i++){
        arr[i]=arr[i+1];
    }
    return 1;
}

int main(){
    int arr[100]={1,2,3,4,5};
    int size=5,capacity=100,index=3,element=12;
    display(arr, size);
    // int a=indInsertion(arr,index,element,size,capacity);
    // if(a==-1){
    //     printf("Array is Over-Flow !! Can't insert element to array");
    // }
    // else if(a==1){
    //     size++;
    //     display(arr,size);
    // }

    int b=indDeletion(arr,size,index);
    if(b==-1){
        printf("Array is UnderFlow !! Can not Delete Element of Array...");
    }
    else if(b==1){
        size-=1;
        display(arr,size);
    }
        
    

    
    return 0;
}