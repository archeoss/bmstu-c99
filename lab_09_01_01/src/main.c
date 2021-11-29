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
    int mode = NO_MODE;
    if (args > 2)
        mode = check_key(keys[2]); 
    if (mode == NO_MODE)
        error_code = KEY_ERROR;
    else if (args > 2 && args < 5)
    {
        if ((f = fopen(keys[1], "r")) != NULL)
        {
            count = get_count(f);
            int count_read = 0;
            if (count > 0)
            {
                movies = malloc(count * sizeof(movie_struct));
                if (movies)
                    count_read = read_items(f, movies, mode);
                else
                    error_code = ALLOC_ERROR;
            }

            if (count_read > 0 && error_code == NO_ERROR)
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
            if (count_read)
                clear_array(movies, count_read);
        }
        else
            error_code = KEY_ERROR;
    }
    else
        error_code = KEY_ERROR;

    return error_code;
}