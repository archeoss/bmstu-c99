#include "io.h"

int read_items(FILE *f, movie_struct *movies, int mode)
{
    movie_struct last_movie;
    int rc = read_struct(&last_movie, f);
    int count = 0;
    while (rc == FIELDS_COUNT)
    {
        rc = 0;
        if (count == 0)
            put(movies, &last_movie);
        else
            put_by_field(movies, &last_movie, count, mode);

        rc = read_struct(&last_movie, f);
        count++;
    }

    if (rc > 0)
        count = INCORRECT_DATAFILE;

    if (last_movie.title)
        free(last_movie.title);
    if (last_movie.name)
        free(last_movie.name);

    return count;
}

void show_all(movie_struct *movies, int n)
{
    for (int i = 0; i < n; i++)
        printf("%s%s%d\n", movies[i].title, movies[i].name, movies[i].year);
}

int print_item(movie_struct *movies, char *keyword, int n, int mode)
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
        movie_struct *movie_res = bin_search(movies, n, keyword, year, mode);
        if (movie_res)
        {
            error_code = NO_ERROR;
            printf("%s%s%d\n", movie_res->title, movie_res->name, movie_res->year);
        }
    }

    return error_code;
}

int read_struct(movie_struct *last_movie, FILE *f)
{
    int rc = 0;
    char junk[JUNK_LEN];
    last_movie->name = last_movie->title = NULL;
    size_t title_size = 0, name_size = 0;
    if (getline(&last_movie->title, &title_size, f) != -1)
        rc++;
    if (rc > 0)
        rc += check_line(last_movie->title);
    if (getline(&last_movie->name, &name_size, f) != -1)
        rc++;
    if (rc > 1)
        rc += check_line(last_movie->name);
    rc += (fscanf(f, "%d", &last_movie->year) > 0 && last_movie->year >= 0) ? 1 : 0;
    fgets(junk, JUNK_LEN, f); // После fscanf остается лишний \n, который мешает getline

    return rc;
}

void put_by_field(movie_struct *movies, movie_struct *last_movie, int count, int mode)
{
    switch (mode)
    {
        case TITLE_MODE:
            put_by_title(movies, last_movie, count);
            break;
        case AUTHOR_MODE:
            put_by_name(movies, last_movie, count);
            break;
        case YEAR_MODE:
            put_by_year(movies, last_movie, count);
            break;
    }
}