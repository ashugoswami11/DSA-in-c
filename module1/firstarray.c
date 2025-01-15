#include <stdio.h>
#include <stdlib.h>

// initializing a stucture to hold arrays
struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myarray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct myarray *a)
{
    for (int i = 0; i <= a->used_size; i++)
    {
        printf("the value is %d \n", (a->ptr)[i]);
    }
}

void setval(struct myarray *a)
{
    int n;
    for (int i = 0; i <= a->used_size; i++)
    {
        printf("enter the value at the %d th position ", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct myarray marks;
    createarray(&marks, 10, 4);
    printf("setval function is running\n ");
    setval(&marks);

    printf("show function is running\n ");
    show(&marks);

    return 0;
}