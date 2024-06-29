#include<stdio.h>
#include<stdlib.h>

struct Queues{
    int data;
    struct Queues *next;
};
struct Queues *front,*rear;

void create(){
    struct Queues *ptr1,*ptr2;
    int choice;
    ptr1 = (struct Queues*)malloc(sizeof(struct Queues));
    printf("Enter data:");
    scanf("%d",&ptr1->data);
    front = rear = ptr1;
    printf("Continue? Enter 1/0");
    scanf("%d",&choice);

    while(choice == 1){
        ptr2 = (struct Queues*)malloc(sizeof(struct Queues));
        printf("Enter data:");
        scanf("%d",&ptr2->data);
        ptr1->next = ptr2;
        ptr1 = ptr2;
        printf("Continue? Enter 1/0");
        scanf("%d",&choice);
    }
    ptr1->next = NULL;
    rear = ptr1;
}
void display(){
    struct Queues *ptr;
    ptr = front;
    if(ptr == NULL){
        printf("Empty Queue");
        return;
    }
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(int value){
    struct Queues *ptr;
    ptr = (struct Queues*)malloc(sizeof(struct Queues));
    if(ptr == NULL){
        printf("Memory Overflow");
        return;
    }
    ptr->data = value;
    rear->next = ptr;
    rear = ptr;
    rear->next = NULL;
}

void delete(){
    struct Queues *ptr1,*ptr2;
    ptr1 = front->next;
    ptr2 = front;
    if(ptr1 == ptr2 == NULL){
        printf("Empty Queue");
        return;
    }
    front = ptr1;
    free(ptr2);
}
int main(){
    create();
    display();
    insert(7);
    display();
    delete();
    display();
}