#include "../inc/readme.h"

unsigned int fcount(FILE *f)
{
    int rc;
    int tmp;
    unsigned int count = 0;
    if (f != NULL)
    {
        while ((rc = fscanf(f, "%d", &tmp)) == 1)
            count++;
        if ((rc = fscanf(f, "%d", &tmp)) != EOF)
            count = 0;
        rewind(f);
    }
    return count;
}

int read_file(FILE *f, int *a, int *a_end)
{
    int error_code = NO_ERROR;
    if (f == NULL || a == NULL || a_end == NULL)
        error_code = NOT_FOUND;
    else if (a >= a_end)
        error_code = INCORRECT_DATA_ERROR;
    if (error_code == NO_ERROR)
    {
        int rc;
        while ((rc = fscanf(f, "%d", a)) == 1 && a++ <= a_end)
        {
        }
        if (a != a_end || (rc = fscanf(f, "%d", a++)) != EOF)
            error_code = INCORRECT_DATA_ERROR;
    }
    return error_code;
}

int write_arr(FILE *f, int *arr, int *arr_end)
{
    int error_code = NO_ERROR;
    int len = arr_end - arr;   
    if (f == NULL || arr == NULL || arr_end == NULL)
        error_code = NOT_FOUND;
    else if (len < 1)
        error_code = INCORRECT_DATA_ERROR;
    else
        for (int i = 0; i < len; i++)
            fprintf(f, "%d\n", *(arr++));
    return error_code;
}