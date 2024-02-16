#include <stdio.h>  
#include <stdlib.h>  
  
struct node {  
  int data;  
  struct node *right;  
  struct node *left;  
};  
struct node * root=NULL,*temp;

struct node* get_new_node(int x){  
  temp = malloc(sizeof(struct node));  
  printf("Enter data:");
  scanf("%d",&x);
  temp->data= x;
  temp->left= NULL;  
  temp->right = NULL;  

  return temp;
}  

struct node *insert_key(struct node *root, int key) {
    if (root == NULL) {
        return get_new_node(key);
    }
    if (key < root->data) {
        root->left = insert_key(root->left, key);
        printf("inserted left of %d\n", root->data);
    }
    else if (key > root->data) {
        root->right = insert_key(root->right, key);
        printf("inserted right of %d\n", root->data);
    }
    return root;
}
  
int main() {  

  printf("BST IS IMPLEMENTING ....");
  return 0;  
}