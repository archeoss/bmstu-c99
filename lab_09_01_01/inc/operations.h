#ifndef _OPERATIONS_H_

#define _OPERATIONS_H_

#define  _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "structures.h"
#include "errors.h"
#include "defines.h"
#include "io.h"


int check_key(char *key);
void put_by_title(movie_struct *movie, movie_struct last_movie, int count);
void put_by_name(movie_struct *movie, movie_struct last_movie, int count);
void put_by_year(movie_struct *movie, movie_struct last_movie, int count);
int compare(movie_struct movie, char *keyword, int year, int mode);
int get_count(FILE *f);
void clear_array(movie_struct *movies, int count);
void swap(movie_struct *movie, movie_struct *last_movie);
void put(movie_struct *movie, movie_struct last_movie);
void list_move(movie_struct *movie, movie_struct *last_movie, int flag, int i, int count);
int check_line(char *line);
movie_struct *bin_search(movie_struct *movies, int n, char *keyword, int year, int mode);

#endif