/* c program to create and insert at begining , end and nth position in a circular linked list.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp;
int count = 0;

void insertnode()
{
    int number;
    int count1 = 1;
    head = NULL;
    while (count1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("\nEnter a data to put : ");
        scanf("%d",&number);
        newnode->data = number;
        if (head == NULL)
        {
            head = temp = newnode;
            newnode->next = head;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            newnode->next = head;
        }
        printf("\nDO you want to continue (1/0): ");
        scanf("%d", &count1);
    }
}



void insert_at_beg(int num)
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        printf("Empty can be insert.");
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        head = newnode;
        temp->next = head;
    }
}

void insert_at_end(int num)
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next = NULL;
    if (head == NULL)
    {
        printf("EMPTYYY");
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

void insert_at_nth(int num)
{
    struct node *temp1;
    int pos, i;
    temp = head;
    

    printf("\nEnter the position : ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("\nCan't enter .\n");
    }

    else if (pos == 1)
    {
        insert_at_beg(num);
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        for (i = 1; i < (pos - 1); i++)
        {
            temp1 = temp;
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void display()
{
    temp = head;
    printf("\n\nDATAS ARE:\n");
    while (temp->next != head)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("%d\t", temp->data);
}

int main()
{
    int choice;
    insertnode();

    do
    {
        printf("\n 1. Insert at begining \n 2. Insert at end \n 3. Insert at nth postion\n 4. Display \n 5. EXIT\n");
        printf("\n choose number to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_beg(12);
            break;

        case 2:
            insert_at_end(14);
            break;

        case 3:
            insert_at_nth(22);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;
        }
    } while (choice != 5);
    return 0;
}