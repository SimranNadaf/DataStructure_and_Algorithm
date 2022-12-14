
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Traversal(struct Node *head)
{

    struct Node *p = head;
    do
    {
        printf("Element is %d\n", p->data);
        p = p->next;

    } while (p != head);
}

struct Node *InsertionAtHead(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    ptr->next = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;

    return ptr;
}

struct Node *InsertionAtIndex(struct Node *head, int data, int index)
{
    int i = 0;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (i != (index - 1))
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *InsertionAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

struct Node *InsertionAfterNode(struct Node *head, struct Node *p, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;

    return head;
}
int main()
{
    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;
    head = (struct Node *)malloc(sizeof(struct Node));
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 10;
    head->next = first;
    first->data = 20;
    first->next = second;
    second->data = 30;
    second->next = third;
    third->data = 40;
    third->next = head;

    printf("\nCircular Linked List Before Insertion \n");
    Traversal(head);
    head = InsertionAfterNode(head, second, 100);
    printf("\nCircular Linked List After Insertion \n");
    Traversal(head);

    return 0;
}