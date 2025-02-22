// function for the bubble sort
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

void bubblesort(int *arr, int n)
{
    int temp;
    int issorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        issorted = 1;  // issorted = 1 means true yes array is sorted no need to further pass
        printf("number of pass is %d \n", i+1);
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // i did a mistake here it is not arr[i] it's arr[j]
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                issorted =0;  // issorted = 0 means false passes were required and sorting is needed
            }
        }
        if (issorted)
        {
            return;
        }
        
    }
}

// right after the first loop comparison done on the i and i+1 element but if it is proved that all elements  
//are sorted and no need to sort so futher passes can be cancelled and program return  in first pass and value of issorted remains 1
// but if in any case program entered in the swapping block it means the value of issorted is not 1 and program is not sorted

int main()
{
    // int arr[] = {23, 45, 65, 76, 54, 2, 34, 99, 6};
    int arr[] = {23,34,45,67,87,99};
    int size = 6;

    printf("array before sorting\n");
    arraytraversal(arr, size);

    bubblesort(arr, size);

    printf("array after sorting\n");
    arraytraversal(arr, size);
}