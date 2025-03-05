#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node* n; //creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); //allocating memory in the heap
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(){
    // struct node* p;
    // p = (struct node*)malloc(sizeof(struct node));
    // p->data = 2;
    // p->left = NULL;
    // p->right = NULL;

    // struct node* p1;
    // p1 = (struct node*)malloc(sizeof(struct node));
    // p1->data = 1;
    // p1->left = NULL;
    // p1->right = NULL;

    // struct node* p2;
    // p2 = (struct node*)malloc(sizeof(struct node));
    // p2->data = 4;
    // p2->left = NULL;
    // p2->right = NULL;

    // p->left = p1;
    // p->right = p2;

    //<----------- now instead of doing above we can simply call the function to crate nodes--------------->
    struct node*p = createnode(8);
    struct node*p1 = createnode(4);
    struct node*p2 = createnode(6);

    p->left = p1;
    p->right = p2;

    return 0;
}