#ifndef _MATRIX_FUNC_H_

#define _MATRIX_FUNC_H_


#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

long long **make_equal(long long **matrix, long long size, long long to_append);
void delete_row(long long **matrix, long long rows, long long cols, long long row);
void delete_col(long long **matrix, long long cols, long long rows, long long col);
long long **make_it_square(long long **matrix, long long rows, long long cols);
long long **matrix_pow(long long **matrix, long long size, long long pow_num);
long long **matrix_multiplication(long long **matrix_a, long long **matrix_b, long long size);

#endif