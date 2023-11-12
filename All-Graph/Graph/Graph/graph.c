#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
typedef struct Graph {
	int vexnum;
	int arcnum;
	char* vexs;
	int** arcs;
}Graph;
typedef struct queueNode {
	int data;
	struct queueNode* next;
}qNode;
typedef struct Queue {
	qNode* head;//记录头用于出队
	qNode* tail;//记录尾用于入队
}Queue;
void queueInit(Queue* Q)//初始化
{
	assert(Q);
	Q->head = NULL;
	Q->tail = NULL;
}
bool isQueueEmpty(Queue* Q) {
	assert(Q);

	return Q->head == NULL;
}
void enQueue(Queue* Q, int data) {
	assert(Q);
	qNode* newNode = (qNode*)malloc(sizeof(qNode));
	newNode->data = data;
	newNode->next = NULL;

	//判断
	if (isQueueEmpty(Q)) {
		//说明此时队无元素
		Q->head = newNode;
		Q->tail = Q->head;
	}
	else {
		//让尾结点指向新元素,让新元素成为尾结点
		Q->tail->next = newNode;
		Q->tail = newNode;
	}
}
int deQueue(Queue* Q)
{
	assert(Q);
	assert(!isQueueEmpty(Q));
	//只能头删
	qNode* next = Q->head->next;//储存下一个节点,先指后删
	int data = Q->head->data;
	free(Q->head);
	Q->head = next;
	if (Q->head == NULL)
	{
		Q->tail = NULL;
	}
	return data;
}
Graph* initGraph(int vexnum) {
	Graph* G = (Graph*)malloc(sizeof(Graph));
	G->vexs = (char*)malloc(sizeof(char) * vexnum);
	G->arcs = (int**)malloc(sizeof(int*) * vexnum);//可以理解为邻接矩阵的列
	for (int i = 0; i < vexnum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vexnum);//可以理解为为每列横向开辟vexnum个空间作为行
	}
	G->vexnum = vexnum;
	G->arcnum = 0;
	return G;
}
void creatGraph(Graph* G, char* vexs, int* arcs) {
	//arcs是一个二维数组的首地址
	for (int i = 0; i < G->vexnum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexnum + j);//首地址偏移量
			if (G->arcs[i][j]) {
				G->arcnum++;
			}
		}
	}
	G->arcnum /= 2;//因为此时为无向图
}
void DFS(Graph* G, int* visitd, int index) {
	//深度优先遍历

	//index即第一个访问的结点
	// visited数组用于判断是否被访问过
	printf("%c ", G->vexs[index]);
	visitd[index] = 1;//为1则代表访问过
	for (int i = 0; i < G->vexnum; i++) {
		if (G->arcs[index][i] == 1 && !visitd[i]) {
			//递归
			DFS(G, visitd, i);
		}
	}
}
void BFS(Graph* G, int* visited, int index) {
	//广度优先遍历
	//和层次遍历相似
	Queue Q;
	queueInit(&Q);
	printf("%c ", G->vexs[index]);//先访问,访问完了入队
	//访问过了将visited数组中对应索引的值置为1
	visited[index] = 1;
	enQueue(&Q, index);//将索引作为data入队,因为顶点储存在数组中
	while (!isQueueEmpty(&Q)) {
		int i = deQueue(&Q);
		for (int j = 0; j < G->vexnum; j++) {
			if (G->arcs[i][j] == 1 && !visited[j]) {
				printf("%c ", G->vexs[j]);
				visited[j] = 1;
				enQueue(&Q, j);
			}
		}
	}
}
void text() {
	Graph* G = initGraph(5);
	int arcs[5][5] = {
		0,1,0,0,0,
		1,0,0,1,0,
		0,1,0,0,1,
		0,0,1,1,0
	};
	creatGraph(G, "ABCDE", arcs);
	int* visited = (int*)malloc(sizeof(int) * G->vexnum);
	int i = 0;
	for (i = 0; i < G->vexnum; i++) {
		//初始化数组
		visited[i] = 0;
	}
	DFS(G, visited, 0);
	printf("\n");
	for (i = 0; i < G->vexnum; i++) {
		//初始化数组
		visited[i] = 0;
	}
	BFS(G, visited, 0);
}
int main() {
	text();
}