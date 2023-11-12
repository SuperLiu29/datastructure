#include "list.h"
void textList()
{
	node* phead = listInit();
	pushListBack(phead, 1);
	pushListBack(phead, 2);
	pushListBack(phead, 2);
	
	listPrint(phead);
	printf("\n");
	popListBack(phead);
	popListBack(phead);
	popListBack(phead);
	listPrint(phead);
}
int main()
{
	textList();
}