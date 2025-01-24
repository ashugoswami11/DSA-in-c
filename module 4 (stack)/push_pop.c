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

void push(struct stack *ptr, int value)
{
    if (isfull(ptr))
    {
        printf("stack is overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("stack is empty!\n");
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }

}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s,67);
    push(s,45);
    push(s,598);
    push(s,77);
    push(s,91);

    printf("the element which is popped is %d\n", pop(s));
    printf("the element which is popped is %d\n", pop(s));
    printf("the element which is popped is %d\n", pop(s));
    printf("the element which is popped is %d\n", pop(s));
    printf("the element which is popped is %d\n", pop(s));
    printf("the element which is popped is %d\n", pop(s));
    printf("the element which is popped is %d\n", pop(s));

}