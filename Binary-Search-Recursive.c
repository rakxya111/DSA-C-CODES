#include <stdio.h>
#include <conio.h>
void binarysearch(int A[], int beg, int data, int end)
{
    if (beg <= end)
    {
        int mid = (beg + end) / 2;
        if (A[mid] == data)
        {
            printf("\nData found in location : %d\n", mid + 1);
        }
        else if (data < A[mid])
        {
            binarysearch(A, beg, data, mid - 1);
        }
        else
        {
            binarysearch(A, mid + 1, data, end);
        }
    }
    else
    {
        printf("DATA NOT FOUND");
    }
}
int main()
{
    int beg, end, data;
    int A[7] = {2, 3, 4, 5, 6, 7, 8};
    beg = 0, end = 6;
    printf("Enter the data you wanna serach in (2,3,4,5,6,7,8) :\n");
    scanf("%d", &data);
    binarysearch(A, beg, data, end);
    return 0;
}