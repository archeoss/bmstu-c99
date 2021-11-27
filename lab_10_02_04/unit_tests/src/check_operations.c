#include "check_operations.h"

//
// make_simple() test
//

START_TEST(negative_simple)
{
    node_t *head = NULL;
    node_t *head_s = make_simple(-10);
    ck_assert_ptr_eq(head_s, head);
}
END_TEST

START_TEST(zero_simple)
{
    node_t *head = NULL;
    node_t *head_s = make_simple(0);
    ck_assert_ptr_eq(head_s, head);
}
END_TEST

START_TEST(one_simple)
{
    node_t *head = NULL;
    node_t *head_s = make_simple(1);
    ck_assert_ptr_eq(head_s, head);
}
END_TEST

START_TEST(correct_simple)
{
    node_t *head = make_simple(4);
    if (head && ((data_t *)head->data)->number == 2 && ((data_t *)head->data)->power == 2 && head->next == NULL)
        ck_assert_int_eq(1, 1);
    clear_list(head);
}
END_TEST

//
// simple_sqr() test
//

START_TEST(simple_sqr_check)
{
    node_t *head = NULL, *cur_node = NULL;
    alloc_node(&head, &cur_node);
    ((data_t *)cur_node->data)->number = 2;
    ((data_t *)cur_node->data)->power = 3;
    simple_sqr(head);
    if (((data_t *)cur_node->data)->number == 2 && ((data_t *)cur_node->data)->power == 3)
        ck_assert_int_eq(1, 1);
    clear_list(head);
}
END_TEST

//
// simple_mul() test
//

START_TEST(simple_mul_check)
{
    node_t *head_a = NULL, *cur_node_a = NULL;
    node_t *head_b = NULL, *cur_node_b = NULL;
    alloc_node(&head_a, &cur_node_a);
    alloc_node(&head_b, &cur_node_b);
    ((data_t *)cur_node_a->data)->number = 2;
    ((data_t *)cur_node_a->data)->power = 3;
    ((data_t *)cur_node_a->data)->number = 2;
    ((data_t *)cur_node_a->data)->power = 4;
    node_t *result = simple_mul(&head_a, &head_b, compare_numbers);
    if (((data_t *)result->data)->number == 2 && ((data_t *)result->data)->power == 7)
        ck_assert_int_eq(1, 1);
    clear_list(result);
}
END_TEST

Suite *oper_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Operations");

    tc = tcase_create("Core_m");

    tcase_add_test(tc, correct_simple);
    tcase_add_test(tc, negative_simple);
    tcase_add_test(tc, zero_simple);
    tcase_add_test(tc, one_simple);

    tcase_add_test(tc, simple_mul_check);
    tcase_add_test(tc, simple_sqr_check);

    suite_add_tcase(s, tc);
    return s;
}
