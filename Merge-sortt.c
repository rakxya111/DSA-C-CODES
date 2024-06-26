#include <stdio.h>
#include <conio.h>

void merge(int A[], int lb, int mid, int ub)
{
    int i, j, k,l;
    int B[10];
    i = lb; 
    j = mid + 1; 
    k =  lb;
    while (i <= mid && j <= ub)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }

    
     while (j <= ub)
        {
            B[k] = A[j];
            j++;
            k++;
        }	
	

	 while (i <= mid)
        {
            B[k] = A[i];
            i++;
            k++;
        }	
	
      
    for(k = lb; k <= ub; k++)
    {
        A[k] = B[k];
    }
}

void Merge_sort(int A[], int lb, int ub)
{

    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        Merge_sort(A, lb, mid);
        Merge_sort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

int main()
{
	int i;
    int A[9] = {15, 5, 24, 8, 1, 3, 16,17,9};
    Merge_sort(A, 0, 8);
    printf("\nSorted array is :\n");
    for ( i = 0; i < 9; i++)
    {
     printf("%d\t", A[i]);	
	}
   
    return 0;
}