#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create(struct Node* head){
    struct Node* ptr;
    int n;
    printf("Enter data:");
    scanf("%d",&head->data);
    head->prev = NULL;
    printf("Continue?Press 1/0:");
    scanf("%d",&n);
    ptr = head;
    while(n == 1){
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d",&newNode->data);
        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = NULL;
        ptr = newNode;
        printf("Continue?Press 1/0:");
        scanf("%d",&n);
    }
    ptr->next = NULL;
    return head;
}

void print(struct Node* head){
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("%d <-> ",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct Node* sort(struct Node* head){
    struct Node *ptr = head,*ptr2;
    while(ptr->next != NULL){
        ptr2 = ptr->next;
        while(ptr2 != NULL){
            if(ptr->data > ptr2->data){
                int temp = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }
    return head;
}

struct Node* reverse(struct Node* head){
    struct Node* ptr1 = head;
    struct Node* ptr2 = NULL;
    while(ptr1 != NULL){
        ptr2 = ptr1->prev;
        ptr1->prev = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr1->prev;
    }
    if(ptr2 != NULL){
        head = ptr2->prev; // Update the head if needed
    }
    return head;
}

int main(){
    struct Node* head;
    struct Node* first;
    struct Node* second;
    struct Node* third;

    head = (struct Node*)malloc(sizeof(struct Node));
    first = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->prev = NULL;
    head->next = first;

    first->data = 7;
    first->prev = head;
    first->next = second;

    second->data = 6;
    second->prev = first;
    second->next = third;

    third->data = 3;
    third->prev = second;
    third->next = NULL;

    print(head);
    head = reverse(head);
    print(head);
    return 0;
}