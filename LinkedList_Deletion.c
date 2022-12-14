#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Display All Elements of Linked List
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The Element is %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Deleting Head Node of Linked List
struct Node *DeletionFirstNode(struct Node *head)
{
    struct Node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Deletion of Node with given index of Linked List
// It Not Working for Index 0
struct Node *DeletionAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    struct Node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

// Deletion of Last Node of Linked List
struct Node *DeletionLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q;
    while (p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = NULL;
    free(p);
    return head;
}

// Deletion Of Node with given value, search it then delete it.
struct Node *DeletionOfNode(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *q = head;
    while (p->data != data && p->next != NULL)
    {
        q = p;
        p = p->next;
    }
    if (p->data == data)
    {
        q->next = p->next;
        free(p);
    }
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // link first Node and second Node
    head->data = 12;
    head->next = second;

    // link second Node and thirth Node
    second->data = 22;
    second->next = third;

    // link thirth Node and fourth Node
    third->data = 42;
    third->next = fourth;

    // link fourth Node and fifth Node
    fourth->data = 82;
    fourth->next = fifth;

    // link fifth node and NULL
    fifth->data = 100;
    fifth->next = NULL;

    printf("\n Linked List before Deletion\n");
    linkedListTraversal(head);

    // head = DeletionFirstNode(head);
    // head = DeletionAtIndex(head,2);
    // head = DeletionLastNode(head);
    head = DeletionOfNode(head,22);

    printf("\n Linked List After Deletion\n");
    linkedListTraversal(head);
    return 0;
}