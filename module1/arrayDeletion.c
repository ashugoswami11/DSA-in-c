#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

void arraydeletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int array[100] = {7, 8, 12, 27, 28};
    int index = 2, size = 5;
    printf("before running deletion function\n ");
    display(array, size);
    arraydeletion(array, size, index);
    size -= 1;
    printf("after running deletion function\n ");
    display(array, size);

return 0;    
}