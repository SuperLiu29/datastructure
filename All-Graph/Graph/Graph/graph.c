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
	qNode* head;//��¼ͷ���ڳ���
	qNode* tail;//��¼β�������
}Queue;
void queueInit(Queue* Q)//��ʼ��
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

	//�ж�
	if (isQueueEmpty(Q)) {
		//˵����ʱ����Ԫ��
		Q->head = newNode;
		Q->tail = Q->head;
	}
	else {
		//��β���ָ����Ԫ��,����Ԫ�س�Ϊβ���
		Q->tail->next = newNode;
		Q->tail = newNode;
	}
}
int deQueue(Queue* Q)
{
	assert(Q);
	assert(!isQueueEmpty(Q));
	//ֻ��ͷɾ
	qNode* next = Q->head->next;//������һ���ڵ�,��ָ��ɾ
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
	G->arcs = (int**)malloc(sizeof(int*) * vexnum);//�������Ϊ�ڽӾ������
	for (int i = 0; i < vexnum; i++) {
		G->arcs[i] = (int*)malloc(sizeof(int) * vexnum);//�������ΪΪÿ�к��򿪱�vexnum���ռ���Ϊ��
	}
	G->vexnum = vexnum;
	G->arcnum = 0;
	return G;
}
void creatGraph(Graph* G, char* vexs, int* arcs) {
	//arcs��һ����ά������׵�ַ
	for (int i = 0; i < G->vexnum; i++) {
		G->vexs[i] = vexs[i];
		for (int j = 0; j < G->vexnum; j++) {
			G->arcs[i][j] = *(arcs + i * G->vexnum + j);//�׵�ַƫ����
			if (G->arcs[i][j]) {
				G->arcnum++;
			}
		}
	}
	G->arcnum /= 2;//��Ϊ��ʱΪ����ͼ
}
void DFS(Graph* G, int* visitd, int index) {
	//������ȱ���

	//index����һ�����ʵĽ��
	// visited���������ж��Ƿ񱻷��ʹ�
	printf("%c ", G->vexs[index]);
	visitd[index] = 1;//Ϊ1�������ʹ�
	for (int i = 0; i < G->vexnum; i++) {
		if (G->arcs[index][i] == 1 && !visitd[i]) {
			//�ݹ�
			DFS(G, visitd, i);
		}
	}
}
void BFS(Graph* G, int* visited, int index) {
	//������ȱ���
	//�Ͳ�α�������
	Queue Q;
	queueInit(&Q);
	printf("%c ", G->vexs[index]);//�ȷ���,�����������
	//���ʹ��˽�visited�����ж�Ӧ������ֵ��Ϊ1
	visited[index] = 1;
	enQueue(&Q, index);//��������Ϊdata���,��Ϊ���㴢����������
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
		//��ʼ������
		visited[i] = 0;
	}
	DFS(G, visited, 0);
	printf("\n");
	for (i = 0; i < G->vexnum; i++) {
		//��ʼ������
		visited[i] = 0;
	}
	BFS(G, visited, 0);
}
int main() {
	text();
}