#include <stdio.h>

void arraytraversal(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int partition(int *A, int low, int high)
{ // low =A[0] , high =[size-1]
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        { // i will keep checking for an element which is bigger than pivot
            i++;
        }
        while (A[j] > pivot)
        { // j will keep checking for an element which is smaller than pivot
            j--;
        }

        if (i < j) /*if ith element is bigger than jth element then swap them means we i was seek for element bigger and j was seek for element
                    smaller than pivot and they both found before crossover off i and j so simply swap them*/
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j); // we used do-while looop so atleast for once it run and then keep on comparing

    // swap if i becomes greater than j and j fails to find and value smaller than pivot
    temp = A[low]; // storing pivot into temporary variable
    A[low] = A[j]; // storing bigger element which was on pivot to where j was which is obv j is smaller
    A[j] = temp;   // now because pivot is bigger than j so swap between them
    return j;
}

void quickSort(int *A, int low, int high)
{

    int partitionIndex; // index of pivot after partition

    // base case
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

int main()
{
    int A[] = {23, 45, 76, 5, 8, 44, 58, 99, 1, 2};
    int size = 10;

    printf("array before sort");

    arraytraversal(A, size);

    quickSort(A, 0, size - 1);

    printf("array after sort");

    arraytraversal(A, size);
}