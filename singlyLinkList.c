#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head=NULL,*ptr,*newptr;
struct node* getnode()
{
    struct node* np;
    np=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&np->info);
    np->next =NULL;
    return np;
};
void create()
{
    struct node *last;
    char ch;
    do 
    {
        newptr= getnode();
        if(head== NULL)
        head=newptr;
        else
        {
            last->next=newptr;
        }
        last=newptr;
        printf("do you want to add moer(y/n)");
        scanf(" %c",&ch);
    }
     while(ch=='Y' || ch=='y');
}
void display()
{
    ptr=head;
    printf("the elemlens are \n");
    while(ptr !=NULL)
    {
        printf("%d\t",ptr->info);
        ptr=ptr->next;
    }
}
void insert_at_specific(){
          int selectKey;
    if(head !=NULL){
        printf("Select a key:");
        scanf("%d",&selectKey);
        ptr = head;
        while (ptr!=NULL && ptr->info!=selectKey ) {
            ptr=ptr->next;
        
        }
        if(ptr==NULL){
            printf("node with %d as key doesn't exits",selectKey);

        }else {
            newptr = getnode();
            newptr->next = ptr->next;
            ptr->next = newptr;
        }
    }
  
}
void insert_at_begning(){
    struct node *temp;
    printf("\n\t\tEnter the key to insert:");
    scanf("%d",&temp->info);
    if (head==NULL) {
        temp->next=NULL;
        head=temp;
    
    }else {
    temp->next = head;
    head = temp;
    }
    printf("\n\t\t%d is inserted at begining\n",temp->info);
}
void insert_at_last(){

    struct node *temp,*last;
    printf("\n\t\tEnter the info:");
    scanf("%d",&temp->info);
    temp->next=NULL;
    if(head == NULL){
        head = temp;
    }else {
        last = head;
        while (last->next!=NULL) {
            last=last->next;
        }
        last->next =temp;
        
    
    }
    
}
void insert()
{
    int choice;
    printf("\nWhere do you want to insert: \n1. At begning\t 2.At Specified Possiton \t 3. At End \n");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
        insert_at_begning();
        break;
        case 2:
        insert_at_specific();
        break;
        case 3:
        insert_at_last();
        break;
        default:
        printf("\nNo options available .");
    
    }
  

}

void deleteFromFront(){
    if(head == NULL){
        printf("List is empty");
    }else {
    ptr = head;
    printf("%d is deleted !", ptr->info);
    head = head->next;
    free(ptr);
    }

}
void deleteFromRandom(){
    struct node *prevptr= NULL;
    int key;
    if(head == NULL){
        printf("List is empty !");
    }else {
        printf("enter the key to delete:");
        scanf("%d",&key);
        ptr = head;
        while (ptr!=NULL && ptr->info!=key) {
        prevptr = ptr;
        ptr=ptr->next;
        }

        if(ptr==NULL){
            printf("node with key :%d doesn't exist.",key);
        return;
        }
        printf("%d is deleted",ptr->info);
        if(prevptr)
        prevptr->next = ptr->next;
        else
        head=ptr->next;
    free(ptr);
       
    }
    

}
void deleteFromLast(){
    struct node *prevptr = NULL;
    if (head == NULL) {
        printf("List is empty");
    
    }else {
        ptr = head;
        while (ptr->next!=NULL) {
            prevptr = ptr;
            ptr = ptr->next;
        
        }
        printf("%d is deleted !",ptr->info);
        if(!prevptr){
            head = NULL;
        }else {
            prevptr->next = NULL;
        }
        free(ptr);
    
    }

}
void delete()
{
    int ch;
    printf("\n\t1. Delete front \t 2. Delete from random \t 3. Delete from last \n Select Option:");
    scanf("%d",&ch);
    switch (ch) {
        case 1:
        deleteFromFront();
        break;
        case 2:
        deleteFromRandom();
        break;
        case 3:
        deleteFromLast();
        break;
        default:
        printf("No such option available:");
        break;
    }
}
int main()
{
    int choice;
    system("cls");
    create();
    while(1){
    printf("\nLinked list \n1 insert\n2 delete\n3 display \n4 exit");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:  insert();
        break;
        case 2: delete();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        break;
        default:printf("invalid data");
    }
    
    }
    return 0;
}