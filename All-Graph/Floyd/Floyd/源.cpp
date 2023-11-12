#include<stdio.h>
#include <stdlib.h>

#define MAX 32767
#define num 5
typedef struct Graph
{
	int vexNum;
	int arcNum;
	char* vexs;
	int** arcs;
}Graph;
Graph* initGraph(int vexNum) {
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
			if (!G->arcs[i][j] && G->arcs[i][j] != MAX) {
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
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i]) {
			DFS(G, visited, i);
		}
	}
}
void floyd(Graph* G) {
	int d[num][num];
	int p[num][num];
	//初始化两个数组
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			d[i][j] = G->arcs[i][j];
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX) {
				p[i][j] = i;
			}
			else {
				p[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	//算法执行
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			for (int k = 0; k < G->vexNum; k++) {
				//以i为中转点
				if (d[j][i] + d[i][k] < d[j][k]) {
					d[j][k] = d[j][i] + d[i][k];
					p[j][k] = p[i][k];//改变前驱
				}
			}
		}
	}
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
void text() {
	Graph* G = initGraph(4);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++)
		visited[i] = 0;
	int arcs[4][4] = {
			0, 1, MAX, 3,
			1, 0, 2, 2,
			MAX, 2, 0, 8,
			3, 2, 8, 0
	};
	char str[5] = "1234";
	createGraph(G, str, (int*)arcs);
	DFS(G, visited, 0);
	printf("\n");
	floyd(G);
}
int main()
{
	text();
	return 0;
}