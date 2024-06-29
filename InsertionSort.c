#include<stdio.h>
void insertion_sort(int [],int);
void main()
{
   int a[100],n,i;

   printf("Enter the number of elements :");
   scanf("%d",&n);
   printf("Enter %d values into the array\n",n);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   printf("Before applying the sorting algo\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);

   insertion_sort(a,n); //Call of insertion sort function

   printf("After applying the sorting algo\n");
   for(i=0;i<n;i++)
      printf("%d ",a[i]);
}

void insertion_sort(int a[],int n)
{
   int i,j,x;
   for(i=1;i<n;i++)
   {
      x=a[i];
      for(j=i-1;a[j]>x && j>=0;j--)
             a[j+1]=a[j];
      a[j+1]=x;
   }
}
