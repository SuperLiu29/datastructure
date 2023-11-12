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
typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* initStack() {
	Node* stack = (Node*)malloc(sizeof(Node));
	stack->data = 0;//��¼������
	stack->next = NULL;
	return stack;//�����ڱ�λ���
}
void push(Node* stack, int data) {
	//��ջ
	//ͷ�巨
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->next;
	stack->next = newNode;
	stack->data++;//������++
}
bool isEmpty(Node* stack) {
	return stack->next == NULL;
}
int pop(Node* stack) {
	//��ջ
	//���ж��Ƿ�Ϊ��
	if (!isEmpty(stack)) {
		Node* node = stack->next;
		stack->next = node->next;
		int data = node->data;
		free(node);
		return data;
	}
	return 0;
}
int* findInDegrees(Graph* G) {
	int* inDegress = (int*)malloc(sizeof(int) * G->vexnum);
	//��ʼ��
	for (int i = 0; i < G->vexnum; i++) {
		inDegress[i] = 0;
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			if (G->arcs[i][j]) {
				//��Ӧ�����++
				inDegress[j]++;
			}
		}
	}
	return inDegress;
}
void topologicalSort(Graph* G) {
	//��������
	int index = 0;
	int* top = (int*)malloc(sizeof(int) * G->vexnum);//���˺�Ľ������
	int* inDegrees = findInDegrees(G);//������
	Node* stack = initStack();//���ջ
	for (int i = 0; i < G->vexnum; i++) {
		if (inDegrees[i] == 0) {
			//��ջ
			push(stack, i);
		}
	}
	while (!isEmpty(stack)) {
		int vex = pop(stack);//�õ���ջԪ��
		top[index++] = vex;
		for (int i = 0; i < G->vexnum; i++) {
			if (G->arcs[vex][i]) {
				inDegrees[i]--;
				if (inDegrees[i] == 0) {
					push(stack, i);//���Ϊ0��ջ
				}
			}
		}
	}
	//��������������
	for (int i = 0; i < G->vexnum; i++) {
		printf("%c ", G->vexs[top[i]]);
	}
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

void text() {
	Graph* G = initGraph(6);
	int arcs[6][6] = {
		0,1,1,1,0,0,
			0,0,0,0,0,0,
			0,1,0,0,1,0,
			0,0,0,0,1,0,
			0,0,0,0,0,0,
			0,0,0,1,1,0
	};
	creatGraph(G, (char*)"123456", (int*)arcs);
	int* visited = (int*)malloc(sizeof(int) * G->vexnum);
	int i = 0;
	for (i = 0; i < G->vexnum; i++) {
		//��ʼ������
		visited[i] = 0;
	}
	DFS(G, visited, 0);
	printf("\n");

	topologicalSort(G);
}
int main() {
	text();
}