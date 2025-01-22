#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
    struct node * prev;   
};

void doubley_traversal(struct node * ptr){
    while(ptr != NULL){
        printf("element is %d\n", ptr->data);
        ptr=ptr->next;
    }
    
}

void doubley_traversal_left(struct node * ptr){

    while(ptr->next != NULL){
        // printf("element is %d \n", ptr->data);
        ptr=ptr->next;
    }

    while(ptr != NULL){
        printf("left element is %d \n",ptr->data);
        ptr = ptr->prev;
    }
}

int main(){
    struct node * head;
    struct node * second;
    struct node * third;
    struct node * fourth;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    //linking the nodes
    head->data = 4;
    head->next= second;
    head -> prev = NULL;

    second->data = 6;
    second->next= third;
    second -> prev = head;

    third->data = 8;
    third->next= fourth;
    third -> prev = second;

    fourth->data = 7;
    fourth->next= NULL;
    fourth -> prev = third;

    printf("doubley linked list traversal to right\n");
    doubley_traversal(head);


    printf("\ndoubley linked list traversal to left\n");
    doubley_traversal_left(head);
}