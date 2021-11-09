#ifndef _README_H_

#define _README_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "errors.h"
#include "operations.h"
#include "defines.h"

int read_items(FILE *, movie_struct *, int mode);
void show_all(movie_struct *, int n);
int find_item(movie_struct *, char *, int n, int mode);
int read_struct(movie_struct *last_movie, FILE *f);
void put_by_field(movie_struct *movie, movie_struct last_movie, int count, int mode);

#endif