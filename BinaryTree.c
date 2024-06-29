#include<stdio.h>
#include<stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* create_Node(){
    struct Tree* newNode = (struct Tree*)malloc(sizeof(struct Tree));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert_data(struct Tree* root,struct Tree* newNode){
    int choice;
    printf("Enter where you want to insert Left->0 & Right->1 of Node %d:",root->data);
    scanf("%d",&choice);

    if(choice == 0){
        if(root->left == NULL){
            root->left = newNode;
        }else{
            insert_data(root->left,newNode);
        }
    }
    if(choice == 1){
        if(root->right == NULL){
            root->right = newNode;
        }else{
            insert_data(root->right,newNode);
        }
    }
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

            //     5
            //    / \
            //   4   7
            //  /\   /\
            // 3  2 6  8
            //  PreOrder - 5432768
            //  Postorder - 3246875
            //  Inorder - 3425678
int main(){ 
    struct Tree* root = NULL;
    int choice,other_choice;

    while(1){
        printf("\n");
        printf("Enter 1 for Create :\n");
        printf("Enter 2 for PostOrder Traversal :\n");
        printf("Enter 3 for InOrder Traversal :\n");
        printf("Enter 4 for PreOrder Traversal :\n");
        printf("Enter 5 for Exit :\n");
        scanf("%d",&choice);

        switch(choice){
            case 1 : do{
                        struct Tree* newNode = create_Node();
                        printf("Enter data:");
                        scanf("%d",&newNode->data);
                        if(root == NULL){
                            root = newNode;
                        }else{
                            insert_data(root,newNode);
                        }
                        printf("Continue? Press 1/0:");
                        scanf("%d",&other_choice);
                     }while(other_choice == 1);
                     break;
            
            case 2 : postOrder(root);
                     break;

            case 3 : inOrder(root);
                     break;

            case 4 : preOrder(root);
                     break;

            case 5 : exit(0);
        }
    }
    return 0;
}