#ifndef _SORT_H_

#define _SORT_H_

#define NO_ERROR 0
#define KEY_ERROR 1
#define INCORRECT_DATA_ERROR 2

#include <stdio.h>
#include <stdlib.h>

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void mysort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *));


#endif