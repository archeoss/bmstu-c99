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
    char author[AUTHOR_LEN];
    int year;
} Movie;

int read_items(FILE *, Movie *, int mode);
int check_key(char *key);
void put_by_title(Movie *movie, char *title, char *author, int year, int count);
void put_by_author(Movie *movie, char *title, char *author, int year, int count);
void put_by_year(Movie *movie, char *title, char *author, int year, int count);

#endif