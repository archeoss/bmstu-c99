#include "matrix_func.h"
#include "mem_alloc.h"

long long **make_it_square(long long **matrix, long long *rows_src, long long *cols_src)
{
    int type = *rows_src < *cols_src ? DELETE_COL : DELETE_ROW;
    long long rows = *rows_src, cols = *cols_src;
    long long len = llabs(rows - cols);
    for (int k = 0; k < len; k++)
    {    
        long long max_value = matrix[0][0];
        long long max_row = 0;
        long long max_col = 0;
        long long cur_value;
        for (long long i = 0; i < cols; i++)
        {
            for (long long j = 0; j < rows; j++)
            {
                cur_value = matrix[j][i];
                if (cur_value >= max_value)
                {
                    max_value = cur_value;
                    max_row = j;
                    max_col = i;
                }
            }
        }
        if (type == DELETE_ROW)
            delete_row(matrix, rows--, cols, max_row);
        else 
            delete_col(matrix, rows, cols--, max_col);
    }
    if (len)
        matrix = realloc_cst(matrix, rows, cols, rows, cols);
    *cols_src = *rows_src < *cols_src ? *rows_src : *cols_src;
    *rows_src = *cols_src;

    return matrix;
}

void delete_row(long long **matrix, long long rows, long long cols, long long row)
{
    for (long long i = row; i < rows - 1; i++)
        for (long long j = 0; j < cols; j++)
            matrix[i][j] = matrix[i + 1][j];
}

void delete_col(long long **matrix, long long rows, long long cols, long long col)
{
    for (long long i = col; i < cols - 1; i++)
        for (long long j = 0; j < rows; j++)
            matrix[j][i] = matrix[j][i + 1];
}

long long **make_equal(long long **matrix, long long size, long long to_append)
{
    long long **matrix_res = realloc_cst(matrix, size, size, size + to_append, size + to_append);
    for (long long i = 0; i < size; i++)
    {
        long long col_sum = 0;
        for (long long j = 0; j < size; j++)
            col_sum += matrix_res[j][i];
        for (long long j = size; j < size + to_append; j++)
        {
            long long to_add = col_sum / j;
            if (col_sum % j != 0 && col_sum < 0)
                to_add -= 1;
            matrix_res[j][i] = (long long)(to_add);
            col_sum += (long long)(to_add);
        }
    }
    for (long long i = 0; i < size + to_append; i++)
    {
        long long min_row = matrix_res[i][0];
        for (long long j = 0; j < size; j++)
            if (matrix_res[i][j] < min_row)
                min_row = matrix_res[i][j];
        for (long long j = size; j < size + to_append; j++)
            matrix_res[i][j] = min_row;
    }

    return matrix_res;
}

long long **matrix_multiplication(long long **matrix_a, long long **matrix_b, long long size)
{
    long long **matrix_res = alloc_matrix(size, size);
    for (long long row = 0; row < size; row++)
        for (long long col = 0; col < size; col++)
            for (long long k = 0; k < size; k++)
                matrix_res[row][col] += matrix_a[row][k] * matrix_b[k][col];
    
    return matrix_res;
}

long long **matrix_pow(long long **matrix, long long size, long long pow_num)
{
    long long **matrix_res = alloc_matrix(size, size);
    if (matrix_res)
    {
        for (long long i = 0; i < size; i++)
            matrix_res[i][i] = 1;

        for (long long i = 0; i < pow_num; i++)
        {
            long long **matrix_tmp = matrix_multiplication(matrix_res, matrix, size);
            delete_matr(matrix_res);
            matrix_res = matrix_tmp;
        }
    }

    return matrix_res;
}

void update_size(long long *rows_a, long long *rows_b, long long *cols_a, long long *cols_b)
{
    *rows_a = *rows_a > *rows_b ? *rows_a : *rows_b;
    *cols_a = *rows_a;
    *rows_b = *rows_a;
    *cols_b = *cols_a;
}