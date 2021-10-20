#ifndef _MEM_ALLOC_H_

#define _MEM_ALLOC_H_

#include <stdlib.h>
#include "constants.h"

int **alloc_matrix(int n, int m);
int **realloc_cst(int **matrix, int rows, int cols, int new_rows, int new_cols);
void delete_matr(int **matrix);
#endif