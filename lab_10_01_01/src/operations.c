#include "operations.h"

int check_line(char *line)
{
    int flag = -1;
    while (*line != '\0' && flag == -1)
        if (*line != ' ' && *line != '\0' && *(line++) != '\n')
            flag = 0;
    
    return flag;
}

int compare_char(const void *data_a, const void *data_b)
{
    return strcmp(((data_t *)data_a)->name, ((data_t *)data_b)->name);
}

int compare_rating(const void *data_a, const void *data_b)
{
    if (data_a == NULL && data_b == NULL)
        return 0;

    if (data_b == NULL)
        return 1;

    if (data_a == NULL)
        return -1;
    
    return ((data_t *)data_a)->rating - ((data_t *)data_b)->rating;
}

int priority_check(const void *data_a)
{
    return ((data_t *)data_a)->is_priority;
}

int check_rating(const void *data_a)
{
    return ((data_t *)data_a)->rating >= 0;
}