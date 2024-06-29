#include<stdio.h>
int partitioning(int[],int,int);
void swap(int[],int,int);
void quick_sort(int[],int,int);

void main()
{
    int i,n;
    int a[100];
    /*int a[]={4,5,4,5,6,7,8,6,7};
    n=9;*/
    printf("Enter number of values :");
    scanf("%d",&n);
    printf("Enter values into the array :\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nBefore Sorting\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    quick_sort(a,0,n-1);
    printf("\nAfter Sorting\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

void quick_sort(int a[],int low,int up)
{
   int k;
   if(up<low) return;
   k=partitioning(a,low,up);
   quick_sort(a,low,k-1);
   quick_sort(a,k+1,up);

}

int partitioning(int a[],int low,int up)
{
    int i,j,pivot;
    pivot=up;
    i=low-1;
    j=up;
    while(i<j)
    {
        while(a[++i]<=a[pivot] && i<j);
        while(a[--j]>=a[pivot] && j>i);
        if(i<j) swap(a,i,j);
    }
    if(i<pivot) swap(a,i,pivot);
    return i;
}

void swap(int a[],int i,int j)
{
   int tmp=a[i];
   a[i]=a[j];
   a[j]=tmp;
}
