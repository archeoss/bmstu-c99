#ifndef _LIST_OPERATIONS_H_

#define _LIST_OPERATIONS_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "operations.h"
#include "structures.h"
#include "errors.h"

void *pop_front(node_t **head);
void push(node_t **head, node_t *cur_node);
void insert(node_t **head, node_t *elem, node_t *before);
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));
size_t get_count(node_t *cur_node);
void free_list(node_t *cur_node);
void priority_change(node_t **head);

#endif