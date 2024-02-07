#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
 struct list {
    int info;
    struct list *next;
 };
 typedef struct list node;
 node *start;

 void insert_node_begining()
 {
    node *item;
    item = (node *)malloc(sizeof(node));
    printf("Enter the data to insert:");
    scanf("%d",&item->info);
    if(start == NULL){
        item->next=NULL;
        start= item;
    }else {
    item->next = start;
    start = item;
    }
 }

 void insert_node_last(){
    node *item, *temp;
    item = (node *)malloc(sizeof(node));
    printf("Enter the data to insert:");
    scanf("%d",&item->info);
    item->next= NULL;
    if(start==NULL){
        start = item;
    }else {
    temp=start;
    while (temp->next!=NULL) {
        temp=temp->next;
    
    }

        temp->next=item;
        item->next=NULL;

    }
 }

 void insert_node_specific(){
    node *item,*temp;
    item = (node *)malloc(sizeof(node));
    int key;
    printf("Enter the number after which you want to put your data:");
    scanf("%d",&key);
    printf("Enter the actual data to insert:");
    scanf("%d",&item->info);
    temp= start;
    while (temp->next!=NULL && temp->info!=key) {
        
        temp = temp->next;
        
        
    }
        item->next = temp->next;
         temp->next = item;


 }

 void show_data(){
    node *temp;
    printf("\nElements in the lists are:\n");
    temp = start;
    while (temp!=NULL) {
        printf("%d\t",temp->info);
        temp=temp->next;
    
    }
 }

 int main(){
    int ch;
    
    do {
        system("clear");
        printf("\n1.Enter at first \t2.Enter at last \t3.Enter at anywhere \t4. ShowData \n");
        printf("Enter your choice :");
        scanf("%d",&ch);
    switch (ch) {
        case 1:
        insert_node_begining();
        break;
        case 2:
        insert_node_last();
        break;
        case 3:
        insert_node_specific();
        break;
        case 4:
        show_data();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("choose from the option:");
    
    }
    }while (ch!=5);
    

    return 0;
 }