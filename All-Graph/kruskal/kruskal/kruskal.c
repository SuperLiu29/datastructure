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
	//�ߵļ���
	int start;
	int end;
	int weight;
} Edge;

Edge* initEdge(Graph* G) {
	int index = 0;
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->arcNum);
	//���ǵ�������ͼ,���Դ�i+1��ʼ,��Ϊ�ߵĴ����ضԽ��߶Գ�
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = i + 1; j < G->vexNum; j++) {
			if (G->arcs[i][j] != MAX) {
				//���ڱ߲ż���
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
	//ð������
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
	int* connected = (int*)malloc(sizeof(int) * G->vexNum);//����һ����������¼��ͨ����
	for (int i = 0; i < G->vexNum; i++) {
		connected[i] = i;//��ʼ��
	}
	Edge* edge = initEdge(G);
	sortEdge(edge, G);
	//ִ��kruskal
	for (int i = 0; i < G->arcNum; i++) {
		//ͨ�����ұ�
		//��Ϊ��������,edge[i]��Ϊ��ʱ����СȨֵ��
		int start = connected[edge[i].start];
		int end = connected[edge[i].end];
		if (start != end) {
			//˵�����ṹ�ɻ�·
			printf("v%c-->v%c weight=%d\n", G->vexs[edge[i].start], G->vexs[edge[i].end], edge[i].weight);
			for (int j = 0; j < G->vexNum; j++) {
				//������ͨ����
				if (connected[j] == end) {
					//˵���ҵ����յ�.�յ���������
					//����connected�����ж�Ӧ��ֵ
					connected[j] = start;
				}
			}
		}
	}
}
Graph* initGraph(int vexnum) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vexnum);
	G->arcs = (int**)malloc(sizeof(int*) * vexnum);//�������Ϊ�ڽӾ������
	for (int i = 0; i < vexnum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vexnum);//�������ΪΪÿ�к��򿪱�vexnum���ռ���Ϊ��
	}
	G->vexNum = vexnum;
	G->arcNum = 0;
	return G;
}
void createGraph(Graph* G, char* vexs, int* arcs) {
	//arcs��һ����ά������׵�ַ
	for (int i = 0; i < G->vexNum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexNum + j);//�׵�ַƫ����
			if (G->arcs[i][j] && G->arcs[i][j] != MAX) {
				G->arcNum++;
			}
		}
	}
	G->arcNum /= 2;//��Ϊ��ʱΪ����ͼ
}
void DFS(Graph* G, int* visitd, int index) {
	//������ȱ���

	//index����һ�����ʵĽ��
	// visited���������ж��Ƿ񱻷��ʹ�
	printf("%c ", G->vexs[index]);
	visitd[index] = 1;//Ϊ1�������ʹ�
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visitd[i]) {
			//�ݹ�
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