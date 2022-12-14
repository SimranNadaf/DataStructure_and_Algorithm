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

// Does Not Work For for 1 element Circular Linked List...
struct Node * DeletionAtHead(struct Node *head){
    struct Node *p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=head->next;
    free(head);

    return p->next;
}

// Does Not Work for 0th Index...
struct Node * DeletionAtIndex(struct Node *head,int index){
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;

}

// Does Not Work For for 1 element Circular Linked List...
struct Node * DeletionAtEnd(struct Node *head){
    struct Node *p=head;
    struct Node *q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);

    return head;
}

// Does Not Work for Head Node
struct Node * DeletionOfNode(struct Node *head,struct Node *q){
    struct Node *p=head;
    while(p->next!=q){
        p=p->next;
    }
    p->next=q->next;
    free(q);

    return head;
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

    printf("\nCircular Linked List Before Deletion \n");
    Traversal(head);

    head=DeletionOfNode(head,second);
    
    
    printf("\nCircular Linked List After Deletion \n");
    Traversal(head);

    return 0;
}