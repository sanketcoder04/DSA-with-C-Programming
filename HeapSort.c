#include<stdio.h>

void heap_sort(int [],int);
void heap_creation(int [],int);
void restore_down(int [],int,int);

void main()
{
    int a[100],n,i;
    
    printf("Enter the number of elements :");
    scanf("%d",&n);
    
    printf("Enter the values into the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\nBEFORE SORTING\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nAFTER SORTING\n");
    heap_sort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

void heap_sort(int a[],int n)
{
    int i,temp;
    for(i=n-1;i>0;i--)
    {
       heap_creation(a,i);
       temp=a[0];
       a[0]=a[i];
       a[i]=temp;
    }
}

void heap_creation(int a[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
        restore_down(a,i,n);
}

void restore_down(int a[],int i,int size)
{
    int node,left,right;
    node=a[i];
    left=2*i+1;
    right=left+1;
    while(right<=size)
    {
        if(node>=a[left] && node>=a[right])
        {
            a[i]=node;
            return;
        }
        else if(a[left]>a[right])
        {
            a[i]=a[left];
            i=left;
        }
        else
        {
            a[i]=a[right];
            i=right;
        }
        left=2*i+1;
        right=left+1;
    }
    if(left==size && a[left]>node)
    {
        a[i]=a[left];
        i=left;
    }
    a[i]=node;
}

