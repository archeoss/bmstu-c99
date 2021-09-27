#include <check.h>
#include "inc/check_readme.h"
#include "../inc/readme.h"

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
    FILE* f = fopen("./unit_tests/neg_test_01.txt", "r");
    ck_assert_int_eq(fcount(f), 0);
    fclose(f);
}
END_TEST

START_TEST (words_file_fcount)
{
    FILE* f = fopen("./unit_tests/neg_test_03.txt", "r");
    ck_assert_int_eq(fcount(f), 0);
    fclose(f);
}
END_TEST

START_TEST (correct_file_fcount)
{
    FILE* f = fopen("./unit_tests/pos_test_01.txt", "r");
    ck_assert_int_eq(fcount(f), 9);
    fclose(f);
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
    FILE *f = fopen("./unit_tests/pos_test_01.txt", "r");
    ck_assert_int_eq(!read_file(f, a, b), 0);
    fclose(f);
}
END_TEST

START_TEST (empty_file_read_file)
{
    FILE* f = fopen("./unit_tests/neg_test_01.txt", "r");
    int *a = 0;
    int *b = a + 1;
    ck_assert_int_eq(!read_file(f, a, b), 0);
    fclose(f);
}
END_TEST

START_TEST (words_file_read_file)
{
    FILE* f = fopen("./unit_tests/neg_test_03.txt", "r");
    int *a = malloc(4 * sizeof(int));
    int *b = a + 4;
    ck_assert_int_eq(!read_file(f, a, b), 0);
    fclose(f);
    free(a);
}
END_TEST

START_TEST (correct_file_read_file)
{
    FILE* f = fopen("./unit_tests/pos_test_01.txt", "r");
    int *a = malloc(9 * sizeof(int));
    int *b = a + 9;
    ck_assert_int_eq(read_file(f, a, b), 0);
    fclose(f);
    free(a);
}
END_TEST

START_TEST (bigger_len_read_file)
{
    FILE* f = fopen("./unit_tests/pos_test_01.txt", "r");
    int *a = malloc(10 * sizeof(int));
    int *b = a + 10;
    ck_assert_int_eq(!read_file(f, a, b), 0);
    fclose(f);
    free(a);
}
END_TEST

START_TEST (smaller_len_read_file)
{
    FILE* f = fopen("./unit_tests/pos_test_01.txt", "r");
    int *a = malloc(8 * sizeof(int));
    int *b = a + 8;
    ck_assert_int_eq(!read_file(f, a, b), 0);
    fclose(f);
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
    FILE *f = fopen("./unit_tests/test.txt", "w");
    ck_assert_int_eq(!write_arr(f, a, b), 0);
    fclose(f);
}
END_TEST

START_TEST (correct_file_write_arr)
{
    FILE* f = fopen("./unit_tests/test.txt", "w");
    int *a = calloc(9, sizeof(int));
    int *b = a + 9;
    ck_assert_int_eq(write_arr(f, a, b), 0);
    fclose(f);
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
    tcase_add_test(tc, words_file_read_file);
    tcase_add_test(tc, correct_file_read_file);
    tcase_add_test(tc, bigger_len_read_file);
    tcase_add_test(tc, smaller_len_read_file);

    tcase_add_test(tc, null_file_write_arr);
    tcase_add_test(tc, null_pointer_write_arr);
    tcase_add_test(tc, correct_file_write_arr);

    suite_add_tcase(s, tc);
    return s;
}
