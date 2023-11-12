#pragma once
#include "forceMatch.h"
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
		printf((i == 0) ? "%c": "->%c", s->data[i]);
	}
	printf("\n");
}
void stringForceMatch(String* master, String* sub)//����ƥ��
{
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len)
	{
		if (master->data[i] == sub->data[j])
		{
			//ָ�����
			i++;
			j++;
		}
		else
		{
			//ָ�����
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == sub->len)
	{
		printf("match success!\n");
	}
	else
	{
		printf("match fail\n");
	}
}
