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
struct node *min_Value_of_Node(struct node *node) {
    struct node *current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}
struct node *delete_Node(struct node *root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = delete_Node(root->left, key);
    }
    else if (key > root->data) {
        root->right = delete_Node(root->right, key);
    }
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            printf("%d is deleted\n", root->data);
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            printf("%d is deleted\n", root->data);
            free(root);
            return temp;
        }

        struct node *temp = min_Value_of_Node(root->right);
        root->data = temp->data;
        root->right = delete_Node(root->right, temp->data);
    }
    return root;
}
void create() {
    char ch;
    int value;
    do {
        printf("Enter data: ");
        scanf("%d", &value);

        if (root == NULL) {
            root = insert_key(root, value);
            printf("Root created\n");
        }
        else {
            insert_key(root, value);
        }
        printf("Choose (y/Y) to enter more data: ");
        scanf(" %c", &ch);
        

    } while (ch == 'y' || ch == 'Y');
}
void inorder_Traversal(struct node *root) {
    if (root != NULL) {
        inorder_Traversal(root->left);
        printf("%d ", root->data);
        inorder_Traversal(root->right);
    }
}

void preorder_Traversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_Traversal(root->left);
        preorder_Traversal(root->right);
    }
}

void postorder_Traversal(struct node *root) {
    if (root != NULL) {
        postorder_Traversal(root->left);
        postorder_Traversal(root->right);
        printf("%d ", root->data);
    }
}

struct node *search_key(struct node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search_key(root->left, value);
    }
    else {
        return search_key(root->right, value);
    }
}
void show_BST() {
    int ch;
    while (1) {
        printf("\n1. Preorder\n2. Postorder\n3. Inorder\n");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("Pre-oreder Traversal:\n");
            preorder_Traversal(root);
            break;
        case 2:
            printf("In-oreder Traversal:\n");
            inorder_Traversal(root);
            break;
        case 3:
            printf("Post-oreder Traversal:\n");
            postorder_Traversal(root);
            break;
       
        default:
            printf("Press spaces to return\n");
            return;
        }
    }

}
void insertNew() {
    
    int value;
    printf("Enter value to be inserted: ");
    scanf("%d", &value);
    insert_key(root, value);
}
void node_Deletion() {
    int value;
    printf("Enter value to be deleted: ");
    scanf("%d", &value);
    root = delete_Node(root, value);
}

void search_specific_key() {
    int value;
    
    printf("Enter value to be searched: ");
    scanf("%d", &value);
    struct node *result = search_key(root, value);
    if (result != NULL) {
        printf("%d found in the tree\n", value);
    }
    else {
        printf("%d not found in the tree\n", value);
    }
}

int main() {
    int choice;
    create();

    while (1) {
        printf("1. INSERT\n2. DELETE\n3. SEARCH\n4. SHOW\n5. EXIT\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            insertNew();
            break;
        case 2:
            node_Deletion();
            break;
        case 3:
            search_specific_key();
            break;
        case 4:
            show_BST();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Choose a valid option:\n");
        }
    }

    return 0;
}