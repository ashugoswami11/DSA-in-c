#include <stdio.h>
#include <stdlib.h>

//creating a structure to make linked list nodes
struct Node{
    int data;
    struct Node*Next;
};

void linkedlisttraversal(struct Node * ptr){
    while(ptr != NULL){
    printf("%d\n", ptr->data);
    ptr=ptr->Next;
    }

}
int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    //memory allocation for these linked list in the heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));

    //linking of nodes

    head->data = 7;
    head->Next = second;

    second->data = 8;
    second->Next = third;

    third->data = 9;
    third->Next = NULL ;

    linkedlisttraversal(head);

return 0;
}