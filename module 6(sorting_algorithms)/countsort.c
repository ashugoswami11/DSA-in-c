#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int * A, int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");  
}

int maximum(int *A, int n)
{

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i]) 
        {
            max = A[i];
        }
    }
    return max;
}

void countsort(int *A, int n)
{
    int j, i;
    // find the maximum element in A
    int max = maximum(A,n);

    //create the count array
    int * count = (int *) malloc((max+1)*sizeof(int));

    //initialize the array elements with zero
    for (i = 0; i < max+1; i++)
    {
        count[i]=0;
    }

    //incrementing the corresponding index in the count array means the same element which found in the Array A, go to count array and increment the corresponding index 
    //for example if A[i] = 5 means go the count[index = 5] and initialize it with 1;
    
    for (i = 0; i < n; i++)
    {
        count[A[i]] += 1;
    }

    i = 0; // i is the counter of count array
    j = 0; // j is the counter of main array
    
    while (i<= max)
    {
        if(count[i]>0){
            A[j] = i;
            count[i]--;
            j++;
        }  
        else{
            i++;
        }
    }
    
}

int main()
{
    int A[] = {9, 14, 4, 8, 7, 5, 6};
    // int A[] = {1, 1, 1, 1, 1, 2, 1};
    int n = 7;
    printArray(A, n);
    countsort(A, n);
    // quicksort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}