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
/*a为转置前的三元组顺序表，da是a的控制数据*/
/*三元组顺序表a按先行序后列序的顺序存放*/
/*b为转置后的三元组顺序表，db是b的控制数据*/
{
	int p, q, v;

	db->md = da.nd;					/*行数值转为列数值*/
	db->nd = da.md;					/*列数值转为行数值*/
	db->td = da.td;					/*非零元个数不变*/

	if(da.td == 0)	return;
	else
	{
		q = 0;						/*q为b->list[]的下标值*/
		for(v = 1; v <= da.nd; v++)
		{
			for(p = 0; p < da.td; p++)		/*p为a.list[]的下标值*/
			{
				if(a.list[p].j == v)  /*寻找原矩阵中列下标值最小的*/
				{
					b->list[q].i = a.list[p].j;		/*列号转为行号*/
					b->list[q].j = a.list[p].i;		/*行号转为列号*/
					b->list[q].d = a.list[p].d;		/*数组元素复制*/
					q++;
				}
			}
		}
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

	printf("行数：%d  列数：%d  非零元数：%d\n", myB.md, myB.nd, myB.td);
	printf("三元组元素依次为：\n");
	for(i = 0; i < myB.td; i++)
		printf("%d   %d   %d\n", listB.list[i].i, 
				listB.list[i].j, listB.list[i].d);
}