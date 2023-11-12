#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 32767
typedef struct Graph {
	int vexNum;
	int arcNum;
	char* vexs;
	int** arcs;
}Graph;
typedef struct Edge {//edge即是边与被访问过的顶点的集合
	char vex;//代表起始点
	int weight;//代表起始点到图的顶点数组中对应的index索引指向的顶点所形成的边的权值,
			   //如果weight为0,则说该起始点对应索引的顶点已被访问过
} Edge;

Edge* initEdge(Graph* G, int index) {
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) {
		edge[i].vex = G->vexs[index];//初始化
		edge[i].weight = G->arcs[index][i];//此时edge[i].weight代表vex与G->vexs[i]形成边的权值
	}
	return edge;
}

int getMinEdge(Edge* edge, Graph* G) {
	int index;
	int min = MAX;
	for (int i = 0; i < G->vexNum; i++) {
		if (edge[i].weight != 0 && min > edge[i].weight) {
			//通过找到最小的边来找点
			min = edge[i].weight;
			index = i;
		}
	}
	return index;
}

void prim(Graph* G, int index) {
	int min;
	Edge* edge = initEdge(G, index);
	for (int i = 0; i < G->vexNum - 1; i++) {
		min = getMinEdge(edge, G);
		printf("v%c --> v%c, weight = %d\n", edge[min].vex, G->vexs[min],
			edge[min].weight);
		edge[min].weight = 0;//代表该顶点已被访问
		for (int j = 0; j < G->vexNum; j++) {
			//更新边
			if (G->arcs[min][j] < edge[j].weight) {
				edge[j].weight = G->arcs[min][j];
				edge[j].vex = G->vexs[min];
			}
		}
	}
}
Graph* initGraph(int vexnum) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vexnum);
	G->arcs = (int**)malloc(sizeof(int*) * vexnum);//可以理解为邻接矩阵的列
	for (int i = 0; i < vexnum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vexnum);//可以理解为为每列横向开辟vexnum个空间作为行
	}
	G->vexNum = vexnum;
	G->arcNum = 0;
	return G;
}
void createGraph(Graph* G, char* vexs, int* arcs) {
	//arcs是一个二维数组的首地址
	for (int i = 0; i < G->vexNum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);//首地址偏移量
			if (G->arcs[i][j] && G->arcs[i][j] != MAX) {
				G->arcNum++;
			}
		}
	}
	G->arcNum /= 2;//因为此时为无向图
}
void DFS(Graph* G, int* visitd, int index) {
	//深度优先遍历

	//index即第一个访问的结点
	// visited数组用于判断是否被访问过
	printf("%c ", G->vexs[index]);
	visitd[index] = 1;//为1则代表访问过
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visitd[i]) {
			//递归
			DFS(G, visitd, i);
		}
	}
}

void text() {
	Graph* G = initGraph(6);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) visited[i] = 0;
	int arcs[6][6] = { 0,   6, 1, 5,   MAX, MAX, 6,   0,   5, MAX, 3,   MAX,
					  1,   5, 0, 5,   6,   4,   5,   MAX, 5, 0,   MAX, 2,
					  MAX, 3, 6, MAX, 0,   6,   MAX, MAX, 4, 2,   6,   0 };
	createGraph(G, (char*)"123456", (int*)arcs);
	DFS(G, visited, 0);
	printf("\n");
	prim(G, 0);
}
int main() {
	text();
}