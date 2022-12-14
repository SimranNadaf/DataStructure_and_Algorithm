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

void push(struct stack *ptr, char val){
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
        return -1;
    }
}

int Match(char top,char exp){
    if(top=='(' && exp==')'){
        return 1;
    }
    if(top=='[' && exp==']'){
        return 1;
    }
    if(top=='{' && exp=='}'){
        return 1;
    }
    return 0;
}

int ParenthiesisMatch(char * exp){
    // craete and initialize stack
    struct stack *sp;
    sp->top=-1;
    sp->size=100;
    sp->arr=(char *)malloc(sp->size * sizeof(char));

    for(int i=0;exp[i]!='\0';i++){

        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(sp,exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(Match(sp->arr[sp->top],exp[i]) && !(isEmpty(sp))){
                pop(sp);
            }
            else{
                return 0;
            }
        } 
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){

    char * exp="{[(1+2)*(1*3)]/[(1+2)*(1*3)]}";

    if(ParenthiesisMatch(exp)){
       printf("Parenthesis of Expression is Valid\n");  
    }
    else{
        printf("Parenthesis of Expression is Invalid\n");  

    }
    
    return 0;
}