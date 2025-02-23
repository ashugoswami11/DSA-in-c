#include <stdio.h>
#include <stdlib.h>

void arraytraversal(int *arr, int n)
{
    int i = 0;
    while (i<n) //i was doing a mistake here instead of i<n i wrote arr[i]>n which leads to confusion
    {
        printf("%d",arr[i]);
        printf(" ");
        i++;
    }
    printf("\n");
}

void insertionsort(int * arr, int n){
    int key,j;

    //loop for passes
    for (int i = 1; i < n; i++) // it will count the current iteration
    {
        key = arr[i]; // current iteration element
        j = i-1; //(current iteration index-1) element

        //this loop will keep on iterate till the front element and previous element don't get properly sorted
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j]; // previous to front ,piche wala aage
            arr[j] = key; // front to previous aage wala mtlb key ko piche j-1 wali jagah pr
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    int arr[] = {23,56,76,34,2,76,999,555,12};
    int size = 9;

    printf("array before insertion sort\n");
    arraytraversal(arr, size);

    insertionsort(arr, size);

    printf("array after insertion sort\n");
    arraytraversal(arr, size);
}