#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node * next;
    struct node *previous;
};

struct node *head = NULL, *newnode;
struct node *tail;

void insertnode()
{

int casee = 1;
while(casee)
{
newnode = ((struct node*)malloc(sizeof(struct node)));
 printf("Enter the data:");
 scanf("%d",&newnode->data);
 newnode->previous = 0;
 newnode->next = 0;

 if(head == NULL)
 {
    head = tail = newnode;
 } 
 else
 {
    tail->next = newnode;
    newnode->previous = tail;
    tail = newnode;
 }
 printf("Do you want to continue : ");
 scanf("%d",&casee);
}
}
void insert_at_first(int num)
{

    struct node *temp;
    newnode = ((struct node*)malloc(sizeof(struct node)));
    newnode->data = num;
    newnode->previous = 0;
    newnode->next = 0;
    temp = head;
    newnode->next = temp;
    head->previous = newnode;
    head = newnode;
    temp = newnode;
}

void insert_at_end(int num)
{
    
    newnode = ((struct node*)malloc(sizeof(struct node)));
    newnode->data = num;
    newnode->previous = 0;
    newnode->next = 0;
    tail->next = newnode;
    newnode->previous = tail;
    tail = newnode;
}

void insert_at_nth(int num)
{
    struct node *temp,*temp1;
    newnode = ((struct node*)malloc(sizeof(struct node)));
    int pos,i;
    printf("Enter the position : ");
    scanf("%d",&pos);
    if(pos == 1)
    {
        insert_at_first(num);
    }
    else
    {
        for ( i = 1; i < pos; i++)
    {
     
     temp = temp->next;   
    }
    temp1 = temp;
    newnode->previous = temp1;
    newnode->next = temp;
    temp1->next = newnode;
    temp->previous = newnode;
    
    }
  
    
}

void display()
{
    struct node *temp;
    temp = head ;
    while(temp!=0)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
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