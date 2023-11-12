#include <stdio.h>
#include <stdlib.h>
#define MAX 32767//不可达为MAX
//指向自己为0

typedef struct Graph
{
	char* vexs;
	int** arcs;
	int vexNum;
	int arcNum;
}Graph;
Graph* initGraph(int vexNum) {//初始化
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vexNum);
	G->arcs = (int**)malloc(sizeof(int*) * vexNum);
	for (int i = 0; i < vexNum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vexNum);
	}
	G->vexNum = vexNum;
	G->arcNum = 0;
	return G;
}
void createGraph(Graph* G, char* vexs, int* arcs) {
	for (int i = 0; i < G->vexNum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);
			if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX) {
				G->arcNum++;
			}
		}
	}
	G->arcNum /= 2;
}
void DFS(Graph* G, int* visited, int index) {
	printf("%c\t", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != 0 && !visited[i]) {
			DFS(G, visited, i);
		}
	}
}
int getMin(int* D, int* S, Graph* G) {//找到最短路径
	int min = MAX;
	int index = 0;
	for (int i = 0; i < G->vexNum; i++) {
		if (D[i] < min && !S[i]) {
			min = D[i];
			index = i;
		}
	}
	return index;
}
void dijkstra(Graph* G, int index) {
	//创建辅助数组
	int* S = (int*)malloc(sizeof(int) * G->vexNum);//记录目标顶点(即index)到其他顶点的最短路径是否求得
	int* P = (int*)malloc(sizeof(int) * G->vexNum);//记录目标顶点(即index)到其他顶点的最短路径的前驱顶点
	int* D = (int*)malloc(sizeof(int) * G->vexNum);//记录目标顶点(即index)到其他顶点的最短路径长度
	//初始化辅助数组
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX) {
			D[i] = G->arcs[index][i];
			P[i] = index;
		}
		else {
			D[i] = MAX;
			P[i] = -1;
		}
		if (i == index) {
			S[i] = 1;
			D[i] = 0;
		}
		else {
			S[i] = 0;
		}
	}
	//初始化完毕,执行算法
	for (int i = 0; i < G->vexNum - 1; i++) {//因为此时知道已知点的最短路径,而算法核心是不断找出最短路径,所以只需要执行G->vexNum-1次
	//先获取此时的最短路径
		int index = getMin(D, S, G);
		S[index] = 1;//找到最小边后将S数组对应值改为1
		for (int j = 0; j < G->vexNum; j++) {
			if (!S[j] && G->arcs[index][j] + D[index] < D[j]) {
				D[j] = G->arcs[index][j] + D[index];
				P[j] = index;
			}
		}
	}
	//输出
	for (int i = 0; i < G->vexNum; i++) {
		printf("%d  %d  %d  ", S[i], P[i], D[i]);
		printf("\n");
	}
}

int main() {
	Graph* G = initGraph(7);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[7][7] = {
			0, 12, MAX, MAX, MAX, 16, 14,
			12, 0, 10, MAX, MAX, 7, MAX,
			MAX, 10, 0, 3, 5, 6, MAX,
			MAX, MAX, 3, 0, 4, MAX, MAX,
			MAX, MAX, 5, 4, 0, 2, 8,
			16, 7, 6, MAX, 2, 0, 9,
			14, MAX, MAX, MAX, 8, 9, 0
	};
	char data[10] = "1234567";
	createGraph(G, data, (int*)arcs);
	DFS(G, visited, 0);
	printf("\n");
	dijkstra(G, 0);
	return 0;
}