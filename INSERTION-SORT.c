#include <stdio.h>
#include <conio.h>
#define N 6
int A[N];
void insertion_sort(int A[], int n);
void display_sort();
int main()
{
    printf("Enter %d Elements in array :\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("A[%d] : ", i);
        scanf("%d", &A[i]);
    }
    insertion_sort(A, N);
    display_sort();
    return 0;
}

void insertion_sort(int A[], int n)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > temp)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }
}

void display_sort()
{
    printf("\nDISPLAYING AFTER SORTING\n\n");
    for(int i = 0;i<N;i++)
    {
        printf("%d\t",A[i]);
    }
}