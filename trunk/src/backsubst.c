#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */

// PIERWSZA WERSJA - PODSTAWOWA (do poprawy)
// nie jest przystosowana do przypadku wprowadzenia błędnych danych 
// nie wyświetla żadnych komuniatów o błędzie, nie ma przypadku zwracania 1 lub 2

int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i,j; // zmienne pomocnicze
	double sum;

	// oststanie równanie - osobny przypadek
	x->data[r][0] = b->data[r][0]/mat->data[r][c];

	// pozostałe równania - od równania r-1 do 0
	for( i = r-1; i >= 0; i-- ) {
		sum = 0;
		for( j = i+1; j <= r; j++ ) {
			sum += x->data[j][0] * mat->data[i][j];
		}
		x->data[i][0] = (b->data[i][0]-sum) mat->data[i][i];
	}

	return 0;
}


