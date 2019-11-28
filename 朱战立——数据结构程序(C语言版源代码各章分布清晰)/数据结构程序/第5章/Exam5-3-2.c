#include <stdio.h>
#define MaxSize 100
typedef int elemtype;
typedef struct
{
	int i;
	int j;
	elemtype d;
} DataType;

typedef struct
{
	int md;
	int nd;
	int td;
}TriType;

#include "SeqList.h"

void Transition2(SeqList a, TriType da, SeqList *b, TriType *db)
{
	int p;

	db->md = da.nd;
	db->nd = da.md;
	db->td = da.td;
	if(da.td != 0)
	for(p = 0; p < da.td; p++)
	{
		b->list[p].i = a.list[p].j;
		b->list[p].j = a.list[p].i;
		b->list[p].d = a.list[p].d;
	}
}

void main(void)
{
	SeqList listA, listB;
	TriType myA = {6,7,6}, myB;
	DataType a[] = {{1,3,11},{1,5,17},{2,2,25},{4,1,19},
				{5,4,37},6,7,50};
	int i;

	ListInitiate(&listA);
	for(i = 0; i < myA.td; i++)
		ListInsert(&listA, i, a[i]);

	Transition2(listA, myA, &listB, &myB);

	printf("%d   %d   %d\n", myB.md, myB.nd, myB.td);
	for(i = 0; i < myB.td; i++)
		printf("%d   %d   %d\n", listB.list[i].i, 
				listB.list[i].j, listB.list[i].d);
}