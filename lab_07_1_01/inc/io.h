#ifndef _IO_H_

#define _IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"


int read_file(char *filename, int *a, int *a_end);
unsigned int fcount(char *filename);
int write_arr(char *filename, int *arr, int *arr_end);

#endif