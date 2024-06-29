#include<stdio.h>
int main(){
    int arr[100],n,search,index;
    printf("Enter Size of the Array: ");
    scanf("%d",&n);
    printf("Enter an Array\n");
    for(int i=0;i<n;i++){
        printf("Enter Elements: ");
        scanf("%d",&arr[i]);
    }
    printf("Enter the Element You Want to Search:");
    scanf("%d",&search);
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i] == search){
            index=i;
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("Element Found at Index: %d\n",index);
    }else{
        printf("Element Not Found\n");
    }
    return 0;
}
