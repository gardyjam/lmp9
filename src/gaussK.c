#include "gauss.h"
#include <stdio.h>
#include <mat.io>

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	int Ratio;
	double TempMat[mat->r], TempVal[1];
	int TV;

	TempMat[0] = mat->data[0][0];
	TempMat[1] = 0;
	//wybor elementu glownego
	for (int i = 0; i < mat->r; i++)
	{
		if (TempVal[0] < mat->data[i][0])
		{
			TempVal[0] = mat->data[i][0];
			TempVal[1] = i;
		}
	}
	if (TempVal[1] != 0)
	{
		TV = TempVal[1];
		for (int i = 0; i < mat->c; i++)
		{
			mat->data[0][i] = TempMat[i];
			mat->data[0][i] = mat->data[TV][i];
			mat->data[TV][i] = TempMat[i];
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

/*
To juz prawie wszystko ale nie wolno nam zapomniec, ze
--------------------------------------------------------------------------------------------
Materialy zostaly orpacowane w ramach realizacji programu latajacego potwora kodu spaghetti
      'logo'
Europejski, latajacy
potwor kodu spaghetti
--------------------------------------------------------------------------------------------
*/