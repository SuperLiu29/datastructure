#include <stdio.h>   
#include <malloc.h>  

#define MaxSize 100  

typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];		//���ջ�е�����Ԫ��
	int top;					//ջ��ָ�룬�����ջ��Ԫ����data�����е��±�
}SqStack;
//��ʼ��ջ
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack* s)
{
	return (s->top == -1);
}
//��ջ
bool Push(SqStack*& s, ElemType& e)
{
	if (s->top == MaxSize - 1)
		return false;
	else
	{
		s->top++;
		s->data[s->top] = e;
		return true;
	}
}
//��ջ
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
		return false;
	else
	{
		e = s->data[s->top];
		s->top--;
		return true;
	}
}
//����ջ
void DestotyStack(SqStack*& s)
{
	free(s);
}
//��ֵת�� 
void Conversion()
{
	int a = 123456789;
	SqStack* s;
	int x;
	InitStack(s);
	while (a > 0)
	{
		x = a % 16;
		Push(s, x);
		a /= 16;
	}
	while (!StackEmpty(s))
	{
		Pop(s, x);
		switch (x)
		{
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15: x += 87; break;
		default:x += 48;
		}
		printf("%c", x);
	}
	DestotyStack(s);
	printf("\n");
}
//int main(void)
//{
//	Conversion();
//	return 0;
//}
