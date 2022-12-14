#include <stdio.h>
#include <stdlib.h>

struct Node *f;
struct Node *r;

struct Node
{
    int data;
    struct Node *next;
};

void TravelLinkedList()
{
    struct Node *ptr = f;
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
void enqueue(int val)
{
    struct Node *n;
    n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int n = -1;
    struct Node *ptr = f;
    if (f == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        f = f->next;
        n = ptr->data;
        free(ptr);
    }
    return n;
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    printf("Dequeued Element : %d\n", dequeue());
    printf("Dequeued Element : %d\n", dequeue());

    TravelLinkedList();

    return 0;
}