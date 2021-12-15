#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i,j; // zmienne pomocnicze
	double sum;
	int r = mat->r;
	int c = mat->c;

	// sprawdzam, czy wymiary macierzy są poprawne
	if( mat->r != b->r || mat->r != mat->c )
		return 2;
	
	// ostatnie równanie - osobny przypadek
	if( mat->data[r][c] != 0 ) 
		x->data[r][0] = b->data[r][0]/mat->data[r][c];
	else 
		return 1;
	// pozostałe równania - od równania r-1 do 0
	for( i = r-1; i >= 0; i-- ) {
		sum = 0;
		for( j = i+1; j <= c; j++ ) {
			sum += x->data[j][0] * mat->data[i][j];
		}
		if( mat->data[i][i] != 0 )
			x->data[i][0] = (b->data[i][0]-sum)/ mat->data[i][i];
		else
			return 1;
	}

	return 0;
}


