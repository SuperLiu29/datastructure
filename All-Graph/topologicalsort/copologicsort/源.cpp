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
	stack->data = 0;//记录链表长度
	stack->next = NULL;
	return stack;//返回哨兵位结点
}
void push(Node* stack, int data) {
	//入栈
	//头插法
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = stack->next;
	stack->next = newNode;
	stack->data++;//链表长度++
}
bool isEmpty(Node* stack) {
	return stack->next == NULL;
}
int pop(Node* stack) {
	//出栈
	//需判断是否为空
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
	//初始化
	for (int i = 0; i < G->vexnum; i++) {
		inDegress[i] = 0;
	}
	for (int i = 0; i < G->vexnum; i++) {
		for (int j = 0; j < G->vexnum; j++) {
			if (G->arcs[i][j]) {
				//对应的入度++
				inDegress[j]++;
			}
		}
	}
	return inDegress;
}
void topologicalSort(Graph* G) {
	//拓扑排序
	int index = 0;
	int* top = (int*)malloc(sizeof(int) * G->vexnum);//拓扑后的结果数组
	int* inDegrees = findInDegrees(G);//获得入度
	Node* stack = initStack();//获得栈
	for (int i = 0; i < G->vexnum; i++) {
		if (inDegrees[i] == 0) {
			//入栈
			push(stack, i);
		}
	}
	while (!isEmpty(stack)) {
		int vex = pop(stack);//得到出栈元素
		top[index++] = vex;
		for (int i = 0; i < G->vexnum; i++) {
			if (G->arcs[vex][i]) {
				inDegrees[i]--;
				if (inDegrees[i] == 0) {
					push(stack, i);//入度为0入栈
				}
			}
		}
	}
	//输出拓扑排序后结果
	for (int i = 0; i < G->vexnum; i++) {
		printf("%c ", G->vexs[top[i]]);
	}
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
		//初始化数组
		visited[i] = 0;
	}
	DFS(G, visited, 0);
	printf("\n");

	topologicalSort(G);
}
int main() {
	text();
}