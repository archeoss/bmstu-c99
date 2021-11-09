#include "operations.h"

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

int get_count(FILE *f)
{
    int rc = 3;
    int count = 0;
    movie_struct movie_temp;
    while (rc == 3)
    {
        rc = read_struct(&movie_temp, f);
        if (rc == 3)
            count++;
        else if (rc > 0)
            count = INCORRECT_DATAFILE;
        if (movie_temp.title)
            free(movie_temp.name);
        if (movie_temp.title)
            free(movie_temp.title);
    }
    
    rewind(f);

    return count;
}

void clear_array(movie_struct *movies, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(movies[i].name);
        free(movies[i].title);
    }

    free(movies);
}

int check_line(char *line)
{
    int flag = -1;
    while (*line != '\0' && flag == -1)
        if (*line != ' ' && *line != '\0' && *(line++) != '\n')
            flag = 0;
    
    return flag;
}

movie_struct *bin_search(movie_struct *movies, int n, char *keyword, int year, int mode)
{
    movie_struct *movie_res = NULL;
    int end = n;
    int start = 0;
    while (start != end)
    {
        int compare_res;
        int mid = start + (end - start) / 2;
        compare_res = compare(movies[mid], keyword, year, mode);
        if (compare_res == 0)
        {
            end = start;
            movie_res = movies + mid;
        }
        else if (compare_res > 0)
            end = mid;
        else
            start = mid + 1;
    }

    return movie_res;
}