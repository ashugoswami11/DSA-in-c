#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data)
{
    struct node * n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node * insert_into_bst(struct node * root, int data)
{
    if(root == NULL){
        root = create_node(data);
        return root;
    }

    if(data>root->data){
        root->right = insert_into_bst(root->right,data);
    }
    else{
        root->left = insert_into_bst(root->left,data);
    }
    return root;

}

struct node * takeinput(struct node** root)
{
    int data;
    scanf("%d", &data);

    while(data != -1)
    {
        root = insert_into_bst(root, data);
        scanf("%d",&data);
    }

}

void inorder(struct node* root) {
    if (root == NULL) {
        return; // Base case: Stop if NULL
    }
    inorder(root->left); // Visit left subtree
    printf("%d ", root->data); // Print current node
    inorder(root->right); // Visit right subtree
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct node* root) {
    if (root == NULL) {
        return; // Base case: Stop if NULL
    }
    printf("%d ", root->data); // Print current node
    preorder(root->left); // Visit left subtree
    preorder(root->right); // Visit right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct node* root) {
    if (root == NULL) {
        return; // Base case: Stop if NULL
    }
    postorder(root->left); // Visit left subtree
    postorder(root->right); // Visit right subtree
    printf("%d ", root->data); // Print current node
}

int main() {
    struct node* root = NULL; // Start with an empty tree

    printf("Enter data to create a BST (-1 to stop):\n");
    root = takeinput(root); // Build the BST

    // Perform and print different tree traversals
    printf("\nInorder Traversal (Sorted Order):\n");
    inorder(root);

    printf("\nPreorder Traversal (Root First):\n");
    preorder(root);

    printf("\nPostorder Traversal (Root Last):\n");
    postorder(root);

    return 0;
}