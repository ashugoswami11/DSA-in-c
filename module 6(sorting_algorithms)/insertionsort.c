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

void insertionsort(int *arr, int n)
{
    int key, j; // key will store the [i]th element of array and j will store the [i-1]th array means previous from current element
    // loop for passes
    for (int i = 1; i < n; i++) // here we are not starting from zero because we want to start comparison from second element of array
    {
        key = arr[i];
        j = i - 1; // it will hold the index position of array's element "previous one"
        // loop for comparison and insertion
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {23, 45, 65, 76, 54, 2, 34, 99, 6};
    // int arr[] = {23, 34, 45, 67, 87, 99};
    int size = 9;

    printf("array before sorting\n");
    arraytraversal(arr, size);

    insertionsort(arr, size);

    printf("array after sorting\n");
    arraytraversal(arr, size);
}