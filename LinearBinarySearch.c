#include<stdio.h>

    int LinearSearch(int arr[],int size,int element){
        for(int i=0;i<size;i++){
            if(arr[i]==element){
                return i;
            }
        }
        return -1;
    }

    int BinarySearch(int arr[],int size, int element){
        int low=0;
        int high=size-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==element){
                return mid;
            }
            else if(arr[mid]<element){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;

    }

int main(){
    int arr[]={1,22,39,6,8,9,22,77,90};
    int size=sizeof(arr)/sizeof(int);
    int element=1;
    // int SearchIndex=BinarySearch(arr,size,element);
    int SearchIndex=LinearSearch(arr,size,element);
    if(SearchIndex!=-1){
        printf("The Element %d was Found at index %d .",element,SearchIndex);
    }
    else{
        printf("The Element %d was Not Found",element);
    }
    
    return 0;
}