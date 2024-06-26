#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right, *left;
};
struct node *newnnode(int num)
{
    struct node *new; // creating a node pointer
    new = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    new->data = num; // Setting the data
    new->left = NULL; // Setting the left and right children to NULL
    new->right = NULL; // Setting the left and right children to NULL
    return new; // Finally returning the created node
}

int main()
{
    // Constructing the root node - Using Function 
    struct node *p = newnnode(14);
    struct node *p1 = newnnode(16);
    struct node *p2 = newnnode(4);
    // Linking the root node with left and right children
    p->left = p2;
    p->right = p1;
    printf("%d",p->left->data); //printing the left of root to check the code
    return 0;
}