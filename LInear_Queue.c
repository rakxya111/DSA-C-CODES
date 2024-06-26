// linear queue

#include <stdio.h>
#include <stdlib.h>
#define N 5
int front = -1;
int back = -1;
int queue[N];

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
	if (back == N - 1)
	{
		printf("Queue is FULL.");
	}
	else
	{
		printf("Enter the Number : ");
		scanf("%d", &number);
		back++;
		queue[back] = number;
		if (front == -1)
		{
			front++;
		}
	}
}

void dequeue()
{
	if (back == -1 || front > back)
	{
		printf("The queue is empty.");
	}
	else
	{
		front++;
	}
}

void traverse()
{
	int i;
	if (back == -1 || front > back)
	{
		printf("The queue is empty.");
	}
	else
	{
		printf("\n AFTER TRAVESRING : \n");
		for (i = front; i <= back; i++)
		{
			printf("%d\t", queue[i]);
		}
	}
}