#include <stdio.h>
#include <stdlib.h>

//blueprint to create a node
struct node{
    int data;
    struct node * left;
    struct node * right;
};

//method to create a node
struct node * createnode(int data){
    struct node * n;
    n = (struct node*)malloc (sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node * binaryTree(){
    int x;
    scanf("%d",&x);

    if (x == -1)
    {
        return NULL;
    }

    struct node * temp = createnode(x);
    //left side create
    printf("enter the left child of %d\n",x);
    temp->left = binaryTree();

    //right side create
    printf("enter the right child of %d\n",x);
    temp->right = binaryTree();
    return temp;

}

int main(){
    printf("Enter the value for the root node (-1 for NULL)\n");
    struct node * root = NULL;
    root = binaryTree(); 
}