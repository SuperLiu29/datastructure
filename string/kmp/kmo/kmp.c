#include "kmp.h"
String* initString()//���һ��String
{
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
}
void stringAssign(String* s, char* data)//��ֵ
{
	//���ж�s֮ǰ��data�Ƿ���ֵ,�������free��
	if (s->data)
	{
		free(s->data);
	}
	int len = 0;//���ݹ����Ĵ��ĳ���
	char* temp = data;//���ڼ��㴮����
	while (*temp++)
	{
		len++;
	}
	if (len == 0)
	{
		//��������
		s->data = NULL;
		s->len = len;
	}
	else
	{
		temp = data;//��ָ��ָ�ؿ�ͷ
		s->len = len;
		s->data = (char*)malloc(sizeof(char) * (len + 1));//��Ϊ�ַ������ַ�'\0'��β
		for (int i = 0; i < len; i++)
		{
			s->data[i] = *temp++;
		}
	}
}
void printString(String* s)//���
{
	for (int i = 0; i < s->len; i++)
	{
		printf((i == 0) ? "%c" : "->%c", s->data[i]);
	}
	printf("\n");
}
int* getNext(String* s)
{
	int i = 0;//i��ʾ����
	int j = -1;//j��ʾ����ǰ��׺����
	int* next = (int*)malloc(sizeof(int) * s->len);
	next[i] = j;//��Ϊ��Ԫ�صĹ���ǰ��׺����Ϊ-1
	while (i < s->len - 1)//�Ѿ��ҵ��˵�һ����ֵ,���Ի���Ҫѭ��len-1��
	{
		if (j == -1 || s->data[i] == s->data[j])//j=-1˵���Ƶ��˵�һ��Ԫ��|s->data[i] == s->data[j]�����Ļ�
												//ǰһ��Ԫ�صĹ���ǰ��׺+1��Ϊ��һ��Ԫ�صĹ���ǰ��׺����
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];//�ٽ���Ϊ-1����ѭ��
		}
	}
	//for (i = 0; i < s->len; i++)
	//{
	//	next[i] += 1;
	//}
	return next;//����next����
}
void kmpMatch(String* master, String* sub,int *next)
{
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len)
	{
		if (j == -1 || master->data[i] == sub->data[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == sub->len)
	{
		printf("match success\n");
	}
	else
	{
		printf("match fail\n");
	}
}