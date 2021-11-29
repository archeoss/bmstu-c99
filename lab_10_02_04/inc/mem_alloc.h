#ifndef _MEM_ALLOC_H_

#define _MEM_ALLOC_H_

#include <stdlib.h>
#include <stdio.h>
#include "defines.h"
#include "structures.h"
#include "errors.h"

void alloc_node(node_t **head, node_t **cur_node);
void clear_list(node_t *head);

#endif