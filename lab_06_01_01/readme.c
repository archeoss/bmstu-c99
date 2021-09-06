#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readme.h"

void swap(Movie *movie, char *title, char *author, int *year);


int read_items(FILE *f, Movie *movie, int mode)
{
    char junk[10];
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
    int rc = 0;
    if (fgets(title, TITLE_LEN, f) != NULL && title[0] != '\n' && title[strlen(title)-1] == '\n')
        rc++;
    if (fgets(author, AUTHOR_LEN, f) != NULL && author[0] != '\n' && author[strlen(author)-1] == '\n')
        rc++;
    rc += (fscanf(f, "%d", &year) > 0) ? 1 : 0;
    int count = 0;
    while (rc == 3)
    {
        rc = 0;
        if (count == 0)
        {
            strcpy(movie[0].title, title);
            strcpy(movie[0].author, author);
            movie[0].year = year;
        }
        else
        {
            switch (mode)
            {
                case TITLE_MODE:
                    put_by_title(movie, title, author, year, count);
                    break;
                case AUTHOR_MODE:
                    put_by_author(movie, title, author, year, count);
                    break;
                case YEAR_MODE:
                    put_by_year(movie, title, author, year, count);
                    break;
            }
        }
        fgets(junk, 10, f); //После fscanf остается лишний \n, который мешает fgets
        if (fgets(title, TITLE_LEN, f) != NULL && title[0] != '\n' && title[strlen(title) - 1] == '\n')
            rc++;
        if (fgets(author, AUTHOR_LEN, f) != NULL && author[0] != '\n' && author[strlen(author) - 1] == '\n')
            rc++;
        rc += (fscanf(f, "%d", &year) > 0) ? 1 : 0;
        count++;
    }
    if (rc > 0)
        count = 0;
    return count;
}

int check_key(char *key)
{
    int mode;
    if (strcmp(key, "title") == 0)
        mode = TITLE_MODE;
    else if (strcmp(key, "author") == 0)
        mode = AUTHOR_MODE;
    else if (strcmp(key, "year") == 0)
        mode = YEAR_MODE;
    else
        mode = NO_MODE;
    return mode;
}

void put_by_title(Movie *movie, char *title, char *author, int year, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (strcmp(movie[i].title, title) > 0)
        {
            swap(&movie[i], title, author, &year);
            flag = 0;
        }
        i++;
    }
    if (flag)
    {
        strcpy(movie[i].title, title);
        strcpy(movie[i].author, author);
        movie[i].year = year;
    }
    else
    {
        for (; i < count; i++)
        {
            swap(&movie[i], title, author, &year);
        }
        strcpy(movie[i].title, title);
        strcpy(movie[i].author, author);
        movie[i].year = year;
    }
}
void put_by_author(Movie *movie, char *title, char *author, int year, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (strcmp(movie[i].author, author) > 0)
        {
            swap(&movie[i], title, author, &year);
            flag = 0;
        }
        i++;
    }
    if (flag)
    {
        strcpy(movie[i].title, title);
        strcpy(movie[i].author, author);
        movie[i].year = year;
    }
    else
    {
        for (; i < count; i++)
        {
            swap(&movie[i], title, author, &year);
        }
        strcpy(movie[i].title, title);
        strcpy(movie[i].author, author);
        movie[i].year = year;
    }
}
void put_by_year(Movie *movie, char *title, char *author, int year, int count)
{
    int i = 0;
    int flag = 1;
    while (flag && i < count)
    {
        if (movie[i].year > year)
        {
            
            swap(&movie[i], title, author, &year);
            flag = 0;
        }
        i++;
    }
    if (flag)
    {
        strcpy(movie[i].title, title);
        strcpy(movie[i].author, author);
        movie[i].year = year;
    }
    else
    {
        for (; i < count; i++)
        {
            swap(&movie[i], title, author, &year);
        }
        strcpy(movie[i].title, title);
        strcpy(movie[i].author, author);
        movie[i].year = year;
    }
}

void swap(Movie *movie, char *title, char *author, int *year)
{
    char title_tmp[TITLE_LEN];
    char author_tmp[AUTHOR_LEN];
    int year_tmp;
    strcpy(title_tmp, movie->title);
    strcpy(author_tmp, movie->author);
    year_tmp = movie->year;
    strcpy(movie->title, title);
    strcpy(movie->author, author);
    movie->year = *year;
    strcpy(title, title_tmp);
    strcpy(author, author_tmp);
    *year = year_tmp;
}