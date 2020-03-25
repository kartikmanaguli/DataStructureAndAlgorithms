#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node *link;
}
*Node ;
int *visited ;
int **array; 
Node head=NULL;

Node getNode()
{
  Node List = (Node)malloc(sizeof(Node));
  if(List==NULL)
  return NULL ;
  
 return List;
}

void addFront()
{
  Node List = getNode();
  int n;
  if(List==NULL)
  return NULL;
  printf("Enter the Data:");
  scanf("%d",&n);
  List->data=n-1;
  List->link=NULL;
  
  List->link = head;
  head=List; 
}

void depthFirstSearch(int index)
{
  visited[index] = 1;
  printf("%d-> ",index+1);
  for(Node vert = array[index] ; vert!=NULL ; vert=vert->link)
  {
      if(visited[vert->data]==0)
       {
          depthFirstSearch(vert->data);
       }
  }
 
}
void main()
{
   int index , jindex ;
   int nodes;
   int adj;
   int status;
   printf("Enter the Number Of Nodes in Graph:");
   scanf("%d",&nodes); 
   array = (int **) malloc (nodes*sizeof(int*));
   visited = (int*) malloc (nodes*sizeof(int));
      
  for(index =0;index<nodes ; index++)
 { 
   printf("--Enter the Adjecent Nodes For Vertex %d--\n",index+1);
    for(;;)
    {
     addFront();
     printf("Press 1 to continue or 0 to stop taking adj nodes for vertex %d:",index+1);
     scanf("%d",&status);
     if(status==0)
     break;
   } 
  
    array[index]=head;
    head=NULL;
  }
 
 depthFirstSearch(0);
  for(index = 0 ; index < nodes ; index++)
  if(visited[index]==0)
   depthFirstSearch(index);
}


