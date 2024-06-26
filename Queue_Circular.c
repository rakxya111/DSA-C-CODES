// circular queue

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 5
int front = -1;
int back = -1;
int array[N];
void enqueue();
void dequeue();
void traverse();

int main()
{
    int choice;
    do
    {
        printf("\n 1> ENQUEUE \n 2> DEQUEUE \n 3> TRAVERSE  \n 4> EXIT \n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            traverse();
            break;

        case 4:
            exit(0);
            break;
        }
    } while (choice != 4);
    return 0;
}

void enqueue()
{
    int number;
    if ((back + 1) % N == front)
    {
        printf("The Queue is FULL.");
    }
    else
    {
        printf("\nEnter the number to insert in Queue : ");
        scanf("%d", &number);
        back = (back + 1) % N;
        array[back] = number;
    }
}

void dequeue()
{
    if (front == back)
    {
        printf("The Queue is EMPTY.");
    }
    else
    {
        front = (front + 1) % N;
    }
}

void traverse()
{
    if (front == back)
    {
        printf("Queue is EMPTYY.");
        ;
    }
    else
    {
        printf("\n\nAFTER TRAVERSING : \n\n");
        for (int i = (front + 1) % N; i <= back; i++)
        {
            printf("%d\t", array[i]);
        }
    }
}