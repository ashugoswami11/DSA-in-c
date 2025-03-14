// #include <stdio.h>

// void arraytraverse(int *A, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf(" %d ", A[i]);
//     }
//     printf("\n");
// }

// int partition(int *A, int low, int high)
// {
//     int pivot = A[low]; // it works on array's elements
//     int i = low + 1;    // it plays on indexes
//     int j = high;       // it plays on indexes
//     int temp;

//     do
//     {
//         while (A[i] <= pivot)
//         {
//             i++;
//         }

//         while (A[j] > pivot)
//         {
//             j--;
//         }

//         if (i<j) //agar loop pura hone se pehle hee A[low] mtlb pivot se chote elements mil gye tab wrna i aur j k crossover k baad niche jaake pivot naye index pr pahuch jayega
//         {
//         temp = A[i];
//         A[i] = A[j];
//         A[j] = temp;
//         }
//     }while(i<j);

//     //to swap pivot and A[j] elements
//     temp = A[low];   //here i created a mistake instead of A[low]  which holds the pivot forever i wrote pivot itself which is totally wrong because (pivot) itself is not fixed in this program
//     A[low] = A[j];
//     A[j] = temp;
//     return j;
// }

// void quicksort(int *A, int low, int high)
// {
//     int partitionindex; // it will store the pivot's new index

//     if (low < high)
//     {
//         partitionindex = partition(A, low, high);
//         quicksort(A, low, partitionindex - 1);  // left to right
//         quicksort(A, partitionindex + 1, high); // right to left
//     }
// }

// int main()
// {
//     int A[] = {23, 45, 22, 7, 3, 90, 65, 3, 78, 66};
//     int size = 10;

//     printf("array before sorting");
//     arraytraverse(A, size);

//     quicksort(A, 0, size - 1);

//     printf("array after sorting");
//     arraytraverse(A, size);
// }

#include <stdio.h>

void arraytraversal(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while(A[i]<=pivot){
            i++;
        }

        while(A[j]>pivot){
            j--;
        }

        if (i<j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }   
    }while(i<j);

    temp = A[low];  // i made a mistake here pivot is just a temporary local variable which i declared in the function but low is what actually belongs to array and could make change in array so instead of writing pivot i must write A[low]
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int *A, int low, int high)
{
    int partitionIndex;
    
    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quicksort(A, low, partitionIndex - 1);
        quicksort(A, partitionIndex + 1, high);
       
    }

}

int main()
{
    int A[] = {23, 45, 5, 6, 20, 98, 4, 32, 77, 69};
    int n = 10;

    printf("array before quicksort\n");
    arraytraversal(A, 10);

    quicksort(A, 0, n - 1);

    printf("array after quicksort\n");
    arraytraversal(A, 10);
}