#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

char stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

void push(struct stack *ptr, int val){
    if(!isFull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
    else{
        printf("Stack Overflow\n");
    }
}

char pop(struct stack *ptr){
    if(!isEmpty(ptr)){
        char x=ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }
    else{
       printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
}

int precedence(char ch){
    if(ch=='/' || ch=='*'){
        return 3;
    }
    else if(ch=='+' || ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}

int isOperator(char ch){
    if(ch=='/' || ch=='*' || ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

char * InfixToPostfix(char * infix){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->top=-1;
    sp->size=100;
    sp->arr=(char *)malloc(sp->size * sizeof(char));

    char * postfix=(char *)malloc(strlen(infix) * sizeof(char));
    int i=0;
    int j=0;

    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stackTop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isEmpty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[i]='\0';
    return postfix;
}
int main(){

    char * infix="a*b+c";
    printf("PostFix : %s\n",InfixToPostfix(infix));
    return 0;
}