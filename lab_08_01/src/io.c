#include "io.h"
#include "mem_alloc.h"

long long **get_matrix(int rows, int cols)
{
    long long **matrix = NULL;
    int error_code = NO_ERROR;
    if (rows < 1 || cols < 1)
        error_code = INVALID_INPUT;
    else
    {
        matrix = alloc_matrix(rows, cols);
        if (matrix)
            error_code = input_matrix(matrix, rows, cols);
        else
            error_code = ALLOC_ERROR;
        if (error_code)
        {
            delete_matr(matrix);
            matrix = NULL;
        }
    }

    return matrix;
}

int input_matrix(long long **matrix, int n, int m)
{
    int total_len = n * m;
    int i = 0;
    short rc;
    int error_code = NO_ERROR;
    while (i < total_len && (rc = scanf("%lld", *(matrix) + i)) == 1)
    {
        i++;
    }
    if (i != total_len)
        error_code = INVALID_INPUT;

    return error_code;    
}

void print_matrix(long long **matrix, int rows, int cols)
{
    //printf("\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%lld ", matrix[i][j]);
        printf("\n");
    }
}