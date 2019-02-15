#include<stdio.h>
#include<math.h>

void insertion_sort(int arr[],int n)
{  int i,key,j;
   for(i=0;i<n;i++)
   {   key=arr[i];
       j=i-1;

       while(j>=0&&arr[j]>key)
       {   arr[j+1]=arr[j];
           j--;
       }
     arr[j+1]=key;
   }

}

void main()
{ int n,i,a[200000];
  printf("Enter the size of array");
  scanf("%d",&n);
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
  printf("Unsorted array is\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }

   insertion_sort(a,n);

  printf("Sorted array is\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }

}