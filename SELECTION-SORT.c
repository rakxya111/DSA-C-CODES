#include <stdio.h>
#include <conio.h>

void selectionsort(int *A, int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        //swapping
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

void printArray(int* A, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {7, 4, 10, 8, 3, 1};
    int n = 6;
    selectionsort(A, n);
    printArray(A,n);
    return 0;
}