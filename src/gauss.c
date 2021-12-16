#include "gauss.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int Ratio;
	int i;

	if (mat->data[0][0] == 0)
		return 1;

	for (i = 0; i < mat->c; i++)
	{
		int t;
		int tempR = i;
		double tempV = mat->data[tempR][i];
		double pom;

		for (t = i + 1; t < mat->r; t++)
			if (fabs(mat->data[t][i]) > tempV)
			{
				tempV = mat->data[t][i];
				tempR = t;
			}
		if (tempR != i)
			for (int w = 0; w <= mat->c; w++)
			{
				pom = mat->data[i][w];
				mat->data[i][w] = mat->data[t][w];
				mat->data[t][w] = pom;
			}

		for (int j = i + 1; j < mat->r; j++)
		{
			Ratio = mat->data[j][i] / mat->data[i][i];
			for (int k = i; k < mat->c; k++)
			{
				mat->data[j][k] -= Ratio * mat->data[i][k];
			}
			mat->data[j][i] = 0;
		}
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TEMP TEMP TEMP TEMP

	printf("Element glowny: \n");
	printf("[ \n");
	for (int i = 0; i < mat->r; i++)
	{
		printf("  ");
		for (int j = 0; j < mat->c; j++)
		{
			printf("%f ", mat->data[i][j]);
		}
		printf("; \n");
	}
	printf("]\n");

	//tworzenie diagonala
	if (mat->data[0][0] == 0)
		return 1;

	for (int i = 0; i < mat->r; i++)
	{
		for (int j = 0; j < mat->c; j++)
		{
			if (j > i)
			{
				Ratio = mat->data[j][i] / mat->data[i][i];
				for (int k = 0; k < mat->r; k++)
				{
					mat->data[j][k] = mat->data[j][k] - Ratio * mat->data[i][k];
				}
			}
		}
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! TEMP TEMP TEMP TEMP

	printf("Diagonal: \n");
	printf("[ \n");
	for (int i = 0; i < mat->r; i++)
	{
		printf("  ");
		for (int j = 0; j < mat->c; j++)
		{
			printf("%f ", mat->data[i][j]);
		}
		printf("; \n");
	}
	printf("]\n");

	return 0;
}
