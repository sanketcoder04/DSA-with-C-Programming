#include<stdio.h>
#include<stdlib.h>
#define max 10

int arr[max];
int top = -1;

void create(){
    int i = 0;
    int ch;
    if(top == max-1){
        printf("Stack is Overflow");
        return;
    }
    do{
        printf("Enter data in Stack:");
        scanf("%d",&arr[i]);
        i++;
        top++;
        printf("Continue press 1/0");
        scanf("%d",&ch);
    }while(ch == 1);    
}

void display(){
    for(int i = 0;i<=top;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Top Value is %d\n",top);
}

void push(int data){
    if(top == max-1){
        printf("Stack is Overflow");
        return;
    }
    top++;
    arr[top] = data;
}

void pop(){
    if(top == -1){
        printf("Stack is Underflow");
        return;
    }
    printf("Popped item is %d\n",arr[top]);
    top--;
}
int main(){
    create();
    display();
    push(7);
    display();
    pop();
    display();
    return 0;
}