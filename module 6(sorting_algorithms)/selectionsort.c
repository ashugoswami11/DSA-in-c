#include <stdio.h>

void arraytraversal(int *arr, int size){
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
    
}

void selectionsort(int * arr, int n){
    int indexofmin, temp;
    for (int i = 0; i < n-1; i++)
    {
        indexofmin = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[indexofmin]>arr[j])
            {
                indexofmin = j;
            }
            
        }
        temp = arr[i];
        arr[i] = arr[indexofmin];
        arr[indexofmin] = temp;
        
    }
    
}

int main(){
    int arr[] = {23,67,33,5,89,76,12,6};
    int size = 8;

    printf("array before sorting\n");
    arraytraversal(arr,size);

    selectionsort(arr,size);

    printf("array after sorting\n");
    arraytraversal(arr,size);
}