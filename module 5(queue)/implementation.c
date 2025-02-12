#include <stdio.h>
#include <stdlib.h>

//queue and it's operations using arrayss

struct queue {
    int size;
    int r;
    int f;
    int * arr;
};

int isfull(struct queue * q){
    if (q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}

int isempty(struct queue * q){
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

//function to enter the values in the queue known as enqueue
void enqueue(struct queue * q, int val){
    if(isfull(q)){
        printf("queue is full can't enter a new value inside the queue\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q){
    //here a is assigned with -1 just because in case the queue is empty it will return a simple -1
    int a = -1;
    if(isempty(q)){
        printf("queue is empty removal is not possible \n");
    }
    else{

        //The old element still exists in memory but is simply ignored.
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct queue q;
    q.size = 100;
    q.f = -1;
    q.r = -1;
    q.arr = (int * )malloc(q.size * sizeof(char));

    enqueue(&q, 34);
    enqueue(&q, 78);
    enqueue(&q, 87);

    printf("dequing elements form the queue\n");

   // printf("dequeue element is %d\n ", dequeue(&q));
   // printf("dequeue element is %d\n ", dequeue(&q));
    printf("dequeue element is %d\n", dequeue(&q));
    // printf("dequeue element is %d\n ", dequeue(&q));
}