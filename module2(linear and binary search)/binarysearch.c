#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[], int size, int element)
{
    int low = 0, mid, high = size - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int array[] = {45, 67, 87, 94, 155, 212, 321, 434};
    int size = sizeof(array) / sizeof(int);
    // printf("size of array is %d\n", size);
    int element = 434;

    int atindex = binarysearch(array, size, element);
    printf("the element %d is found at index %d ", element, atindex);

    return 0;
}