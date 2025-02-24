#include <stdio.h>

int arraytraversal(int * a, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    
}

void selectionsorting(int *arr, int n){
    int indexofmin, temp;
    for (int i = 0; i < n-1; i++)
    {
        indexofmin = i;
        for (int j = i+1; j < n; j++)
        {
            if(arr[j]<arr[indexofmin]){
                indexofmin = j; //once it finds a book smaller than the current smallest (the one at indexofmin), it updates indexofmin to that book's index.
            }
        }
        //swap arr[i] and arr[indexofmin]
        temp = arr[i];
        arr[i] = arr[indexofmin];
        arr[indexofmin] = temp;
        
    }
    
}

int main(){

    int arr[] = {23,45,1,26,75,38,86,55,68};
    int size = 9;

    printf("array before selection sorting\n");
    arraytraversal(arr,size);

    selectionsorting(arr,size);

    printf("array after selection sorting\n");
    arraytraversal(arr,size);

}