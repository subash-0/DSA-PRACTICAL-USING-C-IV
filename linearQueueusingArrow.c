#include<stdio.h>
#include <stdlib.h>
#define N 5
struct queue
{
    int data[N];
    int front,rear;

};

void enqueue(struct queue *q);
void dequeue(struct queue *q){
    if(q->rear<q->front)
    {
        printf("Queue is Empty .");
    }else {
        printf("%d is Dequeued.",q->data[q->front]);
        q->front++;
    }
}

void shift(struct queue *q){
    int i;
     if(q->rear<q->front)
    {
        printf("Queue is Empty .");
    }else {
        printf("%d is Dequeued.",q->data[q->front]);
       
        for (i=1; i<=q->rear;i++) {
            q->data[i-1]=q->data[i];
        
        }
        q->rear--;
      
    }

}
void show(struct queue *q){
    int i;
    if(q->rear<q->front){
        printf("Queue is Empty.");

    }else {
        printf("The numbers in the queue are:\n");
        for(i=q->front;i<=q->rear;++i)
        {
            printf("%d\t",q->data[i]);
        }
    }
}
void front(struct queue *q)
{
     if(q->rear<q->front){
        printf("Queue is Empty.");

    }else {
        printf("The numbers in front of the queue %d:\n",q->data[q->front]);
       
}
}

int main()
{
    struct queue q;
    int c;
    q.rear=-1;
    q.front=0;
    do {
       
    printf("\n\n\t\t\t\t\tLinear Queue Implementation using Array \n\n");
    printf("1. Enqueue \t 2. Dequeue \t 3. Front \t 4. Show all \t 5. Deque with Shift \t 6. Exit \n");
    printf("Enter Your Choice:");
    scanf("%d",&c);
    switch (c) {
        case 1:
            system("clear");
            enqueue(&q);
            break;
        case 2:
            system("clear");
            dequeue(&q);
            break;
        case 3:
            system("clear");
            front(&q);
            break;
        case 4:
            system("clear");
            show(&q);
            break;
        case 5:
            shift(&q);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Select from Available Options:");
            break;

    
    }

    }while (c!=6);

    return 0;
}

void enqueue(struct queue *q){
  
     int val;
    if(q->rear==N-1)
    {
        printf("Queue is Full !");

    }else {
        printf("Enter the Number to Enque:");
        scanf("%d",&val);
        q->rear++;
        q->data[q->rear]= val;
        
        printf("%d is enqueued. ",val);
    }
}