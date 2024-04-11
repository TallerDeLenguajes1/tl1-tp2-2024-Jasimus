#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 7

int main()
{
	int i,j;
	int mt[N][M];
	int* p = &mt[0][0];

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M*sizeof(int); j+= sizeof(int))
		{
			*(p + j) = 1 + rand() % 100;
			printf("%d ", *(p + j));
		}
		p++;
		printf("\n");
	}
	return 0;
}
