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

// deleting the first element in the linked list
struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// deleting the indexed element in the linked list
struct Node *delete_index(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);

    return head;
}

// delete the last node
struct Node *delete_last(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
    
};

// deleting the given node element in the linked list
struct Node *delete_value(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }

    return head;
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

    printf("linked list before deletion\n ");
    linkedlisttraversal(head);

    // head = deletefirst(head);
    // head = delete_index(head, 2);
    // head = delete_last(head);
    head = delete_value(head,76);

    printf("linked list after deletion\n");
    linkedlisttraversal(head);

    return 0;
}