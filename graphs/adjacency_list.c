//Adjacency list for an undirected graph

#include<stdio.h>
#include<stdlib.h>

struct node
{ int vertex;
  struct node* next;
};

struct Graph
{
   int numVertices;
   struct node** adjList;   
};

struct node* createNode(int v)
{ struct node* newnode=malloc(sizeof(struct node));
  newnode->vertex=v;
  newnode->next=NULL;
  return newnode;  
}

struct Graph* createGraph(int vertices)
{  struct Graph* graph=malloc(sizeof(struct Graph));
   graph->numVertices=vertices;
   
   graph->adjList=malloc(vertices*sizeof(struct node*));
   int i;
   for(i=0;i<vertices;i++)
   graph->adjList[i]=NULL;
   
   return graph;	
}

void addEdge(struct Graph* graph,int src,int dest)
{
	//Add edge from source to destination
	struct node *newnode=createNode(dest);
	newnode->next=graph->adjList[src];
	graph->adjList[src]=newnode;
	
	//Add edge from destination to source
	newnode=createNode(src);
	newnode->next=graph->adjList[dest];
	graph->adjList[dest]=newnode;
}

void display_adjlist(struct Graph* graph)
{ int v;
  for(v=0;v<graph->numVertices;v++)
  {  
	 struct node* temp=graph->adjList[v];
     printf("Adjacency list of vertix %d\n",v);
     while(temp)
     {  printf("%d ->",temp->vertex);
	    temp=temp->next;
     }		 
	 printf("\n");
  }
}

void main()
{   int v,ch=0,e;
    printf("Enter the no of vertices in graph\n");
    scanf("%d",&v);
    struct Graph* graph=createGraph(v);
    int src,dest;
	printf("Enter the no of edges");
	scanf("%d",&e);
	do
    { printf("Enter the source and destination vertex for the graph");
      scanf("%d %d",&src,&dest);
	  addEdge(graph,src,dest);
      ch++;	  
    }while(ch<e);		

	display_adjlist(graph);
}