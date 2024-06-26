#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int d)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = d;
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

void insertnode(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    struct node *new = createnode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
struct node * inOrderPredecessor(struct node *root)
{
    root = root->left;
    while(root->right!=NULL)
    {
        root = root->right;
    }
        return root;
}
struct node *deletenode(struct node *root,int value)
{
    struct node *inpre;
    if(root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right==NULL)
    {
        free(root);
        return NULL;
    }
    if(value < root->data)
    {
        root->left = deletenode(root->left,value);
    }
    else if(value > root->data)
    {
        root->right = deletenode(root->right,value);
    }
    else
    {
        inpre = inOrderPredecessor(root);
        root->data = inpre->data;
        root->left = deletenode(root->left,inpre->data);

    }
    return root;
}
int main()
{
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createnode(5);
    struct node *p1 = createnode(3);
    struct node *p2 = createnode(6);
    struct node *p3 = createnode(1);
    struct node *p4 = createnode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    //insertnode(p, 4);
    preorder(p);
    printf("\n");
    deletenode(p, 3);
    preorder(p);
    return 0;
}