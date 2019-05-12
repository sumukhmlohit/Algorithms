//The Siruseri Sports Stadium


//The bustling town of Siruseri has just one sports stadium. There are a number of schools, colleges, sports associations, etc. that use this stadium as the venue for their sports events.

//Anyone interested in using the stadium has to apply to the Manager of the stadium indicating both the starting date (a positive integer S) and the length of the sporting event in days (a positive integer D) they plan to organise. Since these requests could overlap it may not be possible to satisfy everyone.

//It is the job of the Manager to decide who gets to use the stadium and who does not. The Manager, being a genial man, would like to keep as many organisations happy as possible and hence would like to allocate the stadium so that maximum number of events are held.

//Suppose, for example, the Manager receives the following 4 requests:

//	Event No.  	Starting Date     	 Length 
           
 //          1                   2                    5
 //          2                   9                    7
 //          3                  15                    6
 //          4                   9                    3
//He would allot the stadium to events 1, 4 and 3. Event 1 begins on day 2 and ends on day 6, event 4 begins on day 9 and ends on day 11 and event 3 begins on day 15 and ends on day 20. You can verify that it is not possible to schedule all the 4 events (since events 2 and 3 overlap and only one of them can get to use the stadium).

//Your task is to help the manager find the best possible allotment (i.e., the maximum number of events that can use the stadium).


#include<stdio.h>
#include<stdlib.h>

void main()
{ int i,j,n,s[20000],d[20000],f[20000],temp,sche[20000];
   
  scanf("%d",&n);
  
  for(i=0;i<n;i++)
  {
    scanf("%d",&s[i]);//start date
    scanf("%d",&d[i]);//duration
  }
 
  for(i=0;i<n;i++)
  {
    f[i]=s[i]+d[i];//finish date
  }
  //Sort events according to finish date
  for( i = 0; i <n-1; i++)
  {  for( j = 0; j< n-i-1; j++)
     {  if(f[j]>f[j+1])
        { temp=f[j];
          f[j]=f[j+1];
          f[j+1]=temp;
          temp=s[j];
          s[j]=s[j+1];
          s[j+1]=temp;
         
        }

     }
  } 
 
 int pre=-200000;
 //Check if starting date of present event conflicts with finish date of previous event
 int k=0;
 for(i=0;i<n;i++)
 {
   if(s[i]>=pre)
   { k++;
     pre=f[i];
   }
 }  
 
 printf("%d",k);
 
}