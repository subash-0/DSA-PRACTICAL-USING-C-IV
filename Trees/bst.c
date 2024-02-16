#include <stdio.h>  
#include <stdlib.h>  
  
struct node {  
  int data;  
  struct node *right;  
  struct node *left;  
};  
struct node * root=NULL,*temp;

struct node* get_new_node(){  
  temp = malloc(sizeof(struct node));  
  int x;
  printf("Enter data:");
  scanf("%d",&x);
  temp->data= x;
  temp->left= NULL;  
  temp->right = NULL;  

  return temp;
}  

  
int main() {  

  printf("BST IS IMPLEMENTING ....");
  return 0;  
}