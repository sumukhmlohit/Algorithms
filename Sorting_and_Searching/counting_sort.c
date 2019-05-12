#include<stdio.h>

void main()
{  int a[200000],n,i;
  printf("Enter the no of elements");
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
	 a[i]=rand();  
  }

  printf("Unsorted array is\n");
  for(i=0;i<n;i++)
  {
	 printf("%d",a[i]);  
  }
  
  count_sort();
  
  printf("Sorted array is\n");
  for(i=0;i<n;i++)
  {
	 printf("%d",a[i]);  
  }
}