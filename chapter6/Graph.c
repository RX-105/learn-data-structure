#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct SqQueue {
  int data[100];
  int front, rear
} SqQueue;

void InitQueue(SqQueue *sq);
int EnQueue(SqQueue *sq, int x);
int DeQueue(SqQueue *sq, int *x);
int QueueEmpty(SqQueue sq);

typedef struct {
  VertexType Vex[MaxVertexNum];// 顶点表
  EdgeType Edge[MaxVertexNum][MaxVertexNum];// 边表
  int vexnum, arcnum; // 顶点数与弧数
} MGraph;

typedef struct ArcNode {
  int adjvex;
  struct ArcNode *next;
} ArcNode;

typedef struct VNode {
  VertexType data;
  ArcNode *first;
} VNode, AdjList[MaxVertexNum];

typedef struct {
  AdjList vertices;
  int vexnum, arcnum;
} ALGraph;

void visit(int v); // STUB
int FirstNeighbor(MGraph g, int v);// STUB
int NextNeighbor(MGraph g, int v, int w);// STUB

int visited[MaxVertexNum];
SqQueue q;
void BFS(MGraph g, int v) {
  // 取起始顶点访问并入队，方便后续层次遍历
  visit(v);
  visited[v] = 1;
  EnQueue(&q, v);
  while (!QueueEmpty(q)) {
    DeQueue(&q, &v);
    for (int w = FirstNeighbor(g, v); w >= 0; w = NextNeighbor(g, v, w)) {
      // 队列访问就是广度优先
      if (!visited[w]) {
        visit(w);
        visited[w] = 1;
        EnQueue(&q, w);
      }
    }
  }
}
void BFSTraverse(MGraph g) {
  // 清空visited
  for (int i = 0; i < g.vexnum; i++) visited[i] = 0;
  InitQueue(&q);
  // 把每个顶点挨个BFS一遍
  for (int i = 0; i < g.vexnum; i++) {
    if (!visited[i]) BFS(g, i);
  }
}

void DFS(MGraph g, int v) {
  visit(v);
  visited[v] = 1;
  for (int w = FirstNeighbor(g, v); w >= 0; w = NextNeighbor(g, v, w)) {
    // 递归访问就是深度优先
    if (!visited[w]) DFS(g, w);
  }
}

void DFSTraverse(MGraph g) {
  // visited置空
  for (int v = 0; v < g.vexnum; v++) visited[v] = 0;
  // 每个顶点挨个DFS一遍
  for (int v = 0; v < g.vexnum; ++v)
    if (!visited[v]) DFS(g, v);
}

//void MiniSpanTree_Kruskal(AMGraph G) {
//  sort(Edge);
//  for (i = 0; i < G.vexnum; ++i)
//    Vexset[i] = i;
//  for (i = 0; i < G.arcnum; ++i) {
//    v1 = LocateVex(G, Edge[i].Head);
//    v2 = Locatevex(G, Edge[i].Tail);
//    vs1 = Vexset[v1];
//    vs2 = Vexset[v2];
//    if (vs1 != vs2) {
//      cout << Edge[i].Head << Edge[i].Tail;
//      for (j = 0; j < G.vexnum; ++j)
//        if (Vexset[j] == vs2) Vexset[j] = vs1;
//    }
//  }
//}
