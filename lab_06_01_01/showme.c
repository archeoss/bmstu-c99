#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readme.h"
#include "showme.h"

#define NO_ERROR 0
#define KEY_ERROR 1
#define INCORRECT_DATA_ERROR 2
#define NOT_FOUND 3

void show_all(Movie *movie, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s%s%d\n", movie[i].title, movie[i].author, movie[i].year);
    }
}

int find_item(Movie *movie, char *keyword, int n, int mode)
{
    int error_code = NO_ERROR;
    int year;
    if (mode == YEAR_MODE)
    {
        year = strtol(keyword, NULL, 10);
        if (year == 0)
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
            switch (mode)
            {
                case TITLE_MODE:
                    compare_res = strcmp(movie[mid].title, keyword);
                    break;
                case AUTHOR_MODE:
                    compare_res = strcmp(movie[mid].author, keyword);
                    break;
                case YEAR_MODE:
                    if (movie[mid].year == year)
                        compare_res = 0;
                    else
                        compare_res = movie[mid].year > year ? 1 : -1;
                    break;
            }
            if (compare_res == 0)
            {
                end = start;
                error_code = NO_ERROR;
                printf("%s%s%d\n", movie[mid].title, movie[mid].author, movie[mid].year);
            }
            else if (compare_res == 1)
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return error_code;
}