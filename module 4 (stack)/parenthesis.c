#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isempty(struct stack * ptr)
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

int isfull(struct stack * ptr)
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

void push(struct stack * ptr, char value){
    if(isfull(ptr)){
        printf("the stack is overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("stack is underflowed\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int parenthesis_match(char *expression)
{
    struct stack *p;
    p->size = 100;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            push(p, '(');
        }
        else if (expression[i] == ')')
        {
            if (isempty(p)){
                return 0;
            }
            else{
                pop(p);
            }
        }
    }

    if (isempty(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

    int main(){
        //checking if parenthesis are matching or not

        char * exp = "8*23-76(654/66)(89*&";

        if(parenthesis_match(exp)){
            printf("parenthesis are matching\n");
        }
        else{
            printf("parenthesis are not matching\n");
        }

    }
   