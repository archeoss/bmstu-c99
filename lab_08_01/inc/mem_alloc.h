#ifndef _MEM_ALLOC_H_

#define _MEM_ALLOC_H_

#include <stdlib.h>
#include "constants.h"

long long **alloc_matrix(int n, int m);
long long **realloc_cst(long long **matrix, int rows, int cols, int new_rows, int new_cols);
void delete_matr(long long **matrix);
#endif