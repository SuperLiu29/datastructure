#pragma once
#include <stdlib.h>
#include <stdio.h>
//�ַ����ṹ��
typedef struct String
{
	char* data;//����
	int len;//����
}String;
String* initString();//���һ��String
void stringAssign(String* s,char* data);//��ֵ
void printString(String* s);//���
void stringForceMatch(String* master,String* sub);//����ƥ��

