#ifdef _TEST_H
#define _TEST_H

#include "mat_io.h"
#include "gauss.h"
#include "backsubst.h"

int test( char * fnameA, char * fnameb, char * fnameW );

int czyRowne( Matrix * W, Matrix * X );

#endif

