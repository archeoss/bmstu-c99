#include "../inc/sort.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int len = pe_src - pb_src; 
    int error_code = NO_ERROR;
    if (pb_src == NULL || pb_dst == NULL || pe_src == NULL || pe_dst == NULL)
        error_code = NOT_FOUND;
    else if (len - 2 < 1)
        error_code = INCORRECT_DATA_ERROR;
    else
    {
        *pb_dst = malloc((size_t)(len - 2) * sizeof(int));
        *pe_dst = *pb_dst + len - 2;
        int max = *pb_src;
        int min = *pb_src;
        for (int i = 0; i < len; i++)
        {
            if (*pb_src > max)
                max = *pb_src;
            else if (*pb_src < min)
                min = *pb_src;
            pb_src++;
        }
        pb_src -= len;
        int flag_max = 1, flag_min = 1;
        while (pb_src != pe_src)
        {
            if (*pb_src == max && flag_max)
                flag_max = 0;
            else if (*pb_src == min && flag_min)
                flag_min = 0;
            else
            {
                **pb_dst = *pb_src;
                (*pb_dst)++;
            }
            pb_src++;
        }
        *pb_dst -= len - 2;
    }
    return error_code;
}

void mysort(void *base, size_t num, size_t size, int (*compare) (const void *, const void *))
{
    if (base != NULL && size > 0 && num > 0 && compare != NULL)
    {   
        char *ptr = (char *)base;
        for (size_t i = 0; i < num - 1; i++)
        {
            for (size_t j = 0; j < num - 1 - i; j++)
            {
                int res = (*compare)((void *) ptr, (void *) (ptr + size));
                //printf("%d : %d :: %d\n", (int)*ptr, (int)*(ptr + size), res);
                if (res > 0)
                    swap(ptr, ptr + size, size);
                ptr += size;
            }
            ptr -= (num - 1 - i) * size;
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
