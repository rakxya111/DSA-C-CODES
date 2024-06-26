#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *head, *temp;
void delete_first();
void delete_end();
void delete_nth(int);
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
        printf("Which operation do you want to perform ?\n press 1 ----> delete at the beginning\n press 2 ----> delete at the end\n press 3 ----> delete at specific position\n press 4 ----> To Display the Linked list\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            delete_first();
            display();
            break;

        case 2:
            delete_end();
            display();
            break;

        case 3:
            delete_nth(count);
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

void delete_first()
{
    temp = head;
    head = head->next;
    free(temp);
}

void delete_end()
{
    struct node *temp1;
    temp = head;
    while (temp->next != 0)
    {
        temp1 = temp;
        temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
}

void delete_nth(int count)
{
    struct node *temp1;
    int i = 1, pos;
    temp = head;
   
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
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp);
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