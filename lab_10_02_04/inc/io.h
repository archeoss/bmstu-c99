#ifndef _IO_H_

#define _IO_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "errors.h"
#include "operations.h"
#include "defines.h"

node_t *get_number();
int get_mode();
void print_simple(node_t **head);

#endif