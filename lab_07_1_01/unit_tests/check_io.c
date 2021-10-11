#include <check.h>
#include "inc/check_io.h"
#include "../inc/io.h"

//
// fcount() check
//

START_TEST (null_file_fcount)
{
    ck_assert_int_eq(fcount(NULL), 0);
}
END_TEST

START_TEST (empty_file_fcount)
{
    ck_assert_int_eq(fcount("./unit_tests/neg_test_01.txt"), 0);
}
END_TEST

START_TEST (words_file_fcount)
{
    ck_assert_int_eq(fcount("./unit_tests/neg_test_03.txt"), 0);
}
END_TEST

START_TEST (correct_file_fcount)
{
    ck_assert_int_eq(fcount("./unit_tests/pos_test_01.txt"), 9);
}
END_TEST

//
// read_file() check
//

START_TEST (null_file_read_file)
{
    int *a = 0;
    int *b = a + 1;
    read_file(NULL, a, b);
}
END_TEST

START_TEST (null_pointer_read_file)
{
    int *a = NULL;
    int *b = a + 1;
    ck_assert_int_eq(!read_file("./unit_tests/pos_test_01.txt", a, b), 0);
}
END_TEST

START_TEST (eq_pointer_read_file)
{
    int *a = malloc(sizeof(int));
    int *b = a;
    ck_assert_int_eq(!read_file("./unit_tests/pos_test_01.txt", a, b), 0);
    free(a);
}
END_TEST

START_TEST (empty_file_read_file)
{
    int *a = 0;
    int *b = a + 1;
    ck_assert_int_eq(!read_file("./unit_tests/pos_test_01.txt", a, b), 0);
}
END_TEST

START_TEST (words_file_read_file)
{
    int *a = malloc(4 * sizeof(int));
    int *b = a + 4;
    ck_assert_int_eq(!read_file("./unit_tests/neg_test_03.txt", a, b), 0);
    free(a);
}
END_TEST

START_TEST (correct_file_read_file)
{
    int *a = malloc(9 * sizeof(int));
    int *b = a + 9;
    ck_assert_int_eq(read_file("./unit_tests/pos_test_01.txt", a, b), 0);
    free(a);
}
END_TEST

START_TEST (bigger_len_read_file)
{
    int *a = malloc(10 * sizeof(int));
    int *b = a + 10;
    ck_assert_int_eq(!read_file("./unit_tests/pos_test_01.txt", a, b), 0);
    free(a);
}
END_TEST

START_TEST (smaller_len_read_file)
{
    int *a = malloc(8 * sizeof(int));
    int *b = a + 8;
    ck_assert_int_eq(!read_file("./unit_tests/pos_test_01.txt", a, b), 0);
    free(a);
}
END_TEST

//
// write_arr() check
//

START_TEST (null_file_write_arr)
{
    int *a = calloc(9, sizeof(int));
    int *b = a + 9;
    ck_assert_int_eq(!write_arr(NULL, a, b), 0);
    free(a);
}
END_TEST

START_TEST (null_pointer_write_arr)
{
    int *a = NULL;
    int *b = a + 1;
    ck_assert_int_eq(!write_arr("./unit_tests/test.txt", a, b), 0);
}
END_TEST

START_TEST (eq_pointer_write_arr)
{
    int *a = malloc(sizeof(int));
    int *b = a;
    ck_assert_int_eq(!write_arr("./unit_tests/test.txt", a, b), 0);
    free(a);
}
END_TEST

START_TEST (correct_file_write_arr)
{
    int *a = calloc(9, sizeof(int));
    int *b = a + 9;
    ck_assert_int_eq(write_arr("./unit_tests/test.txt", a, b), 0);
    free(a);
}
END_TEST

//
// Suite
//

Suite * readme_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Readme");

    tc = tcase_create("Core");

    tcase_add_test(tc, empty_file_fcount);
    tcase_add_test(tc, null_file_fcount);
    tcase_add_test(tc, words_file_fcount);
    tcase_add_test(tc, correct_file_fcount);

    tcase_add_test(tc, empty_file_read_file);
    tcase_add_test(tc, null_file_read_file);
    tcase_add_test(tc, null_pointer_read_file);
    tcase_add_test(tc, eq_pointer_read_file);
    tcase_add_test(tc, words_file_read_file);
    tcase_add_test(tc, correct_file_read_file);
    tcase_add_test(tc, bigger_len_read_file);
    tcase_add_test(tc, smaller_len_read_file);

    tcase_add_test(tc, null_file_write_arr);
    tcase_add_test(tc, null_pointer_write_arr);
    tcase_add_test(tc, correct_file_write_arr);
    tcase_add_test(tc, eq_pointer_write_arr);
    suite_add_tcase(s, tc);
    return s;
}
