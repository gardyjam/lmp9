#include "gauss.h"
#include <math.h>


//#include <stdio.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b)
{
	double Ratio;
	int i;
	
	if (mat->data[0][0] == 0)
		return 1;

	for (i = 0; i < (mat->c - 1); i++)  
	{
		int t;
		int tempR = i;
		double tempV = mat->data[tempR][i];
		double pom;
		
		for (t = i+1; t < mat->r; t++ ) 
			if (fabs(mat->data[t][i]) > tempV)
			{
				tempV = mat->data[t][i];
				tempR = t;
			}

		if ( tempR != i ) 
		{
			for (int w=0; w < mat->c; w++) // <= ?
			{
				pom = mat->data[i][w];
				mat->data[i][w] = mat->data[tempR][w];
				mat->data[tempR][w] = pom;

			}
			pom = b->data[i][0];
			b->data[i][0] = b->data[tempR][0];
			b->data[tempR][0] = pom;
		}	

		for (int j = i+1; j < mat->r; j++) 
		{
			Ratio = mat->data[j][i] / mat->data[i][i];
			
			for (int k = 0; k < mat->c; ++k)
			{
				mat->data[j][k] -= Ratio * mat->data[i][k];
			}	
			b->data[j][0] -= Ratio * b->data[i][0]; 
		}
	}

	return 0;
}

