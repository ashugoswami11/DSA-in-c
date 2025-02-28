#include <stdio.h>

void arraytraverse(int*A,int size){
    for (int i = 0; i < size; i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
    
}

int partition(int * A, int low , int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while (A[i]<=pivot)
        {
            i++;
        }
        while (pivot<A[j]){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while (i<j); //it will stop when index of j become smaller than index of i

   //swapping of A[low](bigger) and A[j](smaller)
   temp = A[low]; // bigger value to temp var
   A[low] = A[j]; // smaller value on the place of bigger value 
   A[j] = temp;  // on the empty place of smaller value bigger value will place 
   return j;  //index value of pivot to new place as a partition
}

void quicksort(int * A, int low, int high){
    
    int partitionindex; //index of pivot after partition

    if(low<high){ //until array will not left with a single element or no element
    partitionindex = partition(A,low,high);
    quicksort(A,low,partitionindex-1); //left subarray
    quicksort(A,partitionindex+1,high); //right subarray
    }
}

int main(){
    int A[] = {23,45,22,7,3,90,65,3,78,66};
    int size = 10;

    printf("array before sorting");
    arraytraverse(A,size);

    quicksort(A,0,size-1);

    printf("array after sorting");
    arraytraverse(A,size);
    
}