#include<stdio.h>
#include<time.h>

void main()
{ int a[1000],n,i,j,min,temp;
  printf("Enter the no of elements in array\n");
  scanf("%d",&n);
  clock_t begin,end;
  begin=clock();
  for(i=0;i<n;i++)
  {  
     scanf("%d",&a[i]);
  }
  printf("Elements of array before sorting are\n");
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }

  for(i=0;i<n-1;i++)
  {   min=i;
      for(j=i+1;j<n;j++)
      {  if(a[j]<a[min])
         min=j;
      } 
      if(min!=i);
     { temp=a[min];
       a[min]=a[i];
       a[i]=temp;
     }
  }

  printf("Elements of array after sorting are\n");
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }

  end=clock();
  float duration=(double)(end-begin)/CLOCKS_PER_SEC;
  printf("Time for selection sort is %f",duration);
}