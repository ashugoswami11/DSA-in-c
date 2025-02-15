#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * next;
};
struct node * f = NULL;
struct node * r = NULL;

int linkqueuetraversal(struct node * ptr){
    while (ptr != NULL)
    {
       printf("%d\n",ptr->data);
       ptr = ptr->next;
    }
}

void enque(int val){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("queue is full can't enqueue");
    }else{
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;    
        }else{
            r->next = n;
            r =n;
        }  
    }  
}

int dequeue(){
    struct node * n = f; 
    int val = -1;

    if (f == NULL)
    {
        printf("queue is empty can't dequeue\n");
    }
    else{
        f = f->next;
        val = n->data;
        free(n);
    }
    return val;
}

int main(){
    enque(56);
    enque(889);
    enque(98);

    linkqueuetraversal(f);
    
    printf("dequeue element is %d\n",dequeue());
    printf("dequeue element is %d\n",dequeue());
    printf("dequeue element is %d\n",dequeue());
}
