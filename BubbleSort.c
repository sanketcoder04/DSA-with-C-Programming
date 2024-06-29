#include<stdio.h>

void bubble_sort(int [],int);

void main()
{
   int a[100],i,n;
   printf("Enter the number of elements :");
   scanf("%d",&n);
   printf("Enter values into the array\n");
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   printf("\nBEFORE SORTING\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
   printf("\nAFTER SORTING\n");
   bubble_sort(a,n);
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
}

void bubble_sort(int a[],int n)
{
     int i,j,k,flag=1;
     for(i=1;i<n;i++)
     {
          if(flag==1) flag=0;
          else break;
          for(j=0;j<n-i;j++)
          {
              if(a[j]>a[j+1])
              {
                  flag=1;
                  k=a[j];
                  a[j]=a[j+1];
                  a[j+1]=k;
              }
          }
     }
}
