#include<stdio.h>
#include<stdlib.h>
#define max 10

int arr[max];
int front = -1;
int rear = -1;

void create(){
    int i = 0 , ch;
    front++;
    rear++;
    printf("Enter data:");
    scanf("%d",&arr[i]);
    printf("Continue?Press 1/0");
    scanf("%d",&ch);
    i++;
    while(ch == 1){
        printf("Enter data:");
        scanf("%d",&arr[i]);
        rear++;
        printf("Continue?Press 1/0");
        scanf("%d",&ch);
        i++;
    }
}

void display(){
    for(int i=front;i<=rear;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("Front value is %d\n",front);
    printf("Rear value is %d\n",rear);
}

void insert(int value){
    if(rear == max-1){
        printf("Quene is Overflow");
        return;
    }
    rear++;
    arr[rear] = value;
}

void delete(){
    if(front == -1 || front == rear){
        printf("Quene is Underflow");
        return;
    }
    printf("Deleted item is %d\n",arr[front]);
    front++;
}
int main(){
    create();
    display();
    insert(5);
    display();
    delete();
    display();
}