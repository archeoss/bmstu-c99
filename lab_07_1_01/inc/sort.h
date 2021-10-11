#ifndef _SORT_H_

#define _SORT_H_


#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

void swap(char *ptr1, char *ptr2, size_t size);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *));
int comp(const void *i, const void *j);

#endif