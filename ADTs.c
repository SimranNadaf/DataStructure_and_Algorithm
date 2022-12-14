#include<stdio.h>
#include<stdlib.h>

    struct myArray{
       int total_size;
       int used_size;
       int * ptr;
    };
    void createArray(struct myArray *a, int tsize, int usize){
        // (*a).total_size=tsize;
        // (*a).used_size=usize;
        // (*a).ptr=(int *) malloc (tsize * sizeof(int));

        a->total_size=tsize;
        a->used_size=usize;
        a->ptr=(int *) malloc (tsize * sizeof(int));
    }
    void setval(struct myArray *a){
        for(int i=0;i<(a->used_size);i++){
            printf("Enter %d Index Element :",i);
            scanf("%d",&(a->ptr)[i]);
        }

    }
    void show(struct myArray *a){
        for(int i=0;i<(a->used_size);i++){
            printf("%d index Element : %d\n",i,(a->ptr)[i]);
        }
    }

int main(){
    struct myArray demo; 
    createArray(&demo,20,5);
    setval(&demo);
    show(&demo);
    
    return 0;
}