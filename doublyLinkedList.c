#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL,*ptr,*newptr;

struct node* getnode()
{
    struct node* np;
    np=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&np->info);
    np->next =NULL;
    np->prev = NULL;
    return np;
};

void createList(){
    char ch;
    do {
        newptr = getnode();
    if (head == NULL) {
        head = newptr;
    }else {
        ptr->next = newptr;
        newptr->prev = ptr;
     }
    ptr = newptr;
    printf("Would you like to add more data:(Y/N)");
    scanf(" %c",&ch);
    }while (ch == 'y' || ch=='Y');
}
void display(){
    ptr = head;
    printf("Data in Doubly Link List are:\n");
    while (ptr!=NULL) {
        printf("%d\t",ptr->info);
        ptr=ptr->next;
    
    }

}
int main(){
        int c;
     createList();
     
     do {
     printf("\n1.INSERT \t 2. DISPLAY \t 3. DELETE \t 4.EXIT \n Enter your choice:");
     scanf("%d",&c);
     switch (c) {
        case 1:
        printf("Insertion function is going to be created soon !");
        break;
        case 2:
        display();
        break;
        case 3:
        printf("Deletion will be provided soon!");
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("No such option is available.");
     
     }
     }while (c!=4);
    return 0;
}