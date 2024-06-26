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

int main()
{
    struct node *p = createnode(18);
    struct node *p1 = createnode(19);
    struct node *p2 = createnode(3);
    p->left = p2;
    p->right = p1;
    insertnode(p, 4);
    preorder(p);
    return 0;
}