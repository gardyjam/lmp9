#include "test.h"
#include "gauss.h"
#include "backsubst.h"

#include <stdio.h>

int test( char * fnameA, char * fnameb, char * fnameW );

int czyRowne( Matrix * W, Matrix * X );

int testowanie() {

	//test 1 - poprawne dane, macierz 2x2
	int wynik1 = test("test1A.txt", "test1b.txt", "test1W.txt");
	if (wynik1 == 0)
		fprintf(stderr, "Test 1 [poprawne dane, 2x2]: działanie poprawne");
	else
		fprintf(stderr, "Test 1 [poprawne dane, 2x2]: błąd");

	int wynik2 = test("test2A.txt", "test2b.txt", "test2W.txt");
	if (wynik2 == 0)
		fprintf(stderr, "Test 2 [poprawne dane, 4x4]: działanie poprawne");
	else
		fprintf(stderr, "Test 2 [poprawne dane, 4x4]: błąd");

	int wynik3 = test("test3A.txt", "test3b.txt", "test3W.txt");
	if (wynik3 == 0)
		fprintf(stderr, "Test 3 [A[0][0] = 0]: działanie poprawne");
	else
		fprintf(stderr, "Test 3 [A[0][0] = 0]: błąd");

	int wynik4 = test("test4A.txt", "test4b.txt", "test4W.txt");
	if (wynik4 == 0)
		fprintf(stderr, "Test 4 [macierz osobliwa]: działanie poprawne");
	else
		fprintf(stderr, "Test 4 [macierz osobliwa]: błąd");

	int wynik5 = test("test5A.txt", "test5b.txt", "test5W.txt");
	if (wynik5 == 0)
		fprintf(stderr, "Test 5 [niepoprawne dane]: działanie poprawne");
	else
		fprintf(stderr, "Test 5 [niepoprawne dane]: błąd");
}

int test(char * fnameA, char * fnameb, char * fnameW) {
  int res;
  int result;
  Matrix * A = readFromFile(fnameA);
  Matrix * b = readFromFile(fnameb);
  Matrix * wyniki = readFromFile(fnameW);
  Matrix * x;

  if (A == NULL) return -1;
  if (b == NULL) return -2;
  if (wyniki == NULL) return -4;

  res = eliminate(A,b);
  if (res != 0)
	  return res;
  x = createMatrix(b->r, 1);
  if (x != NULL) {
    res = backsubst(x,A,b);
    if (res != 0)
    	  return res; 
    result = czyRowne(wyniki, x);
    freeMatrix(x);
  } else {
          fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
  }

  freeMatrix(A);
  freeMatrix(b);

  return result;
}

int czyRowne( Matrix * W, Matrix * X ) {
        if( W->c != X->c || W->r != X->r )
		return 1;
	for (int r=0; r < X->r; r++) 
	      for (int c=0; c < X->c; c++)
	      		if( W->data[r][c] != X->data[r][c])
		  		return 1;
	return 0;
}	
 
