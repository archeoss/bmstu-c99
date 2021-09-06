#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readme.h"
#include "showme.h"

#define NO_ERROR 0
#define KEY_ERROR 1
#define INCORRECT_DATA_ERROR 2
#define NOT_FOUND 3

#define STRUCT_COUNT 15

int main(int args, char **keys)
{
    int error_code = NO_ERROR;
    movie_struct movies[STRUCT_COUNT];
    FILE *f;
    int count;
    int mode = check_key(keys[2]); //readme.c
    if (mode == NO_MODE)
        error_code = KEY_ERROR;
    else if (args > 2 && args < 5)
    {
        if ((f = fopen(keys[1], "r")) != NULL)
        {
            count = read_items(f, movies, mode);
            if (count != 0)
            {
                if (args == 3)
                    show_all(movies, count);
                else if (args == 4 && find_item(movies, keys[3], count, mode) == NOT_FOUND)
                    printf("Not found");
            }
            else
                error_code = INCORRECT_DATA_ERROR;
            fclose(f);
        }
        else
            error_code = KEY_ERROR;
    }
    else
        error_code = KEY_ERROR;
    return error_code;
}