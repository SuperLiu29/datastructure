#pragma once
#pragma once
#include <stdlib.h>
#include <stdio.h>
//字符串结构体
typedef struct String
{
	char* data;//数据
	int len;//长度
}String;
String* initString();//获得一个String
void stringAssign(String* s, char* data);//赋值
void printString(String* s);//输出
int* getNext(String* s);//获得next值
void kmpMatch(String* master, String* sub, int* next);//执行匹配
