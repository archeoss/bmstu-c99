#include "../inc/io.h"

int len_of_file(char *filename)
{
    int rc;
    int tmp;
    FILE *f;
    int count = 0;
    if (filename != NULL && ((f = fopen(filename, "r")) != NULL))
    {
        while ((rc = fscanf(f, "%d", &tmp)) == 1)
            count++;
        if ((rc = fscanf(f, "%d", &tmp)) != EOF)
            count = READ_ERR;
        fclose(f);
    }
    else
        count = READ_ERR;

    return count;
}

int read_file(char *filename, int *array, int *array_end)
{
    int error_code = NO_ERROR;
    FILE *f;
    if (filename == NULL || array == NULL || array_end == NULL || ((f = fopen(filename, "r")) == NULL))
        error_code = NOT_FOUND;
    else if (array >= array_end)
        error_code = INCORRECT_DATA_ERROR;
    if (error_code == NO_ERROR)
    {
        int rc;
        int tmp;
        while (array < array_end && (rc = fscanf(f, "%d", &tmp)) == 1)
            *(array++) = tmp;
        if (array != array_end || (rc = fscanf(f, "%d", &tmp)) != EOF)
            error_code = INCORRECT_DATA_ERROR;
        fclose(f);
    }

    return error_code;
}

int write_arr(char *filename, int *array, int *array_end)
{
    int error_code = NO_ERROR;
    int len = array_end - array;  
    FILE *f; 
    if (filename == NULL || array == NULL || array_end == NULL || ((f = fopen(filename, "w")) == NULL))
        error_code = NOT_FOUND;
    else if (len < 1)
        error_code = INCORRECT_DATA_ERROR;
    else
    {
        for (int i = 0; i < len; i++)
            fprintf(f, "%d ", *(array++));
        fclose(f);
    }

    return error_code;
}
