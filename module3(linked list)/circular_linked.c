
#include <stdio.h>
#include <stdlib.h>

// creating a structure
struct Node
{
    int data;
    struct Node *next;
};

void linkedlisttraversal(struct Node *head)
{
    struct Node * ptr = head;
    do{
        printf("element is %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
   
}

struct Node * insert_at_head(struct Node* head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node * p = head->next;
    while(p->next != head){
        p = p->next;
    }

    p->next = ptr;
    ptr ->next = head;
    head = ptr;

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
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 6;
    third->next = fourth;

    fourth->data = 1;
    fourth->next = head;

    printf("list before insertion\n");
    linkedlisttraversal(head);

    head = insert_at_head(head,88);

    printf("\nlist after insertion\n");
    linkedlisttraversal(head);

    return 0;
}