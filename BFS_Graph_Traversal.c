#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct Queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is OverFlow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is UnderFlow\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct Queue q;
    q.size = 100;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    //BFS implementation
    int node;
    int i=0; // starting node
    int visited[7] = {0,0,0,0,0,0,0}; // visited array 
    int a[7][7]={
     {0,1,1,1,0,0,0},//0
     {1,0,1,0,0,0,0},//1
     {1,1,0,1,0,0,0},//2
     {1,0,1,0,1,0,0},//3
     {0,0,1,1,0,1,1},//4
     {0,0,0,0,1,0,0},//5
     {0,0,0,0,1,0,0}//6
    }; // given graph representation in adjacency matrix

    printf("%d ",i);
    visited[i] = 1;
    enqueue(&q, i);

    while(!isEmpty(&q)){
        node=dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d ",j);
                enqueue(&q,j);
                visited[j] = 1;
            }
        }
        
    }

    return 0;
}