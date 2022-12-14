#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr!= NULL)
    
    {
        printf("The Element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // link first node and second node
    head->data = 12;
    head->next = second;

    // link first node and second node
    second->data = 22;
    second->next = third;

    // link first node and second node
    third->data = 42;
    third->next = fourth;

    // link first node and second node
    fourth->data = 82;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
}