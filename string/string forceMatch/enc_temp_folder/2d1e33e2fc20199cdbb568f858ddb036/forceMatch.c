#pragma once
#include "forceMatch.h"
String* initString()//获得一个String
{
	String* s = (String*)malloc(sizeof(String));
	s->data = NULL;
	s->len = 0;
}
void stringAssign(String* s, char* data)//赋值
{
	//先判断s之前的data是否有值,如果有则free掉
	if (s->data)
	{
		free(s->data);
	}
	int len = 0;//传递过来的串的长度
	char* temp = data;//用于计算串长度
	while (*temp++)
	{
		len++;
	}
	if (len == 0)
	{
		//即无数据
		s->data = NULL;
		s->len = len;
	}
	else
	{
		temp = data;//将指针指回开头
		s->len = len;
		s->data = (char*)malloc(sizeof(char) * (len + 1));//因为字符串以字符'\0'结尾
		for (int i = 0; i < len; i++)
		{
			s->data[i] = *temp++;
		}
	}
}
void printString(String* s)//输出
{
	for (int i = 0; i < s->len; i++)
	{
		printf((i == 0) ? "%c": "->%c", s->data[i]);
	}
	printf("\n");
}
void stringForceMatch(String* master, String* sub)//暴力匹配
{
	int i = 0;
	int j = 0;
	while (i < master->len && j < sub->len)
	{
		if (master->data[i] == sub->data[j])
		{
			//指针后移
			i++;
			j++;
		}
		else
		{
			//指针回溯
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
