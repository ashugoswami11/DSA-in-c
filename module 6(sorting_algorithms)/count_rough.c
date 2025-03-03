#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

void arraytraversal(int*A, int n){
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

int maximum(int * A, int n){
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


void countsort(int* A, int n){
    int max = maximum(A,n);
    int i, j;
    int * count = (int *)malloc((max+1)*sizeof(int));
    //initializing whole count array elements with zero

    for (int i = 0; i <= max+1; i++)
    {
        count[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        count[A[i]] += 1;
    }

    i = 0;
    j = 0;

    while(i<=max){
        if (count[i]>0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else{
            i++;
        }
        
    }
}

int main(){
    int A[] = {23,5,78,12,9,36,49,66,2};
    int n = 9;

    arraytraversal(A,n);

    countsort(A,n);

    arraytraversal(A,n);

}