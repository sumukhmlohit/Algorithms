/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5000
int table[MAX];

void shift_table(char p[])
{   int i,j,n;
    n=strlen(p);
    for(i=0;i<MAX;i++)
    {
        table[i]=n;         //table entry=length of pattern
    }
    
    for(j=0;j<n-1;j++)
    {
        table[p[j]]=n-j-1;   //table entry=length-index-1;
    }
    
}

int horspool(char s[],char p[])
{   int i,j,k,m,n;
    n=strlen(s);
    m=strlen(p);
    
    printf("Length of string is %d",n);
    printf("Length of pattern is %d",m);
    i=m-1; 
    
    while(i<n)   //moving through the input string
    {
        k=0;//no of matched characters
         while((k<m)&&(p[m-k-1]==s[i-k])) //till we have not reached end of pattern
         //and if pattern end from the end is equal to corresponding text index
         {
              k++;            
         }
         
         if(k==m)
         return i-m+1;
         else
         i+=table[s[i]];
    }
    
    return -1;
}


int main()
{
   char str[20000],pattern[20000];
   
   int pos;
   printf("Enter the string");
   gets(str);
   printf("Enter the pattern");
   gets(pattern);
    shift_table(pattern);
    pos=horspool(str,pattern);
    
    if(pos>=0)
    {
        printf("Pattern position found starting from %d",pos);
    }
    else
    {
        printf("Pattern not found");
    }
    
    return 0;
}
