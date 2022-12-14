#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *ptr,char val){
    if(isFull(ptr)){
        printf("Stack is Overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack UnderFlow\n");
        return -1;
    }
    else{
        char x=ptr->arr[ptr->top];
        ptr->top--;
        return x;
    }

}

int paranthesisMatch(char *exp){
    struct stack *ptr;
    ptr->top=-1;
    ptr->size=100;
    ptr->arr=(char *)malloc(ptr->size * sizeof(char));

    for(int i=0; exp[i]!='\0'; i++){
        if(exp[i] == '('){
            push(ptr,exp[i]);
        }
        else if(exp[i] == ')'){
            if(isEmpty(ptr)){
                return 0;
            }
            pop(ptr);
        }
    }
    if(isEmpty(ptr)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    
    char * exp = "(2*3)-(3/5))";
    if(paranthesisMatch(exp)){
        printf("The Parenthesis is Matching...\n");
    }
    else{
        printf("The Parenthesis is not Matching...\n");
    }
    return 0;
}