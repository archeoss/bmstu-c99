#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readme.h"

#define STRUCT_COUNT 15

void swap(movie_struct *movie, char *title, char *name, int *year);
void put(movie_struct *movie, char *title, char *name, int year);

int read_items(FILE *f, movie_struct *movie, int mode)
{
    char junk[10];
    char title[TITLE_LEN];
    char name[AUTHOR_LEN];
    int year;
    int rc = 0;
    if (fgets(title, TITLE_LEN, f) != NULL && title[0] != '\n' && title[strlen(title)-1] == '\n')
        rc++;
    if (fgets(name, AUTHOR_LEN, f) != NULL && name[0] != '\n' && name[strlen(name)-1] == '\n')
        rc++;
    rc += (fscanf(f, "%d", &year) > 0) ? 1 : 0;
    fgets(junk, 10, f); //После fscanf остается лишний \n, который мешает fgets
    int count = 0;
    while (rc == 3 && count < STRUCT_COUNT)
    {
        rc = 0;
        if (count == 0)
            put(&movie[0], title, name, year);
        else
            switch (mode)
            {
                case TITLE_MODE:
                    put_by_title(movie, title, name, year, count);
                    break;
                case AUTHOR_MODE:
                    put_by_name(movie, title, name, year, count);
                    break;
                case YEAR_MODE:
                    put_by_year(movie, title, name, year, count);
                    break;
            }
        if (fgets(title, TITLE_LEN, f) != NULL && title[0] != '\n' && title[strlen(title) - 1] == '\n')
            rc++;
        if (fgets(name, AUTHOR_LEN, f) != NULL && name[0] != '\n' && name[strlen(name) - 1] == '\n')
            rc++;
        rc += (fscanf(f, "%d", &year) > 0) ? 1 : 0;
        fgets(junk, 10, f); //После fscanf остается лишний \n, который мешает fgets
        count++;
    }
    if (rc > 0)
        count = 0;
    else if (fgets(junk, 10, f)!= NULL)
        count = 0; 
    return count;
}

int check_key(char *key)
{
    int mode;
    if (strcmp(key, "title") == 0)
        mode = TITLE_MODE;
    else if (strcmp(key, "name") == 0)
        mode = AUTHOR_MODE;
    else if (strcmp(key, "year") == 0)
        mode = YEAR_MODE;
    else
        mode = NO_MODE;
    return mode;
}

void put_by_title(movie_struct *movie, char *title, char *name, int year, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (strcmp(movie[i].title, title) > 0)
        {
            swap(&movie[i], title, name, &year);
            flag = 0;
        }
        i++;
    }
    if (flag)
        put(&movie[i], title, name, year);
    else
    {
        for (; i < count; i++)
            swap(&movie[i], title, name, &year);
        put(&movie[i], title, name, year);
    }
}
void put_by_name(movie_struct *movie, char *title, char *name, int year, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (strcmp(movie[i].name, name) > 0)
        {
            swap(&movie[i], title, name, &year);
            flag = 0;
        }
        i++;
    }
    if (flag)
        put(&movie[i], title, name, year);
    else
    {
        for (; i < count; i++)
            swap(&movie[i], title, name, &year);
        put(&movie[i], title, name, year);
    }
}
void put_by_year(movie_struct *movie, char *title, char *name, int year, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (movie[i].year > year)
        {
            
            swap(&movie[i], title, name, &year);
            flag = 0;
        }
        i++;
    }
    if (flag)
        put(&movie[i], title, name, year);
    else
    {
        for (; i < count; i++)
            swap(&movie[i], title, name, &year);
        put(&movie[i], title, name, year);
    }
}

void put(movie_struct *movie, char *title, char *name, int year)
{
    strcpy(movie->title, title);
    strcpy(movie->name, name);
    movie->year = year;
}

void swap(movie_struct *movie, char *title, char *name, int *year)
{
    char title_tmp[TITLE_LEN];
    char name_tmp[AUTHOR_LEN];
    int year_tmp;
    strcpy(title_tmp, movie->title);
    strcpy(name_tmp, movie->name);
    year_tmp = movie->year;
    put(movie, title, name, *year);
    strcpy(title, title_tmp);
    strcpy(name, name_tmp);
    *year = year_tmp;
}