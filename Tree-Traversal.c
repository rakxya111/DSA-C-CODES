#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};
struct node *newnnode(int num)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = num;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        printf("%d\t", root->data);
        postorder(root->right);
    }
}

int main()
{

    struct node *p = newnnode(14);
    struct node *p1 = newnnode(16);
    struct node *p2 = newnnode(4);
    // Linking the root node with left and right children
    p->left = p2;
    p->right = p1;
    preorder(p);
    printf("\n");
    postorder(p);
    printf("\n");
    inorder(p);
    return 0;
}