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
typedef struct Edge {
	//边的集合
	int start;
	int end;
	int weight;
} Edge;

Edge* initEdge(Graph* G) {
	int index = 0;
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->arcNum);
	//考虑到是无向图,所以从i+1开始,因为边的存在沿对角线对称
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = i + 1; j < G->vexNum; j++) {
			if (G->arcs[i][j] != MAX) {
				//存在边才加入
				edge[index].start = i;
				edge[index].end = j;
				edge[index].weight = G->arcs[i][j];
				index++;
			}
		}
	}
	return edge;
}
void sortEdge(Edge* edge, Graph* G) {
	Edge temp;
	//冒泡排序
	for (int i = 0; i < G->arcNum - 1; i++) {
		for (int j = 0; j < G->arcNum - i - 1; j++) {
			if (edge[j].weight > edge[j + 1].weight) {
				temp = edge[j];
				edge[j] = edge[j + 1];
				edge[j + 1] = temp;
			}
		}
	}
}
void kruskal(Graph* G) {
	int* connected = (int*)malloc(sizeof(int) * G->vexNum);//开辟一个数组来记录连通向量
	for (int i = 0; i < G->vexNum; i++) {
		connected[i] = i;//初始化
	}
	Edge* edge = initEdge(G);
	sortEdge(edge, G);
	//执行kruskal
	for (int i = 0; i < G->arcNum; i++) {
		//通过点找边
		//因为经过排序,edge[i]即为此时的最小权值边
		int start = connected[edge[i].start];
		int end = connected[edge[i].end];
		if (start != end) {
			//说明不会构成回路
			printf("v%c-->v%c weight=%d\n", G->vexs[edge[i].start], G->vexs[edge[i].end], edge[i].weight);
			for (int j = 0; j < G->vexNum; j++) {
				//更改连通分量
				if (connected[j] == end) {
					//说明找到了终点.终点跟着起点走
					//更改connected数组中对应的值
					connected[j] = start;
				}
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
	kruskal(G);
}
int main() {
	text();
}