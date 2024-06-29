#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* create(struct Node* head){
    struct Node* ptr = head;
    struct Node* newNode;
    int ch;
    printf("Enter data:");
    scanf("%d",&ptr->data);
    printf("Continue?Press 1/0:");
    scanf("%d",&ch);
    while(ch == 1){
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&newNode->data);
        ptr->next = newNode;
        ptr = newNode;
        ptr->next = head;
        printf("Continue?Press 1/0:");
        scanf("%d",&ch);
    }
    //ptr->next = head;
    return head;
}

void print(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("%d -> ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("HEAD(%d)\n",head->data);
}

int size(struct Node* head){
    struct Node* ptr = head;
    int size = 0;
    do{
        size++;
        ptr = ptr->next;
    }while(ptr != head);
    return size;
}

void addIndex(struct Node* head,int index){
    
}

int main(){

    //Declaration of Nodes manually

    struct Node *head;
    // struct Node *first;
    // struct Node *second;
    // struct Node *third;

    // // //Memory allocation for each Node

    head = (struct Node*)malloc(sizeof(struct Node));
    // first = (struct Node*)malloc(sizeof(struct Node));
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));

    // //Insert data at head and points to first

    // head->data = 2;
    // head->next = first;

    // //Insert data at first and points to fsecond

    // first->data = 6;
    // first->next = second;

    // //Insert data at second and points to fthird

    // second->data = 9;
    // second->next = third;

    // //Insert data at third and points to NULL

    // third->data = 1;
    // third->next = head;
    head = create(head);
    print(head);
    int length = size(head);
    printf("Length is %d\n",length);
    return 0;
}
