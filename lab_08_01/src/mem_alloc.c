#include "mem_alloc.h"

long long **alloc_matrix(int n, int m)
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
        for (int i = 0; i < n; i++)
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

long long **realloc_cst(long long **matrix, int rows, int cols, int new_rows, int new_cols)
{
    long long **matrix_res = alloc_matrix(new_rows, new_cols);
    if (matrix_res)
    {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                matrix_res[i][j] = matrix[i][j];
    }
    delete_matr(matrix);

    return matrix_res;
}