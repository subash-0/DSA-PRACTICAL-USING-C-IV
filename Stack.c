#include<stdio.h>

#include<stdlib.h>
#define N 5
struct stack
{
    int n[N];
    int top;
};

void push(struct stack *s, int val);
void pop(struct stack *s);
void show(struct stack *s);
void tos(struct stack *s);
void main(){
    int c,val;
    struct stack s;
    s.top=-1;
    do{
        printf("\n\t\t STACK IMPLEMENTATION USING ARRAY \n");
        printf("\n Choose an option: \n 1.Push \n 2.Pop \n 3.Show all \n 4.Top of Stack \n 5.Exit \n ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter Number to push :");
                scanf("%d",&val);
                push(&s,val);
                break;
            }
            case 2:
            {
                pop(&s);
                break;
            }
            case 3:
            {
                show(&s);
                break;
            }
            case 4:
            {
                tos(&s);
                break;
            }
            case 5:
            {
                exit(0);

            }
            default:
            {
                printf("Select from the given options:");
               
                break;
            }
        }
    }while(c!=5);
}

void push(struct stack *s, int val)
{
    if(s->top == N-1)
    {
        printf("Stack is full");
       
    } else{
        s->top++;
        s->n[s->top] = val;
        printf("%d is pushed \n",s->n[s->top]);
       
    }
}

void pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty, underflow");
       
    }else{
        printf("\n %d is poped \n",s->n[s->top]);
        s->top--;
       
    }
}

void show(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty");
       

    }else{
        printf("VALUES IN STACK:\n");
        for(int i=s->top;i>=0;i--){
            printf("%d\t",s->n[i]);
        }

       
    }
}

void tos(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty, underflow");
      
    }else{
        printf("\n %d is top value of stack \n",s->n[s->top]);
       
       
    }
}