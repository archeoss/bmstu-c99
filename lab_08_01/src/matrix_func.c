#include "matrix_func.h"
#include "mem_alloc.h"

int **make_it_square(int **matrix, int rows_src, int cols_src)
{
    int type = rows_src < cols_src ? DELETE_COL : DELETE_ROW;
    int rows = rows_src, cols = cols_src;
    int len = abs(rows - cols);
    for (int k = 0; k < len; k++)
    {    
        int max_value = matrix[0][0];
        int max_row = 0;
        int max_col = 0;
        int cur_value;
        for (int i = 0; i < cols; i++)
        {
            for (int j = 0; j < rows; j++)
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

    return matrix;
}

void delete_row(int **matrix, int rows, int cols, int row)
{
    for (int i = row; i < rows - 1; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = matrix[i + 1][j];
}

void delete_col(int **matrix, int rows, int cols, int col)
{
    for (int i = col; i < cols - 1; i++)
        for (int j = 0; j < rows; j++)
            matrix[j][i] = matrix[j][i + 1];
}

int **make_equal(int **matrix, int size, int to_append)
{
    int **matrix_res = realloc_cst(matrix, size, size, size + to_append, size + to_append);
    for (int i = 0; i < size; i++)
    {
        int col_sum = 0;
        for (int j = 0; j < size; j++)
            col_sum += matrix_res[j][i];
        for (int j = size; j < size + to_append; j++)
        {
            float to_add = col_sum / j;
            if ((to_add - (int)to_add) < 0)
                to_add -= 1;
            matrix_res[j][i] = (int)(to_add);
            col_sum += (int)(to_add);
        }
    }
    for (int i = 0; i < size + to_append; i++)
    {
        int min_row = matrix_res[i][0];
        for (int j = 0; j < size; j++)
            if (matrix_res[i][j] < min_row)
                min_row = matrix_res[i][j];
        for (int j = size; j < size + to_append; j++)
            matrix_res[i][j] = min_row;
    }

    return matrix_res;
}

int **matrix_multiplication(int **matrix_a, int **matrix_b, int size)
{
    int **matrix_res = alloc_matrix(size, size);
    for (int row = 0; row < size; row++)
        for (int col = 0; col < size; col++)
            for (int k = 0; k < size; k++)
                matrix_res[row][col] += matrix_a[row][k] * matrix_b[k][col];
    
    return matrix_res;
}

int **matrix_pow(int **matrix, int size, int pow_num)
{
    int **matrix_res = alloc_matrix(size, size);
    if (matrix_res)
    {
        for (int i = 0; i < size; i++)
            matrix_res[i][i] = 1;

        for (int i = 0; i < pow_num; i++)
        {
            int **matrix_tmp = matrix_multiplication(matrix_res, matrix, size);
            delete_matr(matrix_res);
            matrix_res = matrix_tmp;
        }
    }

    return matrix_res;
}