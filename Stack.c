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


//Operations on Stack 
//A function with parameters struct stack* S and int data , will push element to the top of the stack 

void push_el(struct stack*S){
    if(S->top == S->capacity-1){
        printf("Stack Overflow !!\n");
        return;
    }
    int data;
    printf("\nEnter the data : \n"); scanf("%d",&data);
    S->top++;
    S->arr[S->top] = data;
    S->size++;
    printf("Push Successful of %d \n",data);
}

// A function that deletes the top most element of the Stack by following LIFO 
void del_top(struct stack* s){
    if(s->top == -1){
        printf("Stack is empty already \n");
        return;
    }
    int temp = s->arr[s->top];
    s->top--;
    s->size--;
    printf("Element %d deleted successfully \n",temp);
}

// Function that traverse the stack and prints the elements 
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
    int ch;
    while (1)
    {
        printf("\n------ Enter Your Choice -----\n");
        printf("1. For pushing an element into the stack \n");
        printf("2. For deleting the top most element of the stack \n");
        printf("3. For printing the elements of the stack \n");
        printf("4. To exit "); scanf("%d",&ch);

        switch (ch)
        {
        case 1:push_el(S1);
            break;
        case 2: del_top(S1);
        break;
        case 3: show_stack(S1);
        break;
        case 4: exit(0);
        default: printf("Wrong Choice \n");
            break;
        }
    }
    

    return 0;
}