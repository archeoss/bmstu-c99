#include "check_list_operations.h"


//
// check_line() test
//

START_TEST(correct_check_line)
{
    ck_assert_int_eq(check_line("abc"), 0);
}
END_TEST

START_TEST(incorrect_check_line)
{
    ck_assert_int_eq(check_line("\n"), -1);
}
END_TEST

//
// compare_char() test
//

START_TEST(first_cmp_char)
{
    node_t *node_a = malloc(sizeof(node_t));
    node_t *node_b = malloc(sizeof(node_t));
    data_t data_a, data_b;
    data_a.name = "a";
    data_b.name = "b";
    node_a->data = &data_a;
    node_b->data = &data_b;
    ck_assert_int_eq(compare_char(node_a, node_b), -1);
    free(node_a);
    free(node_b);
}
END_TEST

START_TEST(second_cmp_char)
{
    node_t *node_a = malloc(sizeof(node_t));
    node_t *node_b = malloc(sizeof(node_t));
    data_t data_a, data_b;
    data_a.name = "b";
    data_b.name = "a";
    node_a->data = &data_a;
    node_b->data = &data_b;
    ck_assert_int_eq(compare_char(node_a, node_b), 1);
    free(node_a);
    free(node_b);
}
END_TEST


Suite *oper_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Operations");

    tc = tcase_create("Core_m");

    tcase_add_test(tc, correct_check_line);
    tcase_add_test(tc, incorrect_check_line);

    tcase_add_test(tc, second_cmp_char);
    tcase_add_test(tc, first_cmp_char);

    suite_add_tcase(s, tc);
    return s;
}
