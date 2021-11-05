#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "errors.h"
#include "operations.h"
#include "structures.h"
#include "defines.h"

int main(int args, char **keys)
{
    int error_code = NO_ERROR;
    movie_struct *movies = NULL;
    FILE *f;
    int count;
    int mode = check_key(keys[2]); 
    if (mode == NO_MODE)
        error_code = KEY_ERROR;
    else if (args > 2 && args < 5)
    {
        if ((f = fopen(keys[1], "r")) != NULL)
        {
            count = get_count(f);
            if (count > 0)
            {
                movies = malloc(count * sizeof(movie_struct));
                count = read_items(f, movies, mode);
            }

            if (count > 0)
            {
                if (args == 3)
                    show_all(movies, count);
                else if (args == 4)
                {
                    int res = find_item(movies, keys[3], count, mode);
                    if (res == NOT_FOUND)
                        printf("Not found");
                    else if (res == KEY_ERROR)
                        error_code = KEY_ERROR;
                }
            }
            else
                error_code = INCORRECT_DATA_ERROR;
            fclose(f);
            clear_array(movies, count);
        }
        else
            error_code = KEY_ERROR;
    }
    else
        error_code = KEY_ERROR;

    return error_code;
}