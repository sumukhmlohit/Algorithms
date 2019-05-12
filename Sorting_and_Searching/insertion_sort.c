#include<stdio.h>
#include<math.h>
#include<time.h>

void insertion_sort(int arr[],int n)
{  int i,key,j;
   for(i=1;i<n;i++)
   {   key=arr[i];
       j=i-1;

       while(j>=0&&arr[j]>key)
       {   arr[j+1]=arr[j];
           j--;
		   for(int k=0;k<n;k++)
		   printf("%d ",arr[k]);
       }
     arr[j+1]=key;
   }

}

void main()
{ int n,i,a[200000];clock_t start,end;
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
   start=clock();
   insertion_sort(a,n);
   end=clock();
   time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("Sorted array is\n");
    for(i=0;i<n;i++)
    {
       printf("%d ",a[i]);
    }

  printf("Time for insertion sort is %f",time);
}