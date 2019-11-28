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
/*aΪת��ǰ����Ԫ��˳���da��a�Ŀ�������*/
/*��Ԫ��˳���a��������������˳����*/
/*bΪת�ú����Ԫ��˳���db��b�Ŀ�������*/
{
	int p, q, v;

	db->md = da.nd;					/*����ֵתΪ����ֵ*/
	db->nd = da.md;					/*����ֵתΪ����ֵ*/
	db->td = da.td;					/*����Ԫ��������*/

	if(da.td == 0)	return;
	else
	{
		q = 0;						/*qΪb->list[]���±�ֵ*/
		for(v = 1; v <= da.nd; v++)
		{
			for(p = 0; p < da.td; p++)		/*pΪa.list[]���±�ֵ*/
			{
				if(a.list[p].j == v)  /*Ѱ��ԭ���������±�ֵ��С��*/
				{
					b->list[q].i = a.list[p].j;		/*�к�תΪ�к�*/
					b->list[q].j = a.list[p].i;		/*�к�תΪ�к�*/
					b->list[q].d = a.list[p].d;		/*����Ԫ�ظ���*/
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

	printf("������%d  ������%d  ����Ԫ����%d\n", myB.md, myB.nd, myB.td);
	printf("��Ԫ��Ԫ������Ϊ��\n");
	for(i = 0; i < myB.td; i++)
		printf("%d   %d   %d\n", listB.list[i].i, 
				listB.list[i].j, listB.list[i].d);
}