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
void insertAtFront()
{
    newptr = getnode();
    if (head != NULL)
    {
        newptr->next = head;
        head->prev = newptr;
    }
    printf("%d is inserted", newptr->info);
    head = newptr;
}
void insertAtLast()
{
    newptr = getnode();
    if (head != NULL)
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newptr;
        newptr->prev = ptr;
    }
    else
    {
        head = newptr;
    }
    printf("%d is inserted", newptr->info);
}
void insertAnywhere()
{
    int key;
    if (head != NULL)
    {
        newptr = getnode();
        ptr = head;
        printf("enter key:");
        scanf("%d", &key);
        while (ptr != NULL && ptr->info != key)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("\nnode with key does not exist");
        }
        else
        {

            newptr->next = ptr->next;
            ptr->next = newptr;
            ptr->next->prev = newptr;
            newptr->prev = ptr;
            printf("%d is inserted", newptr->info);
        }
    }
    else
    {
        insertAtFront();
    }
}
void insert()
{
    int ch;
    if (head != NULL)
    { 
       
        do{
            system("cls");
            printf("1.INSERT at FRONT\n2.INSERT  at LAST \n3.INSERT ANYWHERE \n4. PRESS ENTER TO EXIT\n SELECT FROM OPTION :");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                insertAtFront();
                break;
            case 2:
                insertAtLast();
                break;
            case 3:
                insertAnywhere();
                break;
            default:
            printf("press enter");
                return;
            }
          
        } while (ch!=4);
    }
    else
    {
        insertAtFront();
    }
}

void deleteFromFront()
{
    if (head == NULL)
    {
        printf("linked list is empty!!");
    }
    else
    {
        ptr = head;
        if (head->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            head = NULL;
        }
        printf("%d is deleted", ptr->info);
        free(ptr);
    }
}
void deleteFromLast()
{
    if (head == NULL)
    {
        printf("linked list is empty!!");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("%d is deleted", ptr->info);
        if (ptr->prev != NULL)
        {
            ptr->prev->next = NULL;
        }
        else
        {
            head = NULL;
        }
        free(ptr);
    }
}
void deleteFromAnywhere()
{
    int key;
    if (head == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        printf("enter key");
        scanf("%d", &key);
        ptr = head;
        while (ptr != NULL && ptr->info != key)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("data with %d does not exist", key);
        }
        else
        {
            if (ptr->prev != NULL)
            {
                if (ptr->next != NULL)
                {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }
                else
                {
                    ptr->prev->next = NULL;
                }
            }
            else
            {
                if (ptr->next)
                {
                    ptr->next->prev = NULL;
                    head = ptr->next;
                }
                else
                {
                    head = NULL;
                }
            }
            printf("%d is deleted", ptr->info);
            free(ptr);
        }
    }
}
void delete()
{
    int ch;
    if (head != NULL)
    {
        
        while (1) {
            system("cls");
            printf("1.DELETE at FRONT\n2.DELETE at LAST\n3.DELTE ANYWHERE\nPRESS ENTER TO EXIT\n Select your option:");
            scanf("%d", &ch);
            switch (ch)
            {
            case 1:
                deleteFromFront();
                break;
            case 2:
                deleteFromLast();
                break;
            case 3:
                deleteFromAnywhere();
                break;
            default:
            return;
            }
           
        }
    }
    else
    {
        printf("doubly linked list is empty!!");
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
        insert();
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