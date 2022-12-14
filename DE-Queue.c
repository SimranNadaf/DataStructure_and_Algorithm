#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int f;
    int r;
    int size;
    int* arr;
};

int isFull(struct Queue *q){
    if(q->r == q->size-1){
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enQueueR(struct Queue *q, int val){
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->r++;
        q->arr[q->r]=val;
        printf("Enqueued element form rear : %d\n",val);
    } 
}

void enQueueF(struct Queue *q, int val){
    if((q->f==-1) && (q->r == q->size-1)){
        printf("Queue is Full\n");
    }
    else{
        if( q->r == -1){
            q->arr[q->f+1]=val;
        }
        q->arr[q->f]=val;
        q->f--;
        printf("Enqueued element form front : %d\n",val);
    }
}

int deQueueF(struct Queue *q){
    int n=-1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        q->f++;
        n=q->arr[q->f];
    }
    return n;
}

int deQueueR(struct Queue *q){
    int n=-1;
    if(isEmpty(q)){
        printf("Queue is Empty\n");
    }
    else{
        n=q->arr[q->r];
        q->r--;
    }
    return n;
}

void traversal(struct Queue *q){
    for(int i=0;i<q->size;i++){
        printf("Element : %d \n",q->arr[i]);
    }
}

int main(){
    struct Queue q;
    q.size=4;
    q.r=q.f=-1;
    q.arr=(int *)malloc(sizeof(int) * q.size);

    enQueueR(&q,12);
    enQueueR(&q,10);
    enQueueR(&q,8);
    enQueueR(&q,0);
    deQueueF(&q);
    deQueueF(&q);
    // printf("dequeued element from rear %d \n",deQueueR(&q));
    // printf("dequeued element from front %d \n",deQueueF(&q));
    // // printf("dequeued element from front %d \n",deQueueF(&q));
    traversal(&q);
    

//Problem with enQueueF() -- solve tomorrow 10/12/2022

    return 0;
}