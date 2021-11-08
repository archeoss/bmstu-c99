#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readme.h"
#include "showme.h"

#define NO_ERROR 0
#define KEY_ERROR 1
#define INCORRECT_DATA_ERROR 2
#define NOT_FOUND 3

int compare(movie_struct movie, char *keyword, int year, int mode);

void show_all(movie_struct *movie, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s%s%d\n", movie[i].title, movie[i].name, movie[i].year);
    }
}

int find_item(movie_struct *movie, char *keyword, int n, int mode)
{
    int error_code = NO_ERROR;
    int year;
    char *end;
    if (mode == YEAR_MODE)
    {
        year = strtol(keyword, &end, 10);
        if (year <= 0 || *end != '\0')
            error_code = KEY_ERROR;
    }
    else
        strcat(keyword, "\n");
    if (error_code == NO_ERROR)
    {
        error_code = NOT_FOUND;
        int end = n;
        int start = 0;
        while (start != end)
        {
            int compare_res;
            int mid = start + (end - start) / 2;
            compare_res = compare(movie[mid], keyword, year, mode);
            if (compare_res == 0)
            {
                end = start;
                error_code = NO_ERROR;
                printf("%s%s%d\n", movie[mid].title, movie[mid].name, movie[mid].year);
            }
            else if (compare_res > 0)
                end = mid;
            else
                start = mid + 1;
        }
    }
    return error_code;
}

int compare(movie_struct movie, char *keyword, int year, int mode)
{    
    int compare_res;
    switch (mode)
    {
        case TITLE_MODE:
            compare_res = strcmp(movie.title, keyword);
            break;
        case AUTHOR_MODE:
            compare_res = strcmp(movie.name, keyword);
            break;
        case YEAR_MODE:
            if (movie.year == year)
                compare_res = 0;
            else
                compare_res = movie.year > year ? 1 : -1;
            break;
    }
    return compare_res;
}