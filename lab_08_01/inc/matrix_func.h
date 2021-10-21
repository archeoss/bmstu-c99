#ifndef _MATRIX_FUNC_H_

#define _MATRIX_FUNC_H_


#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"

int **make_equal(int **matrix, int size, int to_append);
void delete_row(int **matrix, int rows, int cols, int row);
void delete_col(int **matrix, int cols, int rows, int col);
int **make_it_square(int **matrix, int rows, int cols);
int **matrix_pow(int **matrix, int size, int pow_num);
int **matrix_multiplication(int **matrix_a, int **matrix_b, int size);

#endif