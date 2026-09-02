#include<stdio.h>
#include<stdlib.h>

struct stack{ // creating stack using struct  
    int capacity;
    int size;
    int top;
    int *arr;
};



//Below is the function with return type struct stack* to create a stack, with input 
// parameter of int cap - capacity of the stack.
struct stack* create_stack(int cap){ 
    struct stack* S = (struct stack*)malloc(sizeof(struct stack));
    S->capacity = cap;
    S->top = -1;
    S->size = 0;
    S->arr = (int*)malloc(cap*sizeof(int));
    return S;
}

//A function with parameters struct stack* S and int data , will push element to the top of the stack 

void push_el(struct stack* S, int data){
    if(S->top == S->capacity-1){
        printf("Stack Overflow !!");
        return;
    }
    S->top++;
    S->arr[S->top] = data;
    S->size++;
    printf("Push Successful of %d \n",data);
}

void show_stack(struct stack* s){
    struct stack* temp = s;
    if(s->top == -1){
        printf("Stack is empty \n");
        return;
    }
    printf("Elements : \n");
    for(int i = 0 ; i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
}
int main(){
    struct stack* S1 = create_stack(5);
    push_el(S1,7);
    push_el(S1,77);
    show_stack(S1);
    
    return 0;
}