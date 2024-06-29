#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* createNode(int data){
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Tree* insert_Data(struct Tree* root,int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert_Data(root->left,data); 
    }
    if(data > root->data){
        root->right = insert_Data(root->right,data);
    }
    return root;
}

void preOrder(struct Tree* root){   //Recursive
    struct Tree* ptr = root;
    if(ptr != NULL){
        printf("%d\t",ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(struct Tree* root){    //Recursive
    struct Tree* ptr = root;
    if(ptr != NULL){
        inOrder(ptr->left);
        printf("%d\t",ptr->data);
        inOrder(ptr->right);
    }
}

void postOrder(struct Tree* root){  //Recursive
    struct Tree* ptr = root;
    if(ptr != NULL){
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d\t",ptr->data);
    }
}

int checkBST(struct Tree* root){
    static struct Tree* prev = NULL;
    if(root != NULL){
        if(checkBST(root->left) != 1){
            return 0;
        }
        if(prev != NULL && prev->data >= root->data){
            return 0;
        }
        prev = root;
        return checkBST(root->right);
    }
    else{
        return 1;
    }
}

int searchNode(struct Tree* root,int search){
    struct Tree* ptr = root;
    while(ptr != NULL){
        if(ptr->data == search){
            return 1;
        }
        else if(search < ptr->data){
            ptr = ptr->left;
        }
        else if(search > ptr->data){
            ptr = ptr->right;
        }else{
            return 0;
        }
    }
}

void insertion(struct Tree* root,int data){
    struct Tree* ptr = NULL;
    while(root != NULL){
        ptr = root;
        if(data == root->data){
            printf("Element can not be inserted\n");
            return;
        }
        if(data > root->data){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    struct Tree* newNode = createNode(data);
    if(data < ptr->data){
        ptr->left = newNode;
    }else{
        ptr->right = newNode;
    }
}

struct Tree* inOrderPredecessor(struct Tree* root){
    struct Tree* ptr = root->left;

    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    return ptr;
}

struct Tree* deletion(struct Tree* root,int data){
    struct Tree* ptr = root;
    struct Tree* inPre;
    if(root == NULL){
        return NULL;
    }
    if(ptr->left == NULL && ptr->right == NULL){
        free(ptr);
        return NULL;
    }

    if(data < ptr->data){
        ptr->left = deletion(ptr->left,data);
    }
    else if(data >ptr->data){
        ptr->right = deletion(ptr->right,data);
    }
    else{
        inPre = inOrderPredecessor(ptr);
        ptr->data = inPre->data;
        ptr->left = deletion(ptr->left,inPre->data);
    }
    return root;
}

int main(){
    struct Tree* root = NULL;
    int data,choice;

    // while(1){
    //     printf("\n");
    //     printf("Enter 1 for Create :\n");
    //     printf("Enter 2 for PostOrder Traversal :\n");
    //     printf("Enter 3 for InOrder Traversal :\n");
    //     printf("Enter 4 for PreOrder Traversal :\n");
    //     printf("Enter 5 for check BST\n");
    //     printf("Enter 6 for insertion:\n");
    //     printf("Enter 6 for Exit :\n");
    //     scanf("%d",&choice);

    //     switch(choice){
    //         case 1 : printf("Enter data:");
    //                  scanf("%d",&data);
    //                  root = insert_Data(root,data);
    //                  break;
            
    //         case 2 : postOrder(root);
    //                  break;

    //         case 3 : inOrder(root);
    //                  break;

    //         case 4 : preOrder(root);
    //                  break;

    //         case 5 : if(checkBST(root)==1){
    //                     printf("TRUE\n");
    //                  }else{
    //                     printf("FALSE\n");
    //                  }
    //         case 6 : exit(0);
    //     }
    // }

    root = insert_Data(root,12);
    root = insert_Data(root,34);
    root = insert_Data(root,9);
    root = insert_Data(root,23);
    root = insert_Data(root,36);
    inOrder(root);
    printf("\n");
    insertion(root,11);
    insertion(root,54);
    inOrder(root);
    printf("\n");
    if(searchNode(root,100)){
        printf("Element Found");
    }else{
        printf("Element not Found");
    }
    printf("\n");
    root = deletion(root,23);
    inOrder(root);
    return 0;
}