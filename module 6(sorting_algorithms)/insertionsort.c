#include <stdio.h>
#include <stdlib.h>

void arraytraversal(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionsort(int * arr, int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < count; j++)
        {
            /* code */
        }
        
    }
    
}

int main()
{
    // int arr[] = {23, 45, 65, 76, 54, 2, 34, 99, 6};
    int arr[] = {23,34,45,67,87,99};
    int size = 6;

    printf("array before sorting\n");
    arraytraversal(arr, size);

    insertion(arr, size);

    printf("array after sorting\n");
    arraytraversal(arr, size);
}