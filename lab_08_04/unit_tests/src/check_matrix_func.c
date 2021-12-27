#include "check_matrix_func.h"
#include "io.h"
#define YES 1
#define NO 0

//
// make_it_square() check
//

int check_matrixes(long long **matrix_a, long long **matrix_b, int size)
{
    int result = YES;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (matrix_a[i][j] != matrix_b[i][j])
                result = NO;
    
    return result;
}

START_TEST(MIS_del_rows)
{
    long long **matrix = alloc_matrix(3, 2);
    matrix[0][0] = 2;
    matrix[0][1] = 5;
    matrix[1][0] = 2;
    matrix[1][1] = 5;
    matrix[2][0] = 2;
    matrix[2][1] = 8;

    long long **matrix_res = alloc_matrix(2, 2);
    matrix_res[0][0] = 2;
    matrix_res[0][1] = 5;
    matrix_res[1][0] = 2;
    matrix_res[1][1] = 5;

    long long size_a = 3, size_b = 2;
    matrix = make_it_square(matrix, &size_a, &size_b);
    ck_assert_int_eq(check_matrixes(matrix, matrix_res, 2), YES);
    delete_matr(matrix);
    delete_matr(matrix_res);
}
END_TEST

START_TEST(MIS_del_cols)
{
    long long **matrix = alloc_matrix(2, 3);
    matrix[0][0] = 2;
    matrix[0][1] = 5;
    matrix[0][2] = 2;
    matrix[1][0] = 5;
    matrix[1][1] = 2;
    matrix[1][2] = 8;

    long long **matrix_res = alloc_matrix(2, 2);
    matrix_res[0][0] = 2;
    matrix_res[0][1] = 5;
    matrix_res[1][0] = 5;
    matrix_res[1][1] = 2;

    long long size_a = 3, size_b = 2;
    matrix = make_it_square(matrix, &size_b, &size_a);
    ck_assert_int_eq(check_matrixes(matrix, matrix_res, 2), YES);
    delete_matr(matrix);
    delete_matr(matrix_res);
}
END_TEST

//
//  make_equal() test
//

START_TEST(ME_test)
{
    long long **matrix = alloc_matrix(2, 2);
    matrix[0][0] = 2;
    matrix[0][1] = 5;
    matrix[1][0] = 6;
    matrix[1][1] = 2;

    long long **matrix_res = alloc_matrix(4, 4);
    matrix_res[0][0] = 2;
    matrix_res[0][1] = 5;
    matrix_res[0][2] = 2;
    matrix_res[0][3] = 2;
    matrix_res[1][0] = 6;
    matrix_res[1][1] = 2;
    matrix_res[1][2] = 2;
    matrix_res[1][3] = 2;
    matrix_res[2][0] = 4;
    matrix_res[2][1] = 3;
    matrix_res[2][2] = 3;
    matrix_res[2][3] = 3;
    matrix_res[3][0] = 4;
    matrix_res[3][1] = 3;
    matrix_res[3][2] = 3;
    matrix_res[3][3] = 3;

    long long size_a = 2, size_b = 2;
    matrix = make_equal(matrix, size_a, size_b);
    ck_assert_int_eq(check_matrixes(matrix, matrix_res, 2), YES);
    delete_matr(matrix);
    delete_matr(matrix_res);
}
END_TEST

//
// matrix_multiplication() test
//

START_TEST(MM_test)
{
    long long **matrix_a = alloc_matrix(2, 2);
    matrix_a[0][0] = 2;
    matrix_a[0][1] = 3;
    matrix_a[1][0] = 4;
    matrix_a[1][1] = 5;
    
    long long **matrix_b = alloc_matrix(2, 2);
    matrix_b[0][0] = 5;
    matrix_b[0][1] = 3;
    matrix_b[1][0] = 4;
    matrix_b[1][1] = 2;
    
    long long **matrix_res = alloc_matrix(2, 2);
    matrix_res[0][0] = 22;
    matrix_res[0][1] = 12;
    matrix_res[1][0] = 40;
    matrix_res[1][1] = 22;
    
    long long **matrix_res_m = matrix_multiplication(matrix_a, matrix_b, 2);
    ck_assert_int_eq(check_matrixes(matrix_res, matrix_res_m, 2), YES);

    delete_matr(matrix_res);
    delete_matr(matrix_a);
    delete_matr(matrix_b);
    delete_matr(matrix_res_m);
}
END_TEST

//
// matrix_pow() test
//

START_TEST(MP_test)
{
    long long **matrix_a = alloc_matrix(2, 2);
    matrix_a[0][0] = 2;
    matrix_a[0][1] = 3;
    matrix_a[1][0] = 4;
    matrix_a[1][1] = 5;
    
    long long **matrix_res = alloc_matrix(2, 2);
    matrix_res[0][0] = 116;
    matrix_res[0][1] = 153;
    matrix_res[1][0] = 204;
    matrix_res[1][1] = 269;
    
    long long **matrix_res_m = matrix_pow(matrix_a, 2, 3);
    ck_assert_int_eq(check_matrixes(matrix_res, matrix_res_m, 2), YES);

    delete_matr(matrix_res_m);
    delete_matr(matrix_res);
    delete_matr(matrix_a);
}
END_TEST

Suite *mf_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Matrix func");

    tc = tcase_create("Core_s");

    tcase_add_test(tc, MIS_del_cols);
    tcase_add_test(tc, MIS_del_rows);

    tcase_add_test(tc, ME_test);
    tcase_add_test(tc, MM_test);
    tcase_add_test(tc, MP_test);

    suite_add_tcase(s, tc);
    return s;
}
