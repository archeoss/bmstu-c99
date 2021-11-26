#ifndef _IO_H_

#define _IO_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "errors.h"
#include "operations.h"
#include "list_operations.h"

#define JUNK_LEN 10

int read_items(char *filename, node_t **list);
void show_all(node_t *list);
int file_list(char *filename, node_t *head);

#endif