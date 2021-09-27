#include <check.h>
#include "inc/check_sort.h"
#include "../inc/sort.h"

//
// key() check
//

START_TEST (null_pointer1_key)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a + 10;
    int *c = malloc(8 * sizeof(int));
    int *d = c + 8;
    ck_assert_int_eq(!key(NULL, b, &c, &d), 0);
    free(a);
    free(c);
}
END_TEST

START_TEST (null_pointer2_key)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a + 10;
    int *c = malloc(8 * sizeof(int));
    int *d = c + 8;
    ck_assert_int_eq(!key(a, b, NULL, &d), 0);
    free(a);
    free(c);
}
END_TEST

START_TEST (equal_pointer1_key)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a;
    int *c = malloc(8 * sizeof(int));
    int *d = c + 8;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
    free(c);
}
END_TEST

START_TEST (equal_pointer2_key)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a + 10;
    int *c = malloc(8 * sizeof(int));
    int *d = c;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
    free(c);
}
END_TEST

START_TEST (second_arr_toosmall)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a + 10;
    int *c = malloc(6 * sizeof(int));
    int *d = c + 6;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
    free(c);
}

START_TEST (first_arr_toosmall)
{
    int *a  = calloc(1, sizeof(int));
    int *b = a + 1;
    int *c = malloc(6 * sizeof(int));
    int *d = c + 6;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
    free(c);
}

END_TEST

START_TEST (correct_arr_key)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a + 10;
    int *c = malloc(8 * sizeof(int));
    int *d = c + 8;
    ck_assert_int_eq(key(a, b, &c, &d), 0);
    free(a);
    free(c);
}
END_TEST

//
// Suite
//

Suite * sort_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Sort");

    tc = tcase_create("Core_s");

    tcase_add_test(tc, null_pointer1_key);
    tcase_add_test(tc, null_pointer2_key);
    tcase_add_test(tc, equal_pointer1_key);
    tcase_add_test(tc, equal_pointer2_key);
    tcase_add_test(tc, first_arr_toosmall);
    tcase_add_test(tc, second_arr_toosmall);
    tcase_add_test(tc, correct_arr_key);

    suite_add_tcase(s, tc);
    return s;
}
