#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *head, *temp;
void insert_first();
void insert_end();
void insert_nth(int);
void display();

int main()
{
    int count = 0, choice = 1, a;
    head = NULL;
    while (choice)
    {
        newnode = ((struct node *)malloc(sizeof(struct node)));
        newnode->next = 0;
        printf("Enter the data : ");
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = temp = newnode;
        }

        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (1/0) :");
        scanf("%d", &choice);
    }
    temp = head;
    while (temp != 0)
    {
        temp = temp->next;
        count++;
    }
    do
    {
        printf("Which operation do you want to perform ?\n press 1 ----> insert at the beginning\n press 2 ----> insert at the end\n press 3 ----> insert at specific position\n press 4 ----> To Display the Linked list\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            insert_first();
            display();
            break;

        case 2:
            insert_end();
            display();
            break;

        case 3:
            insert_nth(count);
            display();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;
        }
    } while (a != 5);
    return 0;
}

void insert_first()
{
    temp = head;
    newnode = ((struct node *)malloc(sizeof(struct node)));
    printf("Enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    temp = head;
    newnode = ((struct node *)malloc(sizeof(struct node)));
    printf("Enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    while (temp->next != 0)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insert_nth(int count)
{
    int i = 1, pos;
    temp = head;
    newnode = ((struct node *)malloc(sizeof(struct node)));
    printf("Enter the data : ");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    printf("Enter the postion: ");
    scanf("%d", &pos);
    if (pos > count)
    {
        printf("Can't be done.");
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}