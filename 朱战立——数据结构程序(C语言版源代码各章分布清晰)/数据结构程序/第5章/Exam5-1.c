#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int *a, n = 10, i;

	if((a = (int *)malloc(n * sizeof(int))) == NULL)
	{
		printf("�ڴ�ռ䲻����");
		exit(0);
	}

	for(i = 0; i < n; i++)
		a[i] = i + 1;

	for(i = 0; i < n; i++)
		printf("%d   ", a[i]);

	free(a);
}