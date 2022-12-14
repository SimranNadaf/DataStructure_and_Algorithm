// Creating empty stack
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void traversal(struct stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("Element = %d\n", s->arr[i]);
    }
}

int main()
{

 
    // struct stack s;
    // s.top=-1;
    // s.size=100;
    // s.arr=(int *)malloc(sizeof(int)*s.size);

    struct stack *s;
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    // Manually adding elements in stack array
    // s->arr[0]=1;
    // s->top++;
    // s->arr[1]=2;
    // s->top++;

    traversal(s);

    int result = isFull(s);
    if (result == 1)
    {
        printf("Stack is Full\n");
    }
    else
    {
        printf("Stack is not Full\n");
    }

    result = isEmpty(s);
    if (result == 1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is not Empty\n");
    }

    return 0;
}