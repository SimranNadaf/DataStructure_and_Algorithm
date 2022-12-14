#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void Traversal(struct Node* top){

    while(top != NULL){
        printf("Element is :%d\n",top->data);
        top=top->next;
    }
}

int isFull(struct Node *n){
    struct Node *sp=(struct Node*)malloc(sizeof(struct Node));
    if(sp==NULL){
        printf("Stack Overfull\n");
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Node *n){
    if(n==NULL){
        printf("Stack Underflow\n");
        return 1;
    }
    else{
        return 0;
    }
}

struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node *n=(struct Node*)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node *n=(*top);
        (*top)=n->next;
        int x=n->data;
        free(n);
        return x;
    }
}

// //  Global Variable, so you can use top variable direct in function
// struct Node *top=NULL;

// int pop(struct Node* tp){
//     if(isEmpty(tp)){
//         printf("Stack Underflow\n");
//     }
//     else{
//         struct Node *n=tp;
//         top=n->next;
//         int x=n->data;
//         free(n);
//         return x;
//     }
// }


int peek(struct Node* top,int pos){
    struct Node* ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
}

int stackTop(struct Node* top){
    return top->data;
}
int stackBottom(struct Node* top){
    struct Node* ptr=top;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr->data;
}
int main(){

    struct Node *top=NULL;
    
    top=push(top,1);
    top=push(top,2);
    top=push(top,3);
    top=push(top,4);
    top=push(top,5);


    Traversal(top);
    
    // int element1=pop(top);
    // printf("Popped Element is %d\n",element1);
    // int element2=pop(top);
    // printf("Popped Element is %d\n",element2);
    // int element3=pop(top);
    // printf("Popped Element is %d\n",element3);

    // Traversal(top);
    for(int j=1;j<=5;j++){
        printf("%d position element of stack is %d\n",j,peek(top,j));
    }
        printf("%d position element of stack is %d\n",6,peek(top,6));
    
    printf("The Top Most Element of Stack is %d\n",stackTop(top));
    printf("The Bottom Most Element of Stack is %d\n",stackBottom(top));

    return 0;
}