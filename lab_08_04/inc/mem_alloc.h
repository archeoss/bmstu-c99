#ifndef _MEM_ALLOC_H_

#define _MEM_ALLOC_H_

#include <stdlib.h>
#include "constants.h"

long long **alloc_matrix(long long n, long long m);
long long **realloc_cst(long long **matrix, long long rows, long long cols, long long new_rows, long long new_cols);
void delete_matr(long long **matrix);
#endif