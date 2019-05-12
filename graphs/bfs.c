//Adjacency list for an undirected graph

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4000

struct node
{ int vertex;
  struct node* next;
};

struct Graph
{
   int numVertices;
   struct node** adjList;   
   int *visited;
};

struct queue
{ int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}


int isEmpty(struct queue* q) {
    if(q->rear == -1) 
        return 1;
    else 
        return 0;
}

void enqueue(struct queue* q, int value){
    if(q->rear == SIZE-1)
        printf("\nQueue is Full!!");
    else {
        if(q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct queue* q){
    int item;
    if(isEmpty(q)){
        printf("Queue is empty");
        item = -1;
    }
    else{
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear){
            printf("Resetting queue");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(struct queue *q) {
    int i = q->front;

    if(isEmpty(q)) {
        printf("Queue is empty");
    } else {
        printf("\nQueue contains \n");
        for(i = q->front; i < q->rear + 1; i++) {
                printf("%d ", q->items[i]);
        }
    }    
}

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

void bfs(struct Graph* graph,int startVertex)
{ struct queue* q =createQueue();
  graph->visited[startVertex]=1;
  enqueue(q,startVertex);//enqueue starting vertex,unvisited
  
  while(!isEmpty(q))
  { printQueue(q);
	int currentVertex=dequeue(q);//dequeue current vertex in queue
    printf("Visited %d\n",currentVertex);
	
	struct node *temp=graph->adjList[currentVertex];
	
	while(temp)
	{ int adjVertex=temp->vertex;
	   //put dequeued vertex to visited list
      if(graph->visited[adjVertex]==0)
      { graph->visited[adjVertex]=1;
	    enqueue(q,adjVertex);
      }
    temp=temp->next;	  
	}
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
	bfs(graph,0);
}