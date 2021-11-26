#ifndef _SORT_H_

#define _SORT_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "errors.h"
#include "list_operations.h"
#include "operations.h"

void front_back_split(node_t *head, node_t **back);
node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
void sort(node_t **head, int (*comparator)(const void *, const void *));

#endif