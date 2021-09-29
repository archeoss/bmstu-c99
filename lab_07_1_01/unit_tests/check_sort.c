#include <check.h>
#include "inc/check_sort.h"
#include "../inc/sort.h"

//
// key() check
//

void fill(int *a, int n)
{
    for (int i = n; i > 0; i--)
    {
        *a = i;
        a++;
    }
}
int comp(const int *i, const int *j)
{
    return *i - *j;
}

START_TEST (null_pointer1_key)
{
    int *a = calloc(10, sizeof(int));
    int *b = a + 10;
    int *c = 0;
    int *d = c + 1;
    ck_assert_int_eq(!key(NULL, b, &c, &d), 0);
    free(a);
}
END_TEST

START_TEST (null_pointer2_key)
{
    int *a  = calloc(10, sizeof(int));
    int *b = a + 10;
    ck_assert_int_eq(!key(a, b, NULL, NULL), 0);
    free(a);
}
END_TEST

START_TEST (equal_pointer1_key)
{
    int *a = calloc(10, sizeof(int));
    int *b = a;
    int *c = 0;
    int *d = c + 1;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
}
END_TEST

START_TEST (first_arr_toosmall)
{
    int *a  = calloc(1, sizeof(int));
    int *b = a + 1;
    int *c = 0;
    int *d = c + 1;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
}

END_TEST

START_TEST (correct_arr_key)
{
    int *a = malloc(10 * sizeof(int));
    int *b = a + 10;
    fill(a, 10);
    int *c = 0;
    int *d = c + 1;
    ck_assert_int_eq(key(a, b, &c, &d), 0);
    free(a);
    free(c);
}
END_TEST

START_TEST (zero_len_key)
{
    int *a = malloc(10 * sizeof(int));
    int *b = a + 10;
    fill(a, 10);
    a[4] = 15;
    a[5] = -15;
    int *c = 0;
    int *d = c + 1;
    ck_assert_int_eq(!key(a, b, &c, &d), 0);
    free(a);
    free(c);
}
END_TEST

//
// mysort() check
//

START_TEST (null_pointer_sort)
{
    int *a  = malloc(3 * sizeof(int));
    fill(a, 3);
    mysort(NULL, 3, sizeof(int), (int(*)(const void *, const void *))comp);
    ck_assert_int_eq(a[0], 3);
    ck_assert_int_eq(a[1], 2);
    ck_assert_int_eq(a[2], 1);
    free(a);
}
END_TEST

START_TEST (wrong_len_sort)
{
    int *a  = malloc(3 * sizeof(int));
    fill(a, 3);
    mysort(a, 0, sizeof(int), (int(*)(const void *, const void *))comp);
    ck_assert_int_eq(a[0], 3);
    ck_assert_int_eq(a[1], 2);
    ck_assert_int_eq(a[2], 1);
    free(a);
}
END_TEST

START_TEST (wrong_size_sort)
{
    
    int *a  = malloc(3 * sizeof(int));
    fill(a, 3);
    mysort(a, 3, 0, (int(*)(const void *, const void *))comp);
    ck_assert_int_eq(a[0], 3);
    ck_assert_int_eq(a[1], 2);
    ck_assert_int_eq(a[2], 1);
    free(a);
}
END_TEST

START_TEST (null_comp_sort)
{
    
    int *a  = malloc(3 * sizeof(int));
    fill(a, 3);
    mysort(NULL, 3, sizeof(int), (int(*)(const void *, const void *))NULL);
    ck_assert_int_eq(a[0], 3);
    ck_assert_int_eq(a[1], 2);
    ck_assert_int_eq(a[2], 1);
    free(a);
}
END_TEST

START_TEST (correct_sort)
{
    int *a  = malloc(3 * sizeof(int));
    fill(a, 3);
    mysort(a, 3, sizeof(int), (int(*)(const void *, const void *))comp);
    ck_assert_int_eq(a[0], 1);
    ck_assert_int_eq(a[1], 2);
    ck_assert_int_eq(a[2], 3);
    free(a);
}
END_TEST

//
// swap() test
//

START_TEST (correct_swap)
{
    int a = 1;
    int b = 2;
    swap((char *)&a, (char *)&b, sizeof(int));
    ck_assert_int_eq(a, 2);
    ck_assert_int_eq(b, 1);
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
    tcase_add_test(tc, first_arr_toosmall);
    tcase_add_test(tc, correct_arr_key);
    tcase_add_test(tc, zero_len_key);

    tcase_add_test(tc, null_pointer_sort);
    tcase_add_test(tc, wrong_len_sort);
    tcase_add_test(tc, wrong_size_sort);
    tcase_add_test(tc, null_comp_sort);
    tcase_add_test(tc, correct_sort);

    tcase_add_test(tc, correct_swap);

    suite_add_tcase(s, tc);
    return s;
}
