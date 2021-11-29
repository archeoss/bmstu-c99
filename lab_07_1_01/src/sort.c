#include "../inc/sort.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int len = pe_src - pb_src; 
    int error_code = NO_ERROR;
    if (pb_src == NULL || pb_dst == NULL || pe_src == NULL || pe_dst == NULL)
        error_code = NOT_FOUND;
    else if (len < 3)
        error_code = INCORRECT_DATA_ERROR;
    else
    {
        int max_pos, min_pos;
        max_pos = find_max(pb_src, pe_src);
        min_pos = find_min(pb_src, pe_src);
        unsigned count = (unsigned)(abs(min_pos - max_pos) - 1);
        if (count < 1)
            error_code = INCORRECT_DATA_ERROR;
        if (error_code == NO_ERROR)
        {
            *pb_dst = malloc(count * sizeof(int));
            *pe_dst = *pb_dst + count;
            pb_src += (max_pos < min_pos) ? max_pos + 1 : min_pos + 1;
            for (int i = 0; i < (int)count; i++)
            {
                **pb_dst = *pb_src;
                (*pb_dst)++;
                pb_src++;
            }
            *pb_dst -= count;
        }
    }
    
    return error_code;
}

void mysort(void *base, size_t num, size_t size, int (*compare)(const void *, const void *))
{
    if (base != NULL && size > 0 && num > 0 && compare != NULL)
    {   
        num -= 1;
        char *ptr = (char *)base;
        for (size_t i = 0; i < num; i++)
        {
            for (size_t j = 0; j < num - i; j++)
            {
                int res = (*compare)((void *) ptr, (void *) (ptr + size));
                if (res > 0)
                    swap(ptr, ptr + size, size);
                ptr += size;
            }
            ptr -= (num - i) * size;
        }
    }
}

void swap(char *ptr1, char *ptr2, size_t size)
{   
    while (size-- > 0)
    {
        char tmp = *ptr1;
        *(ptr1++) = *ptr2;
        *(ptr2++) = tmp;
    }
}

int comp(const void *i, const void *j)
{
    return (*(const int *)i) - (*(const int *)j);
}

int find_max(const int *array, const int *array_end)
{
    int max = *array, max_pos = 0;
    int i = 0;
    while (array != array_end)
    {
        if (*array > max)
        {
            max_pos = i;
            max = *(array);
        }
        i++;
        array++;
    }

    return max_pos;
}

int find_min(const int *array, const int *array_end)
{
    int min = *array, min_pos = 0;
    int i = 0;
    while (array != array_end)
    {
        if (*array < min)
        {
            min_pos = i;
            min = *(array);
        }
        i++;
        array++;
    }

    return min_pos;
}