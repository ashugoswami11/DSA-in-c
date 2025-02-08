#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stacktop(struct stack *bucket)
{
    return bucket->arr[bucket->top];
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

char *infixtopostfix(char *infix)
{
    // here we create a stack to store operators it is a part of stack
    struct stack *opbucket;
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
    char *infix = "a*b-c/d+l(k*m)";

    return 0;
}