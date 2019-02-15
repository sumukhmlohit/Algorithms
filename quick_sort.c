#include<stdio.h>

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
{  int pivot=arr[high]; //pivot-last element
   int i=low-1;//index of smaller element
   int temp;
   for(int j=low;j<=high-1;j++)
   {   if(arr[j]<=pivot)
       {  i++;//increment index of smaller element
          //swap a[i] and a[j]
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
       }

   }
   temp=arr[i+1];
   arr[i+1]=arr[high];
   arr[high]=temp;
return i+1;
}

void main()
{ int n,i,a[2000]; 
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

  quick_sort(a,0,n-1);

  printf("Sorted array is\n");
  for(i=0;i<n;i++)
  {   
      printf("%d ",a[i]);
  }  

}