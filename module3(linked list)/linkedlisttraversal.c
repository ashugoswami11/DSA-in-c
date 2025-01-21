
#include <stdio.h>
#include <stdlib.h>

// creating a structure
struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    // creating nodes of structure but they are ultimately pointers pointing towards memory locations available in the heap
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // linking the nodes
    head->data = 7;
    head->next = second;

    second->data = 89;
    second->next = third;

    third->data = 76;
    third->next = fourth;

    fourth->data = 64;
    fourth->next = NULL;

    linkedlisttraversal(head);

    return 0;
}