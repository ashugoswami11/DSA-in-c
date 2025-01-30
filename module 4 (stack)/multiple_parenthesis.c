#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

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

void push(struct stack *expression, char value)
{
    if (isfull(expression))
    {
        printf("sorry the stack is overflowed\n");
    }
    else
    {
        expression->top++;
        expression->arr[expression->top] = value;
    }
}

int pop(struct stack *expression)
{
    if (isempty(expression))
    {
        return 0;
    }
    else
    {
        char val = expression->arr[expression->top];
        expression->top--;
        return val;
    }
}

int match(char a, char b)
{
    if((a == '{' && b == '}') ||
         (a == '[' && b == ']') ||
         (a == '<' && b == '>') ||
         (a == '(' && b == ')'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int parenthesischeck(char *expression)
{
    // a stack to store the bracket as characters
    struct stack *bucket;
    bucket->top = -1;
    bucket->size = 100;
    bucket->arr = (char *)malloc(bucket->size * sizeof(char));
    char popped_char;

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[' || expression[i] == '<')
        {
            push(bucket, expression[i]);
        }
        else if ((expression[i] == ')' || expression[i] == '}' || expression[i] == ']' || expression[i] == '>'))
        {
            if (isempty(bucket))
            {
                return 0;
            }
            else
            {
                popped_char = pop(bucket);
                if (!match(popped_char, expression[i]))
                {
                    return 0;
                }
            }
        }
    }
    if (isempty(bucket))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *expression = "3*43(4+4){>(435)8745-4";
    if (parenthesischeck(expression))
    {
        printf("the expression contains balanced parenthesis\n");
    }
    else
    {
        printf("the expression not contains balanced parenthesis\n");
    }
}