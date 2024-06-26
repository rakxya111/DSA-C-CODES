// c program on implementation of the stack

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 5
int top = -1;
int stack[N];
void push();
void popp();
void traverse();

int main()
{
    int choice;
    do
    {
    printf("\nEnter which task do you want to perform :\n");
    printf("1.PUSH OPERATION \n 2.POP OPERATION \n 3.TRAVERSING\n 4. EXIT\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        push();
        break;

        case 2:
        popp();
        break;

        case 3:
        traverse();
        break;

        case 4:
        exit(0);
        break;

        default:
        printf("choose right number please !!!");
    }  

    } while (choice!=4);
    return 0;
}

void push()
{
    int data;
    if(top == N -1)
    {
        printf("\nThe stack is full so can't push anymore.\n");
    }
    else
    {
        printf("\nEnter a data you wanna push :");
        scanf("%d",&data);
        top++;
        stack[top] = data;
    }
}

void popp()
{
    if(top == -1)
    {
        printf("\nThe stack is empty.\n");
    }
    else
    {
        printf("\n%d is popped\n",stack[top]);
        top--;
    }
}

void traverse()
{
    if(top == -1)
    {
        printf("\nThe given stack is empty.\n");
    }
    else
    {
        int i;
        printf("\nAfter traversing : \n");
        for(i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
}

