#include <stdio.h>
#include <stdlib.h>
#define MAX 32767//���ɴ�ΪMAX
//ָ���Լ�Ϊ0

typedef struct Graph
{
	char* vexs;
	int** arcs;
	int vexNum;
	int arcNum;
}Graph;
Graph* initGraph(int vexNum) {//��ʼ��
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
int getMin(int* D, int* S, Graph* G) {//�ҵ����·��
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
	//������������
	int* S = (int*)malloc(sizeof(int) * G->vexNum);//��¼Ŀ�궥��(��index)��������������·���Ƿ����
	int* P = (int*)malloc(sizeof(int) * G->vexNum);//��¼Ŀ�궥��(��index)��������������·����ǰ������
	int* D = (int*)malloc(sizeof(int) * G->vexNum);//��¼Ŀ�궥��(��index)��������������·������
	//��ʼ����������
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
	//��ʼ�����,ִ���㷨
	for (int i = 0; i < G->vexNum - 1; i++) {//��Ϊ��ʱ֪����֪������·��,���㷨�����ǲ����ҳ����·��,����ֻ��Ҫִ��G->vexNum-1��
	//�Ȼ�ȡ��ʱ�����·��
		int index = getMin(D, S, G);
		S[index] = 1;//�ҵ���С�ߺ�S�����Ӧֵ��Ϊ1
		for (int j = 0; j < G->vexNum; j++) {
			if (!S[j] && G->arcs[index][j] + D[index] < D[j]) {
				D[j] = G->arcs[index][j] + D[index];
				P[j] = index;
			}
		}
	}
	//���
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