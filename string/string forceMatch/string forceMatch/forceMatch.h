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
void stringAssign(String* s,char* data);//赋值
void printString(String* s);//输出
void stringForceMatch(String* master,String* sub);//暴力匹配

