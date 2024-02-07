#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#define  n 5

struct queue 
{
    int data[n];
    int rear,front;
};

void insert(struct queue *cq)
{
    int x;
    if(cq->front==(cq->rear+1)%n)
    {
        printf("Queue is Full !");
    }else {
        printf("Enter a number to insert:");
        scanf("%d",&x);
        cq->data[cq->rear] = x;
        cq->rear = (cq->rear+1)%n;

    }
}

void del(struct queue *cq)
{
    int d;
    if(cq->rear == cq->front)
    {
        cq->rear = 0;
        cq->front =0;
        printf("Wueue is empty");
    }else {
        d = cq->data[cq->front];
        cq->front = (cq->front+1)%n;
        printf("Deleted element is : %d",d);
    }

}

void display(struct queue *cq)
{
    int i;
    i = cq->front;
    if(cq->front==cq->rear)
    {
        printf("No element in queue !");
    }
    else {
        printf("Element are:\n");
        for (; i!=cq->rear;i=(i+1)%n) {
            printf("%d \t",cq->data[i]);
        
        }
    }
}

int main()
{
    int c;
    struct queue cirque;
    cirque.front=0;
    cirque.rear=0;
    do {
        system("clear");
    printf("\n1. Insert \t 2. Delete \t 3. Display \t 4. Exit \n");
    printf("Enter your choice:");
    scanf("%d",&c);
    switch (c) {
        case 1:
            insert(&cirque);
            break;
        case 2:
            del(&cirque);
            break;
        case 3:
            display(&cirque);
            break;
        case 4:
            exit(0);
    }
    }while (c!=4);
    return 0;
}