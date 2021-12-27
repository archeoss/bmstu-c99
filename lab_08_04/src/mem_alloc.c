#include "mem_alloc.h"

long long **alloc_matrix(long long n, long long m)
{
    long long **ptrs, *matrix;
    ptrs = calloc(n, sizeof(long long *));
    if (ptrs)
        matrix = calloc(n * m, sizeof(long long));
    if (!matrix)
    {
        free(ptrs);
        ptrs = NULL;
    }
    else
        for (long long i = 0; i < n; i++)
            ptrs[i] = matrix + i * m;

    return ptrs;
}

void delete_matr(long long **matrix)
{
    if (matrix)
    {
        if (matrix[0])
            free(matrix[0]);
        free(matrix);
    }
}

long long **realloc_cst(long long **matrix, long long rows, long long cols, long long new_rows, long long new_cols)
{
    long long **matrix_res = alloc_matrix(new_rows, new_cols);
    if (matrix_res)
    {
        for (long long i = 0; i < rows; i++)
            for (long long j = 0; j < cols; j++)
                matrix_res[i][j] = matrix[i][j];
    }
    delete_matr(matrix);

    return matrix_res;
}