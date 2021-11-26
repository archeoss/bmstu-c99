#ifndef _OPERATIONS_H_

#define _OPERATIONS_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "errors.h"

int compare_char(const void *node_a, const void *node_b);
int check_line(char *line);
int compare_rating(const void *node_a, const void *node_b);
int priority_check(const void *node_a);
int check_rating(const void *data_a);

#endif