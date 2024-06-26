#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int x)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;

    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void display()
{
    struct node *temp;

    if (front == 0 && rear == 0)
    {
        printf("QUEUE EMPTY.");
    }
    else
    {
    temp = front;
    while (temp != 0)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }

    }
    
}

void dequeue()
{
    struct node *temp;
    temp = front;

    if (front == 0 && rear == 0)
    {
        printf("QUEUE EMPTY.");
    }
    else
    {
        printf("\n%d is dequeued.", front->data);
        front = front->next;
        free(temp);
    }
}

void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("QUEUE EMPTY.");
    }
    else
    {
        printf("\n%d is the topmost no in the queue.", front->data);
    }
}
int main()
{
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    peek();
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
