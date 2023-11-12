#include "kmp.h"
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
		printf((i == 0) ? "%c" : "->%c", s->data[i]);
	}
	printf("\n");
}
int* getNext(String* s)
{
	int i = 0;//i表示索引
	int j = -1;//j表示公共前后缀长度
	int* next = (int*)malloc(sizeof(int) * s->len);
	next[i] = j;//因为首元素的公共前后缀长度为-1
	while (i < s->len - 1)//已经找到了第一个的值,所以还需要循环len-1次
	{
		if (j == -1 || s->data[i] == s->data[j])//j=-1说明推到了第一个元素|s->data[i] == s->data[j]成立的话
												//前一个元素的公共前后缀+1即为后一个元素的公共前后缀长度
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];//再将置为-1继续循环
		}
	}
	//for (i = 0; i < s->len; i++)
	//{
	//	next[i] += 1;
	//}
	return next;//返回next数组
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