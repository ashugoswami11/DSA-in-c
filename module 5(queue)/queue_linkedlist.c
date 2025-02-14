#include <stdio.h>
#include <stdlib.h>

//first creating two pointers for node initially they are null because they are not pointing anything in the beginning
struct node * f = NULL;
struct node * r = NULL;

struct node{
    int data;
    struct node * next;
};

void linkedlisttraversal(struct node * ptr){
    while (ptr != NULL)
    {
        printf("list element is: %d\n", ptr->data );
        ptr = ptr->next;
    }
    
}

void enqueue( int val){
    struct node * n = (struct node * )malloc(sizeof(struct node));
    if(n == NULL){
        printf("queue is full can't enqueu\n");
    }
    else{
        n->data = val;
        n->next = NULL;
        if(f == NULL){
            f = r = n;
        }
        else{
            r->next = n;
            r = n;
        }
    }

}

int dequeue(){
    int val = -1;
    struct node * n = f;
    //check for empty
    if(f == NULL){
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

    enqueue(45);
    enqueue(49);
    enqueue(467);

    linkedlisttraversal(f);

    printf("dequeue element is %d\n ", dequeue());
    printf("dequeue element is %d\n ", dequeue());
    printf("dequeue element is %d\n ", dequeue());
   




    return 0;
}