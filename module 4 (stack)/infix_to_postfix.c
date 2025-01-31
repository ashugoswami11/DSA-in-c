#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

char stacktop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

char *infix_to_postfix(char *infix)
{

    // creating a stack to store the operators
    struct stack *opbucket = (struct stack *)malloc(sizeof(struct stack));
    opbucket->size = 100;
    opbucket->top = -1;
    opbucket->arr = (char *)malloc(opbucket->size * sizeof(char));

    // now i have to make a postfix (a character *  arry) to store the expression after it start converting from infix to postfix
    // it is not associated with stack
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0;
    int j = 0;

    // starting the loop and saying unless the arr[i]th position is not equal to the null iterate it
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
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
}

int main()
{
    char *infix = "a*b(j/n)-k+l";

    infix_to_postfix(infix);

    return 0;
}