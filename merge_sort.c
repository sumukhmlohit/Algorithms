#include<stdio.h>
#include<stdlib.h>

merge_sort(int arr[],int l,int r)
{ if(l<r)
  {
    int m=l+(r-l)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create arrays for left and right branches */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temporary arrays back into array arr[...]*/
    /*for first subarray*/
    i = 0; 
    /*for second subarray*/  
    j = 0; 
    /*for merged subarray*/
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[]array*/
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[] array*/
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void main()
{ int arr[100000],i,n;
  printf("Enter the no of elements in array");
  scanf("%d",&n);

  for(i=0;i<n;i++)
  {  scanf("%d",&arr[i]);

  }
  
  printf("Unsorted array is\n");
  
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);    
  }
  printf("\n");
  merge_sort(arr,0,n-1);
  
  printf("Sorted array is\n");
  
  for(i=0;i<n;i++)
  {
    printf("%d ",arr[i]);    
  }
  
}



