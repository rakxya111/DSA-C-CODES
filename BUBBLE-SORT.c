#include <stdio.h>
#include <conio.h>
#define N 4
int array[N] = {5, 2, 4, 1};

void bubble_sort()
{
    int i, j, temp, flag;
    for (i = 0; i < N - 1; i++)
    {
        flag = 0;
        for (j = 0; j < N - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void display_Bubble()
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d\t", array[i]);
    }
}

int main()
{
    bubble_sort();
    display_Bubble();
    return 0;
}
