#include "operations.h"

int check_line(char *line)
{
    int flag = -1;
    while (*line != '\0' && flag == -1)
        if (*line != ' ' && *line != '\0' && *(line++) != '\n')
            flag = 0;
    
    return flag;
}

int compare_char(const void *node_a, const void *node_b)
{
    return strcmp(((data_t *)((node_t *)node_a)->data)->name, ((data_t *)((node_t *)node_b)->data)->name);
}

int compare_rating(const void *node_a, const void *node_b)
{
    if (node_a == NULL && node_b == NULL)
        return 0;

    if (node_b == NULL)
        return 1;

    if (node_a == NULL)
        return -1;
    
    return ((data_t *)((node_t *)node_a)->data)->rating - ((data_t *)((node_t *)node_b)->data)->rating;
}

int priority_check(const void *node_a)
{
    return ((data_t *)((node_t *)node_a)->data)->is_priority;
}

int check_rating(const void *data_a)
{
    return ((data_t *)data_a)->rating >= 0;
}