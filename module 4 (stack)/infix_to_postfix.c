#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isfull(struct stack * bucket){
    if(bucket->top == bucket->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int stacktop(struct stack *bucket)
{
    return bucket->arr[bucket->top];
}

void push(struct stack * bucket, char val){
    if(isfull(bucket)){
        printf("stack is overflowed can't push elements \n");
    }
    else{
        bucket->top++;
        bucket->arr[bucket->top] = val;
    }
}

int isempty(struct stack *bucket)
{
    if (bucket->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char pop(struct stack * bucket){
    if(isempty(bucket)){
        printf("stack si underflowed can't pop from an empty stack\n");
    }
    else{
        char val = bucket->arr[bucket->top];
        bucket->top--;
        return val;
    }
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
        return 3;

    else if (ch == '+' || ch == '-')
        return 2;

    else
    {
        return 0;
    }
}

int isoperator(char ch)
{
    if(ch == '*' || ch == '/' || ch == '-' || ch == '+'){
        return 1;
    }
    else{
        return 0;
    }
}

char *infixtopostfix(char *infix)
{
    // here we create a stack to store operators it is a part of stack
    struct stack *opbucket = (struct stack *)malloc(sizeof(struct stack));
    opbucket->size = 100;
    opbucket->top = -1;
    opbucket->arr = (char *)malloc(opbucket->size * sizeof(char));

    // postfix expression is not a part of stack just a simple array to store the infix to postfix converted expression
    char *postfix = (char *)malloc(strlen(infix) + 1 * sizeof(char));
    int i = 0; // it will track the infix elements
    int j = 0; // it will track the prefix elements

    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(opbucket)))
            {
                push(opbucket, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(opbucket);
                j++;
            }
        }
    }
    while (!isempty(opbucket))
    {
        postfix[j] = pop(opbucket);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a*b-c/d+l*k*m";
    printf("postfix is %s", infixtopostfix(infix));
    return 0;
}