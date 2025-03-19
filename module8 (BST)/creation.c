#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

//-----------Traversals-----------
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    printf("%d", root->data);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    preorder(root->left);
    preorder(root->right);
    printf("%d", root->data);
}

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct node *bst_tree()
{
    int x;
    scanf("%d", &x);

    if (x == -1)
    {
        return NULL;
    }

    struct node *temp = createnode(x);
    printf("enter the left child of a %d\n", x);
    temp->left = bst_tree();

    printf("enter the right child of a %d\n", x);
    temp->right = bst_tree();

    return temp;
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            {
                return 0;
            }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node * search(struct node * root, int key)
{
    if(root == NULL){
        return NULL;
    }
    if(key == root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left,key);
    }
}

int main()
{
    printf("enter a root node(-1 for NULL)\n");
    struct node *root = NULL;
    root = bst_tree();

    printf("pre-order traversal\n");
    preorder(root);

    // Print In-order traversal
    printf("\nIn-order traversal:\n");
    inorder(root);

    // Print Post-order traversal
    printf("\nPost-order traversal:\n");
    postorder(root);

    int answer = isBST(root);
    if(answer == 1){
        printf("yes this is a binary tree\n");
    }
    else{
        printf("no this is not a binary tree\n");
    }

    struct node * n = search(root,5);
    if(n != NULL){
        printf("found : %d", n->data);
    }
    else{
        printf("element not found");
    }

    return 0;
}
