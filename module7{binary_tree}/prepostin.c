#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};

//---------------------traversals -----------------------
void preorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    printf(" %d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node * root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf(" %d ", root->data);
    inorder(root->right);
}

void postorder(struct node * root)
{
    if (root == NULL)
    {
        return; 
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d ", root->data);
}

struct node * create_node(int data)
{
    struct node * n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n ;
}

struct node * binaryTree()
{
    int x;
    scanf("%d", &x);

    if(x == -1){
        return NULL;
    }

    struct node * temp = create_node(x);
    printf("enter the left child of %d\n", x);
    temp->left = binaryTree();

    printf("enter the right child of %d\n", x);
    temp->right = binaryTree();
    
    return temp;
}

int main(){
    printf("enter the root node(-1 for NULL)\n");
    struct node * root = NULL;
    root = binaryTree();

    printf("pre-order traversal\n");
    preorder(root);
    
    // Print In-order traversal
    printf("\nIn-order traversal:\n");
    inorder(root);

    // Print Post-order traversal
    printf("\nPost-order traversal:\n");
    postorder(root);
}