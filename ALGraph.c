#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef   struct   node
{   int  adjvex;       //邻接点域，邻接点在表头数组中的位置
    struct  node  *next;   //链域，指示下一条边或弧
} ArcNode;
typedef   struct  VNode
{   char  data;     //存放顶点信息
    ArcNode  *firstarc;    //指示第一条依附该顶点的弧或边
}VNode,AdjList[MAX];
typedef  struct{
    AdjList vertices; //表头数组 
    int vexnum, arcnum;// 顶点数和弧数 
    int kind;
}ALGraph;

void CreateUDG(ALGraph *G);
void DFSTraverse(ALGraph *G);
void DFS(ALGraph *G,int v, int visited[]);

void CreateUDG(ALGraph *G)
{ 
    int v1,v2,i;
    int k;
    ArcNode *pi;
    ArcNode *pj;
    printf("请输入顶点数，弧数：\n"); 
    scanf("%d,%d",&G->vexnum ,&G->arcnum );
    for( i= 0; i < G->vexnum; ++i){
    fflush(stdin);
    printf("请输入顶点的值 "); 
   	scanf("%c",&G->vertices[i].data); //输入顶点值 
	G->vertices[i].firstarc = NULL;        //初始化链表头指针为零 
    }
    for(k = 0; k < G->arcnum ;++k){  
        fflush(stdin);
        printf("请输入始点v1，终点v2 ");
        scanf("&d,%d",&v1,&v2); //v1始点v2终点 
        pi = (ArcNode *)malloc(sizeof(ArcNode));
        pi->adjvex = v2 ;
        pi->next = G->vertices[v1].firstarc ;
        G->vertices[v1].firstarc = pi; //插入链表  G.vertices[i]
        pj = (ArcNode *)malloc(sizeof(ArcNode));
        pj->adjvex = v1;
        pj->next = G->vertices[v2].firstarc;
        G->vertices[v2].firstarc = pj;  //插入链表 G.vertices[j] 
    }
} 

void DFSTraverse(ALGraph *G)
{ int i;
  int visited[G->vexnum];
  for(i=0;i<G->vexnum;++i) visited[i]=0;
  for(i=0;i<G->vexnum;++i)
   if(!visited[i]) DFS(G,i,visited); 
	
 } 
 
 void DFS(ALGraph *G,int i,int visited[])
 {
   
   ArcNode *w;
   visited[i]=1;
   
   printf("输出:%c\n",G->vertices[i].data);
   w=G->vertices[i].firstarc; 
   while (w)
    { // i=w->adjvex;//邻接点在数组中的下标
       if(!visited[w->adjvex])
          DFS(G,w->adjvex,visited);
       w=w->next;
	   }
 }


int main()
 { //int v;
   //int visited[MAX];
   ALGraph G;
   CreateUDG (&G); 
   DFSTraverse(&G);
   return 0;
 }
