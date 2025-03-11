#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

//creating binary tree
struct node * binaryTree(){
    int x;
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }

    //creating a temporary node to store the left and right values of parent node
    struct node * temp = createnode(x);

    printf("enter the left child of %d\n", x);
    temp->left = binaryTree();

    printf("enter the right child of %d\n",x);
    temp->right = binaryTree();
    return temp;
}

int main(){
    printf("enter the data of root node (-1 for NULL)\n");
    struct node * root = NULL;
    root = binaryTree();

}