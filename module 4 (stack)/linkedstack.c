#include <stdio.h>
#include <stdlib.h>

//creating linked list
struct node{
    int data;
    struct node * next;
};


void listtraversal(struct node * top){
    while(top != NULL){
        printf("element pushed is %d\n", top->data);
        top = top->next;
    }
} 

int isfull(struct node * top){
    struct node*p = (struct node *)malloc(sizeof(struct node));
    if(p == NULL){
        return 1;
    }
    else{return 0;}
}

int isempty(struct node * top){
    if(top == NULL){
        return 1;
    }
    else{ return 0;}
}

struct node* push(struct node* top, int val){
    if(isfull(top)){
        printf("stack overloaded");
    }
    else{
        struct node *p = (struct node*)malloc(sizeof(struct node));
        p->data = val;
        p->next = top;
        top = p;
        return top;
    }
}

int pop(struct node ** ptr){
    if(isempty(*ptr)){
        printf("stack is underflowed");
    }
    else{
        struct node* p = *ptr;
        *ptr = *(ptr)->next;
        int num = p->data;
        free(p);
        return num;
    }
}

int main(){
struct node * top = NULL;

top = push(top,68);
top = push(top,45);
top = push(top,78);
top = push(top,99);

listtraversal(top);

printf("the element which is poppped is %d", pop(top));

listtraversal(top);

return 0;
}