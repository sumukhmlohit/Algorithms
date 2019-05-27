#include<stdio.h>
#include<time.h>
#include<math.h>
int h[50];
void heapify(int h[],int n)		//build a max heap for sorting in ascending order
{
 int i,j,n1,k,heap,v;
 n1=n;
 for(i=n/2;i>=1;i--)               //all the parent nodes i.e) all except leaf nodes
 {
  k=i;
  v=h[k];                         //initialise parent node
  heap=0;
  while(!(heap)&&(2*k)<=n1)		 // while not added to loop & while it is actually a parent
  {
   j=2*k;						// parent
   if(j<n1&&h[j]<h[j+1])		//if less than total nodes& left node is less than right node,
      j=j+1;					//move to right node i.e) find max child
   if(v>=h[j])					//if that is less than parent,straightaway add it to heap
       heap=1;
   else 
   {
    h[k]=h[j];					//if parent is less than max child, swap the 2
    k=j;
   }
  }
h[k]=v;
 }
}


void main()
{
 int i,n,size,t;
 printf("Enter the value of n \n");
 scanf("%d",&n);
 printf("Enter the array elements \n");
 for(i=1;i<=n;i++)
  scanf("%d",&h[i]);
  heapify(h,n);									//first build the heap
  printf("Elements heapified \n");
  for(i=1;i<=n;i++)
   printf("%d \t",h[i]);
  // swap root node with last child, thereby deleting the root and putting it in the array.then also heapify the array  	
   for(i=n;i>=1;i--)
  {
   t=h[1];
   h[1]=h[i];
   h[i]=t;
   size=i-1;
    heapify(h,size);
  }
 printf("Sorted array is: \n");
 for(i=1;i<=n;i++)
  printf("%d \t",h[i]);
}