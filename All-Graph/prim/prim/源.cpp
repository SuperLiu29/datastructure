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
typedef struct Edge {//edge���Ǳ��뱻���ʹ��Ķ���ļ���
	char vex;//������ʼ��
	int weight;//������ʼ�㵽ͼ�Ķ��������ж�Ӧ��index����ָ��Ķ������γɵıߵ�Ȩֵ,
			   //���weightΪ0,��˵����ʼ���Ӧ�����Ķ����ѱ����ʹ�
} Edge;

Edge* initEdge(Graph* G, int index) {
	Edge* edge = (Edge*)malloc(sizeof(Edge) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) {
		edge[i].vex = G->vexs[index];//��ʼ��
		edge[i].weight = G->arcs[index][i];//��ʱedge[i].weight����vex��G->vexs[i]�γɱߵ�Ȩֵ
	}
	return edge;
}

int getMinEdge(Edge* edge, Graph* G) {
	int index;
	int min = MAX;
	for (int i = 0; i < G->vexNum; i++) {
		if (edge[i].weight != 0 && min > edge[i].weight) {
			//ͨ���ҵ���С�ı����ҵ�
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
		edge[min].weight = 0;//����ö����ѱ�����
		for (int j = 0; j < G->vexNum; j++) {
			//���±�
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
	prim(G, 0);
}
int main() {
	text();
}