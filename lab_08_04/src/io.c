#include "io.h"
#include "mem_alloc.h"

long long **get_matrix(long long rows, long long cols)
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

int input_matrix(long long **matrix, long long n, long long m)
{
    long long i = 0, j = 0;
    short rc = 1;
    int error_code = NO_ERROR;
    while (i < n && rc == 1)
    {
        j = 0;
        while (j < m && rc == 1)
            rc = scanf("%lld", *(matrix + i) + j++);
        i++;
    }
    if (i != n || j != m)
        error_code = INVALID_INPUT;

    return error_code;    
}

void print_matrix(long long **matrix, long long rows, long long cols)
{
    //printf("\n");
    for (long long i = 0; i < rows; i++)
    {
        for (long long j = 0; j < cols; j++)
            printf("%lld ", matrix[i][j]);
        printf("\n");
    }
}