#include "forceMatch.h"
int main()
{
	String* s=initString();
	String* s1=initString();
	String* s2=initString();
	stringAssign(s, "abcde");
	stringAssign(s1, "cde");
	stringAssign(s2, "ade");
	printString(s);
	printString(s1);
	stringForceMatch(s, s1);
	stringForceMatch(s, s2);

}