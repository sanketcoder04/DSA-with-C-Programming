#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* create(struct Node* head){
    struct Node* ptr , *fix1 , *fix2;
    int n;
    ptr = head;
    printf("Enter data:");
    scanf("%d",&ptr->data);
    fix1 = ptr;
    printf("Continue?Press 1/0:");
    scanf("%d",&n);
    while(n==1){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&newNode->data);
        ptr->next = newNode;
        newNode->prev = ptr;
        ptr = newNode;
        printf("Continue?Press 1/0:");
        scanf("%d",&n);
        fix2 = ptr;
    }
    fix2->next = fix1;
    fix1->prev = fix2;
    return fix1;
}

void print(struct Node* head){
    struct Node* ptr = head;
    do{
        printf("%d <-> ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("NULL\n");
}

int main(){

    //Declaration of Nodes manually

    struct Node *head;
    // struct Node *first;
    // struct Node *second;
    // struct Node *third;

    // Memory allocation for each Node

    head = (struct Node*)malloc(sizeof(struct Node));
    // first = (struct Node*)malloc(sizeof(struct Node));
    // second = (struct Node*)malloc(sizeof(struct Node));
    // third = (struct Node*)malloc(sizeof(struct Node));

    // //Insert data at head and points to first

    // head->data = 2;
    // head->next = first;
    // head->prev = third;

    // //Insert data at first and points to fsecond

    // first->data = 6;
    // first->next = second;
    // first->prev = head;

    // //Insert data at second and points to fthird

    // second->data = 9;
    // second->next = third;
    // second->prev = first; 

    // //Insert data at third and points to NULL

    // third->data = 1;
    // third->next = head;
    // third->prev = second;

    head = create(head);
    print(head);
    return 0;
}
