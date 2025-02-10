#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int stacktop;
    char * arr;
};

char stacktop(struct stack * bucket){
    return bucket->arr[bucket->stacktop];
}

int isempty(struct stack * bucket){
    if(bucket->stacktop == -1){
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int isfull(struct stack * bucket){
    if(bucket->stacktop == bucket->size-1){
        return 1;
    }
    else
    {
        return 0;
    }
    
}


void push(struct stack * bucket, char val){
    if (isfull(bucket))
    {
        printf("stack is overflowed can't push ");
    }
    else{
        bucket->stacktop++;
        bucket->arr[bucket->stacktop] = val;
    } 
}

char pop(struct stack * bucket){
    if (isempty(bucket))
    {
        printf("stack is underflowed can't pop ");
        return 0;
    }
    else{
        char val = bucket->arr[bucket->stacktop];
        bucket->stacktop--;
        return val;
    }
    
}

int isoperator(char ch){
    if(ch == '*' || ch == '/' || ch == '-' || ch == '+'){
        return 1;
    }
    else{
        return 0;
    }
}

int precedence(char ch){
    if(ch == '/' || ch == '*'){
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else{
        return 0;
    }
    
}

char * infixtopostfix(char * infix){
    struct stack * opbucket = (struct stack *)malloc(sizeof(struct stack));
    opbucket->size = 100;
    opbucket->stacktop = -1;
    opbucket->arr = (char *)malloc(opbucket->size * sizeof(char));

    char * postfix = (char *)malloc(strlen(infix)+1 * sizeof(char));

    //counters for infix and postfix for tracking the index values
    int i = 0;
    int j = 0;

    while(infix[i] != '\0'){
        if (!isoperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i]) > precedence(stacktop(opbucket))){
                push(opbucket , infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(opbucket);
                j++;
            }

        }
        
    }
    while (!isempty(opbucket))
    {
        postfix[j] = pop(opbucket);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
    
}

int main(){
    char * infix = "7*4-59+33/23*9";
    printf("postfix expression is: %s", infixtopostfix(infix));

}

