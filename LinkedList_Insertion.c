#include<stdio.h>
#include<stdlib.h>

struct Node{
        int data;
        struct Node *next;
    };

void Traversal(struct Node *ptr){
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;

    }
}

struct Node * InsertAtHead(struct Node *head,int data){

    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=head;
    return ptr;
}

//InsertionAtIndex() is not Working for index 0
struct Node * InsertionAtIndex(struct Node *head,int data, int index){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;
    int i=0;

    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    p->next=ptr;

    return head; 
}

struct Node * InsertionAtEnd(struct Node *head,int data){
    struct Node *ptr=(struct Node * )malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node *p=head;

    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;

    return head;
}

struct Node * InsertionAfterNode(struct Node *head,struct Node *preNode,int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    ptr->next=preNode->next;
    preNode->next=ptr;

    return head;
}

    

int main(){

    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=50;
    fourth->next=NULL;
    
    printf("\nLinked List Before Insertion\n");
    Traversal(head);

    // head=InsertAtHead(head,40);
    // head=InsertionAtIndex(head,44,1);
    // head=InsertionAtEnd(head,44);
    head=InsertionAfterNode(head,second,22);


    printf("\nLinked List After Insertion\n");
    Traversal(head);

    
    return 0;
}