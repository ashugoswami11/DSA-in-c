#include <stdio.h>
#include <stdlib.h>

struct cqueue{
    int size;
    int f;
    int r;
    int * arr;
};

int isempty(struct cqueue * q){
    if(q->f == q->r){
        return 1;
    }
    else{
        return 0;
    }
}
//when we mod a smaller number by big number small number as it is returns
int isfull(struct cqueue * q){
    if((q->r+1) % q->size == q->f){
        return 1;
    }
    else{return 0;}
}

void enqueue(struct cqueue * q, int val){
    if(isfull(q)){
        printf("queue is full !\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct cqueue * q){
    int a = -1;
    if(isempty(q)){
        printf("queue is empty !\n");
    }
    else{
        //first we have to move the f forward because queue is always 1 step back because it starts from -1
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;

}
int main(){
    struct cqueue q;
    /* IMPORTANT LESSION
    one of the most important lession is there is always an empty space follow after the front 
    or we can say behind the front there is always an empty space SO if we create a circular queue of size 
    5 it will only gonna store 4 elements only
*/
    q.size = 4;
    // if we write it like q.f = q.r = -1; it means we are out from the circular queue
    //it doesn't make any sense so we start front and rear from 0;

    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q , 34);
    enqueue(&q , 56);
    enqueue(&q , 98);
    // enqueue(&q , 77);

    printf("dequing the element %d \n", dequeue(&q));
    printf("dequing the element %d \n", dequeue(&q));
    printf("dequing the element %d \n", dequeue(&q));
}