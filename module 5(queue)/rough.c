#include <stdio.h>
#include <stdlib.h>

struct cqueue{
    int size;
    int f;
    int r;
    int *arr;
};

int isfull(struct cqueue * q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    else{ return 0;}
}

int isempty(struct cqueue * q){
    if(q->r == q->f){
        return 1;
    }
    else{return 0;}
}

void enqueue(struct cqueue * q, int val){
    if (isfull(q))
    {
        printf("queue is full can't enqueue\n");
    }
    else{    
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }   
}

int dequeue(struct cqueue * q){
    int a = -1;
    if (isempty(q))
    {
        printf("queue is empty can't dequeue\n");  
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct cqueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 34);
    enqueue(&q, 36);
    enqueue(&q, 98);

    printf("dequeued element is %d\n", dequeue(&q));
    printf("dequeued element is %d\n", dequeue(&q));

}