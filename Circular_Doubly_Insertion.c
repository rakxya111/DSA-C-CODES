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

void insert_at_first(int num)
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->data = num;
    if (head == NULL)
    {
        printf("Can't Insert.");
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newnode->next = head;
        newnode->previous = head->previous;
        temp->next = newnode;
        head->previous = newnode;
        head = newnode;
    }
}

void insert_at_end(int num)
{
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->data = num;
    if (head == NULL)
    {
        printf("Can't Insert.");
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->previous = temp;
        head->previous = newnode;
        newnode->next = head;
    }
}

void insert_at_nth(int num)
{
    struct node *temp1;
    int i, pos;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->previous = NULL;
    newnode->data = num;
    if (head == NULL)
    {
        printf("Can't Insert.");
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
        
        temp->next = newnode;
        newnode->previous = temp;
        newnode->next = temp1;
        temp1->previous = newnode;

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
        printf("\n 1. Insert at begining \n 2. Insert at end \n 3. Insert at nth postion\n 4. Display \n 5. EXIT\n");
        printf("\n choose number to perform : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_at_first(12);
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
