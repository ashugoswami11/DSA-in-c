#include <stdio.h>
#include <stdlib.h>

int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int array[] = {45, 67, 87, 44, 55, 12, 221, 34, 56, 98};
    int size = sizeof(array) / sizeof(int);
    int element = 12;

    int atindex = linearsearch(array, size, element);
    printf("the element %d is found at index %d ", element, atindex);

    return 0;
}