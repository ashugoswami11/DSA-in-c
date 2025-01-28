#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linktraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element is %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isempty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull(struct node *top)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        free(ptr);
        return 0;
    }
}

struct node *push(struct node *top, int val)
{
    if (isfull(top))
    {
        printf("stack is overflowed\n");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = val;
        p->next = top;
        top = p;
        return top;
    }
}

struct node *pop(struct node *top)
{
    if (isempty(top))
    {
        printf("stack is underflowed\n");
    }
    else
    {
        struct node *n = top;
        top = top->next;
        int val = n->data;
        printf("the popped element is %d\n", val);
        free(n);
        return top;
    }
}

int main()
{

    struct node *top = NULL;

    top = push(top, 32);
    top = push(top, 78);
    top = push(top, 390);
    top = push(top, 66);

    printf("stack before popping the element\n");
    linktraversal(top);

    top = pop(top);

    printf("stack after popping the element\n");

    linktraversal(top);

    return 0;
}