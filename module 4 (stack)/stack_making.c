#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int isempty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int isfull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack * ptr, int value){
    if(isfull(ptr)){
        printf("sorry the stack is overflowed \n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = value;
        printf("pushed %d to the stack at position %d \n",value , ptr->top );
    }

}

int main(){
    // struct stack *s;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

    for (int i = 0; i < s->size; i++)
    {
        push(s,i);
        // printf("arr element is %d\n",s->arr[i]= i); //this was my logic but break the rule of stack
        // printf("top's position is %d\n",s->top++ +1); //this was my logic but break the rule of stack
    }
    
    //function to check the stack is empty or not
    if(isempty(s)){
        printf("the stack is empty\n");
    }
    else{
        printf("\nthe stack is not empty\n");
    }

    free(s->arr);
    free(s);
}