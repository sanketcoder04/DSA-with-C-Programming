#include<stdio.h>
#include<stdlib.h>
#define max 4

int arr[max];
int front = -1;
int rear = -1;

void create(){
    int i=0 , ch;
    //front = rear = 0;
    printf("Enter data:");
    scanf("%d",&arr[i]);
    //printf("Entered Item %d\n",arr[i]);
    front = (front+1)%max;
    rear = (rear+1)%max;
    printf("Continue?Press 1/0");
    scanf("%d",&ch);
    i=(i+1)%max;
    while(ch == 1){
        printf("Enter data:");
        scanf("%d",&arr[i]);
        //printf("Entered Item %d\n",arr[i]);
        rear = (rear+1)%max;
        printf("Continue?Press 1/0");
        scanf("%d",&ch);
        i=(i+1)%max;
    }
}

void display(){
    int i = front;
    int j = rear;
    if(i<=j){
        while(i<=j){
            printf("%d\t",arr[i]);
            i++;
        }
    }else{
        while(i<=max-1){
            printf("%d\t",arr[i]);
            i++;
        }
        i=0;
        while(i<=j){
            printf("%d\t",arr[i]);
            i++;
        }
    }
    printf("\n");
}

void enqueue(int data){
    if((rear+1)%max == front){
        printf("Queue Overflow");
        return;
    }
    rear = (rear+1)%max;
    arr[rear] = data;
    printf("Enqueued Item is %d\n",arr[rear]);
}

void dequeue(){
    if(front == rear){
        printf("Queue Underflow");
        return;
    }
    printf("Dequeued Item is %d\n",arr[front]);
    front = (front+1)%max;
}
int main(){
    create();
    display();
    enqueue(9);
    display();
    dequeue();
    dequeue();
    dequeue();
    enqueue(11);
    enqueue(13);
    display();
}