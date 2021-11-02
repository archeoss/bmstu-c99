#ifndef _IO_H_

#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "errors.h"
#include "constants.h"

long long **get_matrix(int rows, int cols);
int input_matrix(long long **matrix, int n, int m);
void print_matrix(long long **matrix, int rows, int cols);


#endif