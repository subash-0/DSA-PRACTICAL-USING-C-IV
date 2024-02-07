#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *head=NULL,*ptr,*newptr,*prevptr;
struct node* getnode()
{
    struct node* np;
    np=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&np->info);
    np->next =NULL;
    return np;
};
 void create(){
    struct node *temp;
    char ch;
    do {
    newptr = getnode();
    if(head == NULL){
        head = newptr;
    }else {
    temp->next = newptr;
    }
    newptr->next = head;
    temp = newptr;
    printf("Woul you like to add more data:(Y/N)");
    scanf(" %c",&ch);
    }while (ch == 'y' || ch=='Y');
 }


 void display(){
    if(head!=NULL){
        ptr = head;
        printf("Datas in the circular list are:\n");
        do {
        printf("%d \t",ptr->info);
        ptr = ptr->next;
        }while (ptr!=head);
    }else {
    printf("Circular link list is empty !");
    }
 }

void insertInCList(){
    int key; 
    newptr = getnode();
    if (head != NULL) {
        printf("Enter the key after which you want to put:");
        scanf("%d",&key);

        ptr = head;
        do{
            ptr = ptr->next;
        }while (ptr->info !=key && ptr!=head);

        if(ptr->info!=key){
            printf("Node with key does not exist .");

        }else { 
            printf("%d is inserted !",newptr->info);
            newptr->next = ptr->next;
            ptr->next = newptr;
        
        }
    }
    else {
        head = newptr;
        newptr->next = head;
        printf("%d is inserted",newptr->info);
    }
}
 int main(){
    create();
    int c;
   
    do{
    printf("\n1.INSERT \t 2. DISPLAY \t 3. DELETE \t 4. EXIT \n Enter from options: ");
    scanf("%d",&c);
         switch (c) {
        case 1:
        insertInCList();
        break;
        case 2:
        display();
        break;
        case 3:
        printf("DELETE FUNCTION WILL BE CREATED SOON !");
        break;
        case 4:
        exit(0);
        default:
        printf("No such option available !");
    
    }
    
    }while(1);
   
    
    return 0;
 }