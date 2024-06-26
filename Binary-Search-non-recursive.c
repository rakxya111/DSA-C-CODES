#include <stdio.h>
#include <conio.h>

int main()
{
    int A[7] = {9, 12, 24, 30, 36, 45, 70}; // must be sorted
    int beg, end, flag = 0, data, mid;
    beg = 0;
    end = 6;
    printf("Enter the data you want to search in this sorted array (9,12,24,30,36,45,70) :\n");
    scanf("%d", &data);
    while (beg < end)
    {
        mid = (beg + end) / 2;
        if (A[mid] == data)
        {
            flag = 1;
            break;
        }
        else if (data < A[mid])
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }

if (flag == 1)
{
    printf("\n Data found at location: %d", (mid + 1));
}
else
{
    printf("\nData Not Found ");
}
return 0;
}