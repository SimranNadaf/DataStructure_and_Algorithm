#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    int *arr;
};

int isFull(struct stack *s){
    if(s->top==s->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}



int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack *s,int val){
    if(!isFull(s)){
        s->top++;
        s->arr[s->top]=val;
    }
    else{
        printf("Stack is OverFlow !\n");
    }
    
}
int pop(struct stack *s){
    if(!isEmpty(s)){
        s->top--;
        return s->arr[s->top+1];
    }
    else{
        printf("Stack is UnderFlow !\n");
        return -1;
    }
    
}

int peek(struct stack *s, int position){
    int arrayInd=s->top - position + 1;
    if((isEmpty) && (arrayInd < 0)){
        printf("Invalid Position or Empty Stack\n");
    }
    else{
        return s->arr[arrayInd];
    }
}

int stackTop(struct stack *s){
    if(!isEmpty(s))
        return s->arr[s->top];
}

int stackBottom(struct stack *s){
    if(!isEmpty(s))
        return s->arr[0];
}

int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=50;
    s->arr=(int *)malloc(sizeof(int) * s->size);

    
    printf("Before, Stack is full : %d\n",isFull(s));
    printf("Before, Stack is Empty : %d\n",isEmpty(s));
   
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    push(s,70);
    
    printf("The Top Most Element of this Stack is %d\n",stackTop(s));
    printf("The Bottom Most Element of this Stack is %d\n",stackBottom(s));

    // for(int j=1; j<=s->top +1; j++)
    // printf("%d position of elememt of stack is %d\n",j,peek(s,j));

    // printf("Poped element from Stack :%d\n",pop(s));
    // printf("Poped element from Stack :%d\n",pop(s));
    
    printf("After, Stack is full : %d\n",isFull(s));
    printf("After, Stack is Empty : %d\n",isEmpty(s));
    
    return 0;

}