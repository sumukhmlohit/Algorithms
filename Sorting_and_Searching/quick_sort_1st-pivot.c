#include<stdio.h>
#include<time.h>

void quick_sort(int arr[],int low,int high)
{   if(low<high)
    {  /* pi-partitioning index*/
       int pi=partition(arr,low,high);
       /*Seperately sort elements before and after partition*/
       quick_sort(arr,low,pi-1);
       quick_sort(arr,pi+1,high);
    }

}

int partition(int arr[],int low,int high)
{  int pivot=arr[low]; //pivot-last element
   int i=low;//index of smaller element
   int j=high;
   int temp;
 if(low<high)
 {
   while(i<j)
   {  while(arr[i]<pivot&&i<high)
      i++;
      while(arr[j]>pivot)
      j--;
      
       if(i<j)
       temp=arr[i];
       arr[i]=arr[j];
       arr[j]=temp;

      
   }

   
    temp=arr[j];
    arr[j]=pivot;
    pivot=temp;
 } 
   return j;
   
}

void main()
{ int n,i,a[2000];clock_t start,end; 
  printf("Enter the no of elements");
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
  quick_sort(a,0,n-1);
  end=clock();
  double time=(double)(end-start)/CLOCKS_PER_SEC;
  printf("Sorted array is\n");
  for(i=0;i<n;i++)
  {   
      printf("%d ",a[i]);
  }  
  printf("Time for quicksort is %f",time);
}