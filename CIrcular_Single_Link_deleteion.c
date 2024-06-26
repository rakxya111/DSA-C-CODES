#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode, *temp, *head;

void insertnode1()
{
    head = NULL;
    int choice = 1;
    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        printf("\nEnter the Number to Insert : ");
        scanf("%d", &newnode->data);

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
        printf("\n\n Do u wnt to continue (1/0):");
        scanf("%d", &choice);
    }
}

void delete_at_first()
{
    struct node *temp1;
    temp1 = head;
    if (head == NULL)
    {
        printf("CAN'T INSERT.");
    }
    else
    {
        while (temp1->next != head)
        {
            temp1 = temp1->next;
        }

        head = head->next;
        temp1->next = head;
    }
}

void delete_at_end()
{
    struct node *temp1;
    temp = head;

    if (head == NULL)
    {
        printf("CAN'T INSERT.");
    }
    else
    {
        while (temp->next != head)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = head;

        free(temp);
    }
}

void delete_at_nth()
{
    struct node *temp1;
    temp = head;
    int position, i;

    printf("Enter the position :");
    scanf("%d", &position);
    if (head == NULL)
    {
        printf("CAN'T INSERT.");
    }

    else
    {
        for (i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        free(temp1);
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
    insertnode1();

    do
    {
        printf("\n 1. Delete at begining \n 2. Delete at end \n 3. Delete at nth postion\n 4. Display \n 5. EXIT\n");
        printf("\n choose number to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            delete_at_first();
            break;

        case 2:
            delete_at_end();
            break;

        case 3:
            delete_at_nth();
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