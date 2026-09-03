#include<stdio.h>
#include<stdlib.h>

// Queue works as FIFO - First in First Out , it has two indexes as front and rear 
struct queue{ // creating queue
    int size,capacity;
    int front,rear;
    int *arr;
} queue;

struct queue* create_queue(int cap){ // create queue function
    struct queue* q = (struct queue*)malloc(sizeof(struct queue)); // dynamically allocate memory to q
    q->front = q->rear = -1;// initially both are -1 hence empty queue
    q->size = 0;
    q->capacity = cap;
    q->arr = (int*)malloc(sizeof(int)*cap); // dynamically memory allocation to array
    return q;
}

// function to add an element to queue 
void enqueue(struct queue* q, int data){ 
    if(q->rear == q->capacity){ // check if queue is full 
        printf("Queue is full \n");
        return;
    }
    if(q->front == q->rear){ // check if queue is empty 
        q->front = q->rear = 0; // if empty set both rear and front to 0 
    }
    q->size++;
    q->arr[q->rear] = data;
    q->rear++;
    printf("Element %d enqueued \n",data);
}

// function to delete the first element from the queue 
void dequeue(struct queue* q){ 
    if(q->front == q->rear){ // check if queue is empty 
        printf("Queue is empty \n");
        return;
    }
    printf("Element %d dequeued \n", q->arr[q->front]); 
    q->front++;
    q->size--;
    
}

// function to print size of the queue
void q_size(struct queue*q){
    printf("Size of Queue is : %d \n",q->size);
}

// function to display the elements of the queue 
void dis_q(struct queue* q){
    for(int i = q->front ; i <= q->rear-1; i++){ //i<=q->rear-1, because in enqueue() in the end there is rear++ which shifts rear to next block of queue
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}

// function to print front value of the queue 
void front_q(struct queue* q){
    printf("Front of queue : %d \n",q->front);
}

int main(){
    struct queue* q1 =create_queue(5);
    enqueue(q1,99);
    enqueue(q1,88);
    enqueue(q1,77);
    enqueue(q1,66);
    enqueue(q1,55);
    enqueue(q1,44);
    q_size(q1);
    front_q(q1);
    dequeue(q1);
    enqueue(q1,11);
    q_size(q1);
    dis_q(q1);
    front_q(q1);
    free(q1);
    return 0;
}