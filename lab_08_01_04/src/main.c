#include "io.h"
#include "errors.h"
#include "constants.h"
#include "mem_alloc.h"
#include "matrix_func.h"

int main(void)
{
    int error_code = NO_ERROR;
    int **matrix_a = NULL, **matrix_b = NULL;
    int rows_a, rows_b, cols_a, cols_b;
    scanf("%d%d", &rows_a, &cols_a);
    matrix_a = get_matrix(rows_a, cols_a);
    if (matrix_a)
    {
        scanf("%d%d", &rows_b, &cols_b);
        matrix_b = get_matrix(rows_b, cols_b);
    }
    else
        error_code = INVALID_INPUT;
    if (!matrix_b)
    {
        error_code = INVALID_INPUT;
        delete_matr(matrix_a);
    }
    int pow_a, pow_b;
    int rc = scanf("%d%d", &pow_a, &pow_b);
    if (rc != 2 || pow_a < 0 || pow_b < 0)
        error_code = INVALID_INPUT;
    if (!error_code)
    {
        matrix_a = make_it_square(matrix_a, rows_a, cols_a);
        cols_a = rows_a < cols_a ? rows_a : cols_a;
        rows_a = cols_a;
        matrix_b = make_it_square(matrix_b, rows_b, cols_b);
        cols_b = rows_b < cols_b ? rows_b : cols_b;
        rows_b = cols_b;
        if (!matrix_a || !matrix_b)
            error_code = ALLOC_ERROR;
        if (!error_code)
        {
            if (rows_a < rows_b)
            {
                matrix_a = make_equal(matrix_a, rows_a, rows_b - rows_a);
                rows_a = cols_a = rows_b;
            }
            else if (rows_a > rows_b)
            {
                matrix_b = make_equal(matrix_b, rows_b, rows_a - rows_b);
                rows_b = cols_b = rows_a;
            }
            int **matrix_b_pow = matrix_pow(matrix_b, rows_b, pow_b);
            int **matrix_a_pow = matrix_pow(matrix_a, rows_a, pow_a);
            if (matrix_a_pow && matrix_b_pow)
            {
                int **matrix_res = matrix_multiplication(matrix_a_pow, matrix_b_pow, rows_a);
                print_matrix(matrix_res, rows_a, rows_a); 
                delete_matr(matrix_res);
            }
            delete_matr(matrix_b_pow);
            delete_matr(matrix_a_pow);
        }
        delete_matr(matrix_b);
        delete_matr(matrix_a);
    }

    return error_code;
}
