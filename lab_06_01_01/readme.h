#ifndef _README_H_

#define _README_H_

#define TITLE_LEN 26
#define AUTHOR_LEN 26

#define NO_MODE -1
#define TITLE_MODE 0
#define AUTHOR_MODE 1
#define YEAR_MODE 2

typedef struct 
{
    char title[TITLE_LEN];
    char name[AUTHOR_LEN];
    int year;
} movie_struct;

int read_items(FILE *, movie_struct *, int mode);
int check_key(char *key);
void put_by_title(movie_struct *movie, movie_struct last_movie, int count);
void put_by_name(movie_struct *movie, movie_struct last_movie, int count);
void put_by_year(movie_struct *movie, movie_struct last_movie, int count);

#endif