#include "kmp.h"
void text()
{
	String* s = initString();
	String* s1 = initString();
	stringAssign(s, "ababacb");
	stringAssign(s1, "ababcacd");
	printString(s);
	printString(s1);
	int* next = getNext(s1);
	for (int i = 0; i < s1->len; i++)
	{
		printf(i == 0 ? "%d" : "->%d", next[i]);
	}
	printf("\n");
	kmpMatch(s, s1, next);
}
int main()
{
	text();
}