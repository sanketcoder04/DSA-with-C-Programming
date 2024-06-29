#include<stdio.h>
#include<stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
struct stack *top;

void create(){
    struct stack *ptr1;
    int ch;
    if(ptr1 == NULL){
        printf("Memory Overflow");
        exit(0);
    }
    ptr1 = (struct stack*)malloc(sizeof(struct stack));
    printf("Enter data:");
    scanf("%d",&ptr1->data);
    ptr1->next = NULL;
    printf("Continue?Press 1/0");
    scanf("%d",&ch);
    while(ch == 1){
        struct stack* ptr2 = (struct stack*)malloc(sizeof(struct stack));
        printf("Enter data:");
        scanf("%d",&ptr2->data);
        ptr2->next = ptr1;
        ptr1 = ptr2;
        printf("Continue?Press 1/0");
        scanf("%d",&ch);
    }
    top = ptr1;
}

void display(){
    struct stack* ptr = top;
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void push(int data){
    struct stack* ptr;
    ptr = (struct stack*)malloc(sizeof(struct stack));
    if(ptr == NULL){
        printf("Memory Overflow");
        return;
    }
    ptr->data = data;
    ptr->next = top;
    top = ptr;
}

void pop(){
    struct stack* ptr;
    ptr = top;
    if(ptr == NULL){
        printf("Stack is Underflow");
        return;
    }
    printf("Popped Item is %d\n",ptr->data);
    top = ptr->next;
    free(ptr);
}
int main(){
    create();
    display();
    push(9);
    push(4);
    display();
    pop();
    display();
    return 0;
}