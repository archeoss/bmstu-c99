#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readme.h"

#define STRUCT_COUNT 15
#define JUNK_LEN 10

void swap(movie_struct *movie, movie_struct *);
void put(movie_struct *movie, movie_struct);
void list_move(movie_struct *movie, movie_struct *last_movie, int flag, int i, int count);

int read_items(FILE *f, movie_struct *movie, int mode)
{
    char junk[JUNK_LEN];
    movie_struct last_movie;
    int rc = 0;
    if (fgets(last_movie.title, TITLE_LEN, f) != NULL && last_movie.title[0] != '\n' && last_movie.title[strlen(last_movie.title) - 1] == '\n')
        rc++;
    if (fgets(last_movie.name, AUTHOR_LEN, f) != NULL && last_movie.name[0] != '\n' && last_movie.name[strlen(last_movie.name) - 1] == '\n')
        rc++;
    rc += (fscanf(f, "%d", &last_movie.year) > 0 && last_movie.year >= 0) ? 1 : 0;
    fgets(junk, JUNK_LEN, f); //После fscanf остается лишний \n, который мешает fgets
    int count = 0;
    while (rc == 3 && count < STRUCT_COUNT)
    {
        rc = 0;
        if (count == 0)
            put(movie, last_movie);
        else
        {
            switch (mode)
            {
                case TITLE_MODE:
                    put_by_title(movie, last_movie, count);
                    break;
                case AUTHOR_MODE:
                    put_by_name(movie, last_movie, count);
                    break;
                case YEAR_MODE:
                    put_by_year(movie, last_movie, count);
                    break;
            }
        }
        if (fgets(last_movie.title, TITLE_LEN, f) != NULL && last_movie.title[0] != '\n' && last_movie.title[strlen(last_movie.title) - 1] == '\n')
            rc++;
        if (fgets(last_movie.name, AUTHOR_LEN, f) != NULL && last_movie.name[0] != '\n' && last_movie.name[strlen(last_movie.name) - 1] == '\n')
            rc++;
        rc += (fscanf(f, "%d", &last_movie.year) > 0 && last_movie.year >= 0) ? 1 : 0;
        fgets(junk, JUNK_LEN, f); //После fscanf остается лишний \n, который мешает fgets
        count++;
    }
    if (rc > 0)
        count = 0;
    else if (fgets(junk, JUNK_LEN, f) != NULL)
        count = 0; 
    return count;
}

int check_key(char *key)
{
    int mode;
    if (!strcmp(key, "title"))
        mode = TITLE_MODE;
    else if (!strcmp(key, "name"))
        mode = AUTHOR_MODE;
    else if (!strcmp(key, "year"))
        mode = YEAR_MODE;
    else
        mode = NO_MODE;
    return mode;
}

void put_by_title(movie_struct *movie, movie_struct last_movie, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (strcmp(movie[i].title, last_movie.title) > 0)
        {
            swap(&movie[i], &last_movie);
            flag = 0;
        }
        i++;
    }
    list_move(movie, &last_movie, flag, i, count);
}
void put_by_name(movie_struct *movie, movie_struct last_movie, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (strcmp(movie[i].name, last_movie.name) > 0)
        {
            swap(&movie[i], &last_movie);
            flag = 0;
        }
        i++;
    }
    list_move(movie, &last_movie, flag, i, count);
}
void put_by_year(movie_struct *movie, movie_struct last_movie, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (movie[i].year > last_movie.year)
        {
            swap(&movie[i], &last_movie);
            flag = 0;
        }
        i++;
    }
    list_move(movie, &last_movie, flag, i, count);
}

void put(movie_struct *movie, movie_struct last_movie)
{
    *movie = last_movie;
}

void swap(movie_struct *movie, movie_struct *last_movie)
{
    movie_struct movie_tmp;
    movie_tmp = *movie;
    put(movie, *last_movie);
    *last_movie = movie_tmp;
}

void list_move(movie_struct *movie, movie_struct *last_movie, int flag, int i, int count)
{
    if (flag)
        put(&movie[i], *last_movie);
    else
    {
        for (; i < count; i++)
            swap(&movie[i], last_movie);
        put(&movie[i], *last_movie);
    }
}