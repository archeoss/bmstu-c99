#include "check_io.h"

//
// read_items() check
//

START_TEST(correct_read_title)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    if (f)
        ck_assert_int_eq(read_items(f, movie, TITLE_MODE), 3);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST

START_TEST(correct_read_year)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    if (f)
        ck_assert_int_eq(read_items(f, movie, YEAR_MODE), 3);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST

START_TEST(correct_read_author)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    if (f)
        ck_assert_int_eq(read_items(f, movie, AUTHOR_MODE), 3);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST

//
// find_item() check
//

START_TEST(find_item_title)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    read_items(f, movie, TITLE_MODE);
    char test[] = "Titanic";
    if (f)
        ck_assert_int_eq(find_item(movie, test, 3, TITLE_MODE), 0);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST

START_TEST(find_item_year)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    read_items(f, movie, YEAR_MODE);
    char test[] = "1980";
    if (f)
        ck_assert_int_eq(find_item(movie, test, 3, YEAR_MODE), 0);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST

START_TEST(find_item_author)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    read_items(f, movie, AUTHOR_MODE);
    char test[] = "Rob Reiner";
    if (f)
        ck_assert_int_eq(find_item(movie, test, 3, AUTHOR_MODE), 0);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST

START_TEST(find_item_notfound)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    movie_struct *movie = malloc(sizeof(movie_struct) * 3);
    char test[] = "Robby";
    read_items(f, movie, AUTHOR_MODE);
    if (f)
        ck_assert_int_eq(find_item(movie, test, 3, AUTHOR_MODE), NOT_FOUND);
    clear_array(movie, 3);
    fclose(f);
}
END_TEST


Suite *io_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("IO");

    tc = tcase_create("Core_s");

    tcase_add_test(tc, correct_read_author);
    tcase_add_test(tc, correct_read_title);
    tcase_add_test(tc, correct_read_year);

    tcase_add_test(tc, find_item_author);
    tcase_add_test(tc, find_item_title);
    tcase_add_test(tc, find_item_year);
    tcase_add_test(tc, find_item_notfound);
    
    suite_add_tcase(s, tc);
    return s;
}
