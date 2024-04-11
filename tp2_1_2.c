#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
	int i;
	int vt[N];
	int* p = &vt[0];

	for (i = 0; i < N; i++)
	{
		*(p + i) = 1 + rand() % 100;
		printf("%d ", *(p + i));
	}
	return 0;
}
