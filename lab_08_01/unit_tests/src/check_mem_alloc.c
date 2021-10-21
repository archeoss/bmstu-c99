#include "check_mem_alloc.h"

START_TEST(realloc_check)
{
    int **matrix = alloc_matrix(2, 2);
    int **matrix_re = realloc_cst(matrix, 1, 1, 1, 1);
    ck_assert_int_eq(matrix == matrix_re, 0);

    delete_matr(matrix_re);
}
END_TEST

//
// Suite
//

Suite *mem_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Mem alloc");

    tc = tcase_create("Core_m");

    tcase_add_test(tc, realloc_check);
    
    suite_add_tcase(s, tc);
    return s;
}
