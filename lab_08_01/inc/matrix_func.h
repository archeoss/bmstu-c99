#ifndef _MATRIX_FUNC_H_

#define _MATRIX_FUNC_H_


#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

long long **make_equal(long long **matrix, int size, int to_append);
void delete_row(long long **matrix, int rows, int cols, int row);
void delete_col(long long **matrix, int cols, int rows, int col);
long long **make_it_square(long long **matrix, int rows, int cols);
long long **matrix_pow(long long **matrix, int size, int pow_num);
long long **matrix_multiplication(long long **matrix_a, long long **matrix_b, int size);

#endif