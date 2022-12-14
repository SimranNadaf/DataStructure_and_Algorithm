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
        printf("Enqueued element : %d\n",val);
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
    q.size = 3;
    q.r = q.f = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Dequeue element is : %d\n", dequeue(&q));
    printf("Dequeue element is : %d\n", dequeue(&q));
    printf("Dequeue element is : %d\n", dequeue(&q));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }

    if (isFull(&q))
    {
        printf("Queue is Full\n");
    }

    return 0;
}