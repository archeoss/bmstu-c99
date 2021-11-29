#ifndef _IO_H_

#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "errors.h"
#include "constants.h"

long long **get_matrix(long long rows, long long cols);
int input_matrix(long long **matrix, long long n, long long m);
void print_matrix(long long **matrix, long long rows, long long cols);


#endif