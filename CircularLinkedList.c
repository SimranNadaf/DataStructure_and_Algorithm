#include<stdio.h>
#include<stdlib.h>

struct Node{
        int data;
        struct Node *next;
    };

void Traversal(struct Node *head){

    struct Node *p=head;
    do
    {
        printf("Element is %d\n",p->data);
        p=p->next;


    }while(p!=head);
}
int main(){

    struct Node *head;
    struct Node *first;
    struct Node *second;
    struct Node *third;

    head=(struct Node *)malloc(sizeof(struct Node));
    first=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    head->next=first;

    first->data=20;
    first->next=second;
    
    second->data=30;
    second->next=third;
    
    third->data=40;
    third->next=head;

    Traversal(head);

    return 0;
}