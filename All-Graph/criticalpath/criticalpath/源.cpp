#include <stdio.h>
#include <stdlib.h>
#define MAX 65535

typedef struct Graph {
	char* vexs;
	int** arcs;
	int vexNum;
	int arcNum;
} Graph;

typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* initStack() {
	Node* stack = (Node*)malloc(sizeof(Node));
	stack->data = 0;
	stack->next = NULL;
	return stack;
}

int isEmpty(Node* stack) {
	if (stack->next == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(Node* stack, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = stack->next;
	stack->next = node;
	stack->data++;
}

int pop(Node* stack) {
	if (!isEmpty(stack)) {
		Node* node = stack->next;
		stack->next = node->next;
		return node->data;
	}
	else {
		return -1;
	}
}

int* findInDegrees(Graph* G) {
	int* inDegrees = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) {
		inDegrees[i] = 0;
	}
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX)
				inDegrees[j] = inDegrees[j] + 1;
		}
	}
	return inDegrees;
}
int* topologicalSort(Graph* G) {
	int index = 0;
	int* top = (int*)malloc(sizeof(int) * G->vexNum);
	int* inDegrees = findInDegrees(G);
	Node* stack = initStack();
	for (int i = 0; i < G->vexNum; i++) {
		if (inDegrees[i] == 0) {
			push(stack, i);
		}
	}
	while (!isEmpty(stack)) {
		int vex = pop(stack);
		top[index++] = vex;
		for (int i = 0; i < G->vexNum; i++) {
			if (G->arcs[vex][i] > 0 && G->arcs[vex][i] != MAX) {
				inDegrees[i] = inDegrees[i] - 1;
				if (inDegrees[i] == 0) push(stack, i);
			}
		}
	}
	for (int i = 0; i < index; i++) {
		printf("%c ", G->vexs[top[i]]);
	}
	printf("\n");
	return top;
}

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
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX) G->arcNum++;
		}
	}
}
int getIndex(Graph* G, int* top, int i) {
	//��Ҫ֪��i�����������е�����
	int j;
	for (j = 0; j < G->vexNum; j++) {
		if (top[j] == i) {
			//��ʱ�ҵ���
			break;
		}
	}
	return j;
}
void criticalPath(Graph* G) {
	//�ȵõ���������
	//Ϊʲô?
	//��Ϊ����������Ա�֤���ǻ��������ϵ˳����м���,�����н���ǰ��һ��λ����֮ǰ.
	int* top = topologicalSort(G);
	//����early�����late����,����Ӧ�������е�ֵ
	int* early = (int*)malloc(sizeof(int) * G->vexNum);
	int* late = (int*)malloc(sizeof(int) * G->vexNum);
	//��ʼ��
	for (int i = 0; i < G->vexNum; i++) {
		early[i] = 0;
		late[i] = 0;
	}
	//�������緢��ʱ��
	for (int i = 0; i < G->vexNum; i++) {
		int max = 0;//�������緢��ʱ����ȡǰ��·�����ֵ
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[j][top[i]] > 0 && G->arcs[j][top[i]] != MAX) {
				int index = getIndex(G, top, j);//�ҵ��������������е�����
				if (early[index] + G->arcs[j][top[i]] > max) {
					max = early[index] + G->arcs[j][top[i]];
				}
			}
		}
		early[i] = max;
	}
	//����������ʱ��
	late[(G->vexNum) - 1] = early[(G->vexNum) - 1];//�������
	for (int i = (G->vexNum) - 2; i >= 0; i--) {
		int min = MAX;
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[top[i]][j] > 0 && G->arcs[top[i]][j] != MAX) {
				int index = getIndex(G, top, j);
				if (late[index] - G->arcs[top[i]][j] < min) {
					min = late[index] - G->arcs[top[i]][j];
				}
			}
		}
		late[i] = min;
	}
	for (int i = 0; i < G->vexNum; i++) {
		printf("%d ", early[i]);//���early����
	}
	printf("\n");
	for (int i = 0; i < G->vexNum; i++) {
		printf("%d ", late[i]);//�����late����
	}
	printf("\n");
	//��ؼ�·��(ʱ������==0)
	for (int i = 0; i < G->vexNum; i++) {
		for (int j = 0; j < G->vexNum; j++) {
			if (G->arcs[i][j] > 0 && G->arcs[i][j] != MAX) {
				//Ϊʲô�˴���G->arcs[i][j]?
				//��Ϊ��ʱҪ���·��,���ն��㼯��
				int start = getIndex(G, top, i);
				int end = getIndex(G, top, j);
				if (early[start] == (late[end] - G->arcs[i][j])) {//�������緢��ʱ��-����������ʱ��
					printf("start=%d end=%d\n", i, j);//��ȼ����
				}
			}
		}
	}
}
void DFS(Graph* G, int* visited, int index) {
	printf("%c ", G->vexs[index]);
	visited[index] = 1;
	for (int i = 0; i < G->vexNum; i++) {
		if (G->arcs[index][i] > 0 && G->arcs[index][i] != MAX && !visited[i]) {
			DFS(G, visited, i);
		}
	}
}
int main() {
	Graph* G = initGraph(6);
	int* visited = (int*)malloc(sizeof(int) * G->vexNum);
	for (int i = 0; i < G->vexNum; i++) visited[i] = 0;
	int arcs[6][6] = { 0,3,2,MAX,MAX,MAX,
		MAX,0,4,4,MAX,MAX,
		MAX,0,0,8,3,MAX,
		MAX,MAX,MAX,0,MAX,6,
		MAX,MAX,MAX,2,0,MAX,
		MAX,MAX,MAX,MAX,MAX,0
	};
	createGraph(G, (char*)"012345", (int*)arcs);
	DFS(G, visited, 0);
	printf("\n");
	criticalPath(G);
	return 0;
}