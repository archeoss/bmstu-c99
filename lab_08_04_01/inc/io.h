#ifndef _IO_H_

#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "errors.h"
#include "constants.h"

int **get_matrix(int rows, int cols);
int input_matrix(int **matrix, int n, int m);
void print_matrix(int **matrix, int rows, int cols);


#endif