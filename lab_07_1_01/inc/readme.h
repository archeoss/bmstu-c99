#ifndef _README_H_

#define _README_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NO_ERROR 0
#define KEY_ERROR 1
#define INCORRECT_DATA_ERROR 2
#define NOT_FOUND 3


int read_file(FILE *f, int *a, int *a_end);
unsigned int fcount(FILE *f);
int write_arr(FILE *f, int *arr, int *arr_end);

#endif