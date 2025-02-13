#include <stdio.h>
#include <stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isempty(struct queue *q ){
    if(q->r == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct queue *q ){
    if((q->r+1) % q->size == q->f){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q, int val){
    if(isfull(q)){
        printf("queue is full can't store further elements\n");
    }
    else{
        // mod size is redundant until q->r+1 % q->size != q->size
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q)
{
  int a = -1;  
  if(isempty(q)){
    printf("queue is empty can't dequeue any element \n");
  }  
  else{
    //we write q->f = (q->f+1)%q->size; first because our queue is 1 step back always it starts from -1 so it remains 1 step back so to dequeue the current element we have to first move the f forward
    q->f = (q->f+1)%q->size;
    a = q->arr[q->f];
  }
  return a;
}

int main(){
    struct queue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int*)malloc(q.size * sizeof(int));

    enqueue(&q, 45);
    enqueue(&q, 65);
    enqueue(&q, 88);

    printf("dequing the element %d \n", dequeue(&q));
    printf("dequing the element %d \n", dequeue(&q));
    printf("dequing the element %d \n", dequeue(&q));



}