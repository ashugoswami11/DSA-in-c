#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int* A, int low, int mid, int high){
    int i ,j , k, B[100];
    i = low;
    j = mid+1;
    k = low;

    while (i<=mid && j<=high)
    {
        if (A[i]<A[j])
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

    while(i<=mid){
        B[k]=A[i];
        i++;
        k++;
    }

    while(j<=high){
        B[k]=A[j];
        j++;
        k++;
    }
    
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergesort(int *A, int low , int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergesort(A, low , mid);
        mergesort(A, mid+1 , high);
        merge(A,low,mid,high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;
    printArray(A, n);
    mergesort(A, 0, n-1);
    // quicksort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}