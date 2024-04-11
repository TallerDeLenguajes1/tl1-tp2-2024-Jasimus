#include <stdio.h>
#define N 3


struct compu {
	int velocidad;
	int anio;
	int cantidad;
	char* tipo_cpu;
};


int main()
{
	struct compu compus[N];
	char tipos[6][10] = { "Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium" };
	int ntip;
	int i = 0;

	void mostrarPCS(struct compu compus[]);
	void PCvieja(struct compu compus[]);
	void PCrapi(struct compu compus[]);

	while (i < N)
	{
		do 
		{
			printf("velocidad de la PC %d (entre 1 y 3): ", i+1);
			scanf("%d", &compus[i].velocidad);

		} while (compus[i].velocidad < 1 || compus[i].velocidad > 3);

		do
		{
			printf("anio de fabricacion de la PC %d (entre 2015 y 2024): ", i+1);
			scanf("%d", &compus[i].anio);

		} while (compus[i].anio < 2015 || compus[i].anio > 2024);

		compus[i].tipo_cpu = &tipos[0][0];
		do
		{
			printf("tipo de procesador de la PC %d:\n", i+1);
			for (int j = 1; j <= 6; j++)
			{
				printf("\t%d. %s\n", j, tipos[j-1]);
			}
			scanf("%d", &ntip);
		} while (ntip > 6 || ntip < 1);
		compus[i].tipo_cpu = &tipos[ntip-1][0];

		do
		{
			printf("cantidad de nucleos de la PC %d (entre 1 y 8): \n", i+1);
			scanf("%d", &compus[i].cantidad);
		} while (compus[i].cantidad > 8 || compus[i].cantidad < 1);

		i++;
	}
	mostrarPCS(compus);
	PCvieja(compus);
	PCrapi(compus);
	return 0;
}

void mostrarPCS(struct compu compus[])
{
	for (int i = 0; i < N; i++)
	{
		printf("PC %d:\n", i + 1);
		printf("\tvelocidad: %d GHz\n", compus[i].velocidad);
		printf("\tanio de fabricacion: %d\n", compus[i].anio);
		printf("\ttipo de procesador: %s\n", compus[i].tipo_cpu);
		printf("\tcantidad de nucleos: %d nucleos\n", compus[i].cantidad);
		printf("\n");
	}
}

void PCvieja(struct compu compus[])
{
	int ind = 0;
	for (int i = 1; i < N; i++)
	{
		if (compus[i].anio < compus[ind].anio)
		{
			ind = i;
		}
	}
	printf("PC mas vieja: PC %d:\n", ind + 1);
	printf("\tvelocidad: %d GHz\n", compus[ind].velocidad);
	printf("\tanio de fabricacion: %d\n", compus[ind].anio);
	printf("\ttipo de procesador: %s\n", compus[ind].tipo_cpu);
	printf("\tcantidad de nucleos: %d nucleos\n", compus[ind].cantidad);
	printf("\n");
}

void PCrapi(struct compu compus[])
{
	int ind = 0;
	for (int i = 1; i < N; i++)
	{
		if (compus[i].velocidad > compus[ind].velocidad)
		{
			ind = i;
		}
	}
	printf("PC mas rapida: PC %d:\n", ind + 1);
	printf("\tvelocidad: %d GHz\n", compus[ind].velocidad);
	printf("\tanio de fabricacion: %d\n", compus[ind].anio);
	printf("\ttipo de procesador: %s\n", compus[ind].tipo_cpu);
	printf("\tcantidad de nucleos: %d nucleos\n", compus[ind].cantidad);
	printf("\n");
}