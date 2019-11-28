#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int **Make2DArray(int row, int col)
{
	int **a, i;

	/*动态申请row行个int指针类型的内存空间，内存不足时退出*/
	if((a = (int **)malloc(row * sizeof(int *))) == NULL)
	{
		printf("内存空间不够！");
		exit(0);
	}

	for (i = 0; i < row; i++)
		if((a[i] = (int *)malloc(col * sizeof(int))) == NULL)
		{
			printf("内存空间不够！");
			exit(0);
		}
	return a;
}

Diliver2DArray(int **a, int row)
{
	int i;

	for(i = 0; i < row; i++)
		free(a[i]);
	free(a);	
}

void main(void)
{
	int i, j, c;
	int row = 3, col = 4, **a;

	a = Make2DArray(row, col);

	c = 1;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			a[i][j] = c;
			c++;
		}
	}

	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf("%4d   ", a[i][j]);
		printf("\n");
	}

	Diliver2DArray(a, row);
}