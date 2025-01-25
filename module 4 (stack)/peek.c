#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isfull(ptr))
    {
        printf("stack is overflowed\n ");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("stack is underflowed\n ");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrayind = ptr->top - i + 1;
    if (arrayind < 0)
    {
        printf("not a valid position for the\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayind];
    }
}

int stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stackbottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 89); // first element
    push(s, 56);
    push(s, 78);
    push(s, 99);
    push(s, 33); // last element

    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("the value at the position %d is %d\n", i, peek(s, i));
    }

    printf("the value at the top is %d \n", stacktop(s));
    printf("the value at the bottom is %d \n", stackbottom(s));

    return 0;
}
