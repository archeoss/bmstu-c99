#include "io.h"

int read_items(FILE *f, movie_struct *movie, int mode)
{
    char junk[JUNK_LEN];
    movie_struct last_movie;
    last_movie.name = last_movie.title = NULL;
    size_t title_size = 0;
    size_t name_size = 0;
    int rc = 0;
    if (getline(&last_movie.title, &title_size, f) != -1)
        rc++;
    if (rc > 0)
        rc += check_line(last_movie.title);
    if (getline(&last_movie.name, &name_size, f) != -1)
        rc++;
    if (rc > 1)
        rc += check_line(last_movie.name);
    rc += (fscanf(f, "%d", &last_movie.year) > 0 && last_movie.year >= 0) ? 1 : 0;
    fgets(junk, JUNK_LEN, f); // После fscanf остается лишний \n, который мешает getline
    int count = 0;
    while (rc == 3)
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
        last_movie.title = NULL;
        last_movie.name = NULL;
        title_size = 0;
        name_size = 0;
        if (getline(&last_movie.title, &title_size, f) != -1)
            rc++;
        if (rc > 0)
            rc += check_line(last_movie.title);
        if (getline(&last_movie.name, &name_size, f) != -1)
            rc++;
        if (rc > 1)
            rc += check_line(last_movie.name);
        rc += (fscanf(f, "%d", &last_movie.year) > 0 && last_movie.year >= 0) ? 1 : 0;
        fgets(junk, JUNK_LEN, f); //После fscanf остается лишний \n, который мешает getline
        count++;
    }

    if (rc > 0)
    {
        clear_array(movie, count);
        count = INCORRECT_DATAFILE;
    }

    if (last_movie.title)
        free(last_movie.title);
    if (last_movie.name)
        free(last_movie.name);

    return count;
}

void show_all(movie_struct *movie, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s%s%d\n", movie[i].title, movie[i].name, movie[i].year);
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
