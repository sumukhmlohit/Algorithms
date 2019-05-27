#include<stdio.h>

void dijkstra(int source,int cost[20][20],int visited[20],int d[20],int n)
  { 
    int i,j,min,u,w;
    for(i=1;i<=n;i++)
     {			// first mark all vertices as unvisited and calculate the distance from source to all vertices(direct edges only)
 	visited[i]=0;			
        d[i]=cost[source][i];
     } 
    visited[source]=1;		
    d[source]=0;
    for(j=2;j<=n;j++)
    {
     min=111;
     for(i=1;i<=n;i++)
      {  // if vertex not visited, find the min distance 
       if(!visited[i])
	     {
	       if(d[i]<min)
	       {
	         min=d[i];
	         u=i;
	        }
	      }
      }
     visited[u]=1;		// mark the same vertex as visited
     for(w=1;w<=n;w++)
     {
      if(cost[u][w]!=111&&visited[w]==0)
       {
         if(d[w]>cost[u][w]+d[u])			
         d[w]=cost[u][w]+d[u];					// if source to vertex direct dist > indirect dist , make that as the cost(source to vertex)
        }
      }
    }
  }
  
void main()
{ 
  int n,i,j,visited[20],source,cost[20][20],d[20];
  printf("Enter the number of vertices:\n");
  scanf("%d",&n);
  printf("Enter the cost matrix:\n");
  for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   scanf("%d",&cost[i][j]);
  printf("Enter the source node\n");
  scanf("%d",&source);
  dijkstra(source,cost,visited,d,n);
  for(i=1;i<=n;i++)
  if(i!=source)
  printf("\nShortest path from %d to %d is %d ",source,i,d[i]);
}