#include<stdio.h>
int binarySearch(int arr[],int low,int high,int search){
    int mid = (low+high)/2;
    if(low>high){
        return -1;
    }
    else if(search == arr[mid]){
        return mid;
    }
    else if(search>arr[mid]){
        return binarySearch(arr,mid+1,high,search);
    }else{
        return binarySearch(arr,low,mid,search);
    }
}
int main(){
    int arr[100], n, search, location;
    printf("Enter Size of The Array:");
    scanf("%d",&n);
    printf("Enter a Sorted Array:\n");
    for (int i = 0; i < n; i++){
        printf("Enter Elements :");
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element you Want to Search:");
    scanf("%d",&search);
    location = binarySearch(arr,0,n-1,search);
    if(location == -1){
        printf("Element Not Found\n");
    }
    else{
        printf("Index of The Element is : %d\n",location);
    }
    return 0;
}