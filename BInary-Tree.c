// implementation of binary search tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create()
{
    struct node *newnode;
    int d;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d", &d);
    if (d == -1) // -1 means NULL
    {
        return 0;
    }
    newnode->data = d;
    printf("Enter the left child of root %d : ", d);
    newnode->left = create(); // recursive function used
    printf("Enter the right child of the root %d : ", d);
    newnode->right = create();
    return newnode;
}

int main()
{
    struct node *root;
    root = NULL;
    root = create();
    return 0;
}
