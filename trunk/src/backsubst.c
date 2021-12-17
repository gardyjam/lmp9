#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
**/

int backsubst(Matrix *x, Matrix *mat, Matrix *b)
{

	int i, j; // zmienne pomocnicze
	double sum;
	int r = x->r - 1;
	int c = mat->c - 1;

	// sprawdzam, czy wymiary macierzy są poprawne
	if (mat->r - 1 != b->r - 1 || mat->r - 1 != mat->c - 1)
		return 2;

	// ostatnie równanie - osobny przypadek
	if (mat->data[r - 1][c - 1] != 0.0)
	{
		x->data[r - 1][0] = b->data[b->r - 1][0] / mat->data[r - 1][c - 1];
		printf("x(%d) = %f\n", r, x->data[r - 1][0]);
	}
	else
		return 1;

	// pozostałe równania - od równania r-1 do 0
	for (i = (mat->r - 1); i >= 0; i--)
	{
		sum = 0.0;

		if (mat->data[i][i] == 0)
			return 1;

		for (j = i + 1; j < mat->r - 1; j++)
			sum += x->data[j][0] * mat->data[i][j];

		x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
	}

	return 0;
}
