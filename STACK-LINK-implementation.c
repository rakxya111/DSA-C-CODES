#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *top = 0;
void push(int x)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode; 
}

void pop()
{
    struct node *temp;
    temp = top;
    if(top == 0)
    {
        printf("stack is empty.");
    }
    else
    {
        printf("\nThe popped item is %d.\n",top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp = top;
    if(top == 0)
    {
        printf("Stack is EMPTY");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d\t",temp->data);
            temp = temp->next;
        }
    }
}

void peek() //to find the topmost element
{
    if(top == 0)
    {
        printf("Stack is EMPTY");
    }
    else
    {
        printf("\nThe top most element is : %d\n",top->data);
    }

}

int main()
{
    push(9);
    push(12);
    push(13);
    push(15);
    peek();
    display();
    pop();
    pop();
    peek();
    display();
    return 0;
}