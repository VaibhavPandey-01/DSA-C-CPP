#include<stdio.h>
#include<stdlib.h>

struct CQueue{
    int capacity,size,front,rear;
    int *arr;
}CQueue;


// Initializing Cricular Queue or creating CQueue
struct CQueue* c_Q(int cap){
    struct CQueue* q = (struct CQueue*)malloc(sizeof(struct CQueue));
    q->capacity = cap;
    q->front = q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(sizeof(int)*cap);
}

// Function to insert element in Circular Queue
void c_enq(struct CQueue* q,int data){
    if(q->rear == -1){ // If Queue is empty 
        q->rear = q->front = 0;
    }
    if (q->size == q->capacity) { // Check using size
        printf("Queue is full \n");
        return;
    }
    q->rear = (q->rear+1)%q->capacity; // rear value assigned by circular increment 
    q->arr[q->rear] = data;
    printf("Element %d enqueued \n",data);
    q->size++;
}

// function to deque front element from circular queue
void c_deque(struct CQueue* q){
    if(q->front == q->rear){ // condition to check if queue is empty or not 
        printf("Queue is empty\n");
        return ;
    }
    printf("Element %d dequed \n",q->arr[q->front]);
    q->front = (q->front+1)%q->capacity; //  circular increment 
    q->size--;
}

// function to print values of the circular queue 
void dis_q(struct CQueue* q){
    if(q->front == -1){
        printf("Queue is Empty \n");
    }
    int temp = q->front;
    for(int i = 0 ; i< q->size; i++){
        printf("%d ",q->arr[temp]);
        temp++;
    }
    printf("\n");
}

//function to free memory of the array and the queue to prevent memory leakage
void FreeQ(struct CQueue* q){
    free(q->arr);
    free(q);
}

int main(){
    struct CQueue* q1 = c_Q(5);
    c_enq(q1,55);
    c_enq(q1,67);
    c_enq(q1,77);
    c_enq(q1,88);
    c_enq(q1,99);
    c_enq(q1,100);
    dis_q(q1);
    FreeQ(q1);


}