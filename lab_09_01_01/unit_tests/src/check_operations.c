#include "check_operations.h"

//
// check_key() test
//

START_TEST(title_check)
{
    ck_assert_int_eq(check_key("title"), TITLE_MODE);
}
END_TEST

START_TEST(year_check)
{
    ck_assert_int_eq(check_key("year"), YEAR_MODE);
}
END_TEST

START_TEST(name_check)
{
    ck_assert_int_eq(check_key("name"), AUTHOR_MODE);
}
END_TEST

START_TEST(nomode_check)
{
    ck_assert_int_eq(check_key("games"), NO_MODE);
}
END_TEST

//
// get_count() test
//

START_TEST(correct_getcount)
{
    FILE *f = fopen("./unit_tests/tests/test_01.txt", "r");
    if (f)
        ck_assert_int_eq(get_count(f), 3);
    fclose(f);
}
END_TEST

START_TEST(corrupted_getcount)
{
    FILE *f = fopen("./unit_tests/tests/test_02.txt", "r");
    if (f)
        ck_assert_int_eq(get_count(f), INCORRECT_DATAFILE);
    fclose(f);
}
END_TEST

Suite *oper_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Operations");

    tc = tcase_create("Core_m");

    tcase_add_test(tc, title_check);
    tcase_add_test(tc, name_check);
    tcase_add_test(tc, year_check);
    tcase_add_test(tc, nomode_check);

    tcase_add_test(tc, correct_getcount);
    tcase_add_test(tc, corrupted_getcount);
    
    suite_add_tcase(s, tc);
    return s;
}
