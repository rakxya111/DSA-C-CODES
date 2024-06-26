


#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *previous;
    struct node *next;
};
struct node *head = NULL, *newnode, *temp;

void display()
{
    struct node *temp1 = head;

    while (temp1 != 0)
    {
        printf("%d\t", temp1->data);
        temp1 = temp1->next;
    }
}
void createnode(int num)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    newnode->previous = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->previous = temp;
        temp = newnode;
    }
}

void delete_nth_position()
{

    struct node *temp1 , *temp3,*temp2;
    int pos, i = 1;
    temp1 = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the postion : ");
    scanf("%d", &pos);
    
    if(head == NULL)
    {
        printf("Empty");
    }
    else if(pos==1)
    {
        head = temp1->next;
        head->previous = NULL;
        free(temp1);
    }
    else
    {
        
for(i=1;i<pos-1;i++)
{
temp1=temp1->next;
}
temp2=temp1->next;
temp1->next=temp2->next;
temp3=temp2->next;
temp3->previous=temp1;
free(temp2);

}
}
int main()
{
    createnode(3);
    createnode(4);
    createnode(5);
    createnode(7);
    display();
    delete_nth_position();
    display();
    return 0;
}