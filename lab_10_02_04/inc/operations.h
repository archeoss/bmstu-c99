#ifndef _OPERATIONS_H_

#define _OPERATIONS_H_

#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "structures.h"
#include "errors.h"
#include "mem_alloc.h"

void *pop_front(node_t **head);
void *pop_back(node_t **head);
node_t *make_simple(int number);
int compare_numbers(const void *dat_a, const void *dat_b);
node_t *simple_mul(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *));
void simple_sqr(node_t *head);
void pop_number(node_t **head, node_t *elem);
int simple_div(node_t **head_a, node_t **head_b);

#endif