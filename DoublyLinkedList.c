#include<stdio.h>
#include<stdlib.h>

struct Node{
        int data;
        struct Node *next;
        struct Node *prev;
    };

void Traversal(struct Node *head){
    struct Node *p=head;
    printf("Forward Direction List\n");
    while(p->next!=NULL){
        printf("Element = %d \n",p->data);
        p=p->next;
    }
    printf("Element = %d \n",p->data);
    printf("\n");
    printf("Backward Direction List\n");
    while(p!=NULL){
        printf("Element = %d \n",p->data);
        p=p->prev;
    }
}
int main(){
    struct Node *N1;
    struct Node *N2;
    struct Node *N3;
    struct Node *N4;
    N1=(struct Node *)malloc(sizeof(struct Node));
    N2=(struct Node *)malloc(sizeof(struct Node));
    N3=(struct Node *)malloc(sizeof(struct Node));
    N4=(struct Node *)malloc(sizeof(struct Node));

    N1->prev=NULL;
    N1->data=1;
    N1->next=N2;

    N2->prev=N1;
    N2->data=2;
    N2->next=N3;

    N3->prev=N2;
    N3->data=3;
    N3->next=N4;

    N4->prev=N3;
    N4->data=4;
    N4->next=NULL;

    Traversal(N1);

    return 0;
}