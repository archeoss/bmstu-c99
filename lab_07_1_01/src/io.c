#include "../inc/io.h"

unsigned int fcount(char *filename)
{
    int rc;
    int tmp;
    FILE *f;
    unsigned int count = 0;
    if (filename != NULL && ((f = fopen(filename, "r")) != NULL))
    {
        while ((rc = fscanf(f, "%d", &tmp)) == 1)
            count++;
        if ((rc = fscanf(f, "%d", &tmp)) != EOF)
            count = 0;
        fclose(f);
    }
    return count;
}

int read_file(char *filename, int *a, int *a_end)
{
    int error_code = NO_ERROR;
    FILE *f;
    if (filename == NULL || a == NULL || a_end == NULL || ((f = fopen(filename, "r")) == NULL))
        error_code = NOT_FOUND;
    else if (a >= a_end)
        error_code = INCORRECT_DATA_ERROR;
    if (error_code == NO_ERROR)
    {
        int rc;
        int tmp;
        while ((rc = fscanf(f, "%d", &tmp)) == 1 && a < a_end)
        {
            *(a++) = tmp;
        }
        if (rc == 1 || a != a_end || (rc = fscanf(f, "%d", &tmp)) != EOF)
            error_code = INCORRECT_DATA_ERROR;
        fclose(f);
    }

    return error_code;
}

int write_arr(char *filename, int *arr, int *arr_end)
{
    int error_code = NO_ERROR;
    int len = arr_end - arr;  
    FILE *f; 
    if (filename == NULL || arr == NULL || arr_end == NULL || ((f = fopen(filename, "w")) == NULL))
        error_code = NOT_FOUND;
    else if (len < 1)
        error_code = INCORRECT_DATA_ERROR;
    else
    {
        for (int i = 0; i < len; i++)
            fprintf(f, "%d ", *(arr++));
        fclose(f);
    }
    return error_code;
}
