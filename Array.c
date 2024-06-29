#include<stdio.h>
#include<stdlib.h>
#define max 20
void scan(int arr[max],int size){
    printf("Enter Elements of Array\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }  
}
void display(int arr[max],int size){
    for(int i=0;i<size;i++){
        printf("arr[%d]=%d\t",i,arr[i]);
    }
}
int addFirst(int arr[max],int size){
    int addElement;
    printf("Enter the Element You want to Add:");
    scanf("%d",&addElement);
    for(int i=size-1;i>=0;i--){
        arr[i+1] = arr[i]; 
    }
    arr[0] = addElement;
    return size+1;
}
int addLast(int arr[max],int size){
    int addElement;
    printf("Enter the Element You want to Add:");
    scanf("%d",&addElement);
    arr[size] = addElement;
    return size+1;
}
int insert(int arr[max],int size){
    int addElement,position;
    printf("Enter the Element You want to Add:");
    scanf("%d",&addElement);
    printf("Enter Location You want to Insert:");
    scanf("%d",&position);
    for(int i=0;i<size;i++){
        if(i==position){
            for(int j=size;j>=position;j--){
                arr[j+1]=arr[j];
            }
            arr[position] = addElement;
        }
    }
    return size+1;
}
int deleteFirst(int arr[max],int size){
    for(int i=0;i<=size;i++){
        arr[i] = arr[i+1];
    }
    return size-1;
}
int deleteLast(int arr[max],int size){
    return size-1;
}
int delete(int arr[max],int size){
    int position;
    printf("Enter the Position at which You want Deletition:");
    scanf("%d",&position);
    for(int i=0;i<size;i++){
        if(i==position){
            for(int i=position;i<size;i++){
                arr[i] = arr[i+1];
            }
        }
    }
    return size-1;
}
void sortArr(int arr[max],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void reverse(int arr[max],int size){
    for(int k=0;k<size/2;k++){
        int firstVal = arr[k];
        int secondVal = arr[size-k-1];
        arr[k] = secondVal;
        arr[size-k-1] = firstVal;
    }
}
int main(){
    //Operations for Single Array

    int arr[max],size;
    printf("Enter Size:");
    scanf("%d",&size);
    scan(arr,size);
    reverse(arr,size);
    printf("Size of Array is %d\n",size);
    display(arr,size);
}