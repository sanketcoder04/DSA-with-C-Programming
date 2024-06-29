#include<stdio.h>
void selection_sort(int [],int);
void main()
{
    int a[100],n,i;
    
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter %d elements into array :\n",n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    printf("Before sorting\n");
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
 
    selection_sort(a,n); //Function Call for Selection Sort

    printf("After sorting\n");
    for(i=0;i<n;i++)
       printf("%d ",a[i]);
}

void selection_sort(int a[],int n)
{
     int i,j,max,loc;
 
     for(i=1;i<n;i++)
     {
        max=a[0];
        loc=0;
        for(j=1;j<=n-i;j++)
        {
            if(a[j]>max)
            {
               max=a[j];
               loc=j;
            }
        }
        a[loc]=a[n-i];
        a[n-i]=max;
     }
}
