#include<stdio.h>
#include<time.h>

void main()
{ int n,a[10000],i,j,temp;
  printf("Enter the no of elements\n");
  scanf("%d",&n);
  clock_t begin,end;
  begin=clock();
  for(i = 0; i < n; i++)
  {  a[i]=rand();
  }
  printf("Elements before sorting are");
  for(i = 0; i < n; i++)
  { 
      printf("%d ",a[i]);
  }
  
  for( i = 0; i <n-1; i++)
  {  for( j = 0; j< n-i-1; j++)
     {  if(a[j]>a[j+1])
        { temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;
        }

     }
  }
  printf("Elements after sorting are");
  for(i = 0; i < n; i++)
  { 
      printf("%d ",a[i]);
  }
  double duration;
  end=clock();  
  duration=(double)(end-begin)/CLOCKS_PER_SEC;
  printf("Time for program is %f");
}