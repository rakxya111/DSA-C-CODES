#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *previous;
};

struct node *newnode, *temp, *head;

void insertnode()
{
    int choice = 1;

    head = NULL;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter a data :");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        newnode->previous = NULL;

        if (head == NULL)
        {
            head = temp = newnode;
            newnode->previous = head;
            newnode->next = head;
        }

        else
        {

            temp->next = newnode;
            newnode->previous = temp;
            newnode->next = head;
            head->previous = newnode;
            temp = newnode;
        }
        printf("DO u wnt to Continue (1/0) : ");
        scanf("%d", &choice);
    }
}

void delete_at_first()
{
    temp = head;

    if (head == NULL)
    {
        printf("Can't delete.");
    }
    else
    {
        head = head->next;
        temp->previous->next = head;
        head->previous = temp->previous;
    }
}

void delete_at_end()
{
    struct node *temp1;
    temp = head;

    if (head == NULL)
    {
        printf("Can't delete.");
    }
    else
    {
        while (temp->next != head)
        {
            temp1 = temp;
            temp = temp->next;
        }
       temp1->next = head;
       head->previous = temp1;
       free(temp);

    }

}

void delete_at_nth()
{
    struct node *temp1;
    int i, pos;
    temp = head;

    if (head == NULL)
    {
        printf("Can't delete.");
    }

    else
    {
        printf("Enter position : ");
        scanf("%d", &pos);
        for (i = 1; i < pos - 1; i++)
        {
            
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->previous = temp;
    }
}

void display()
{
    temp = head;
    printf("\n\nDATAS ARE : \n\n");
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
        printf("\n 1. delete at begining \n 2. delete at end \n 3. delete at nth postion\n 4. Display \n 5. EXIT\n");
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
