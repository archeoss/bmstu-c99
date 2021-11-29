#include "check_list_operations.h"

//
// get_count() test
//

START_TEST(correct_getcount)
{
    node_t *head = NULL;
    read_items("./unit_tests/tests/test_01.txt", &head);
    ck_assert_int_eq(get_count(head), 11);
    while (head)
    {
        node_t *tmp = head;
        head = head->next;
        free(((data_t *)tmp->data)->name);
        free(tmp->data);
        free(tmp);
    }
}
END_TEST

START_TEST(corrupted_getcount)
{
    node_t *head = NULL;
    read_items("./unit_tests/tests/test_02.txt", &head);
    ck_assert_int_eq(get_count(head), 0);
    while (head)
    {
        node_t *tmp = head;
        head = head->next;
        free(((data_t *)tmp->data)->name);
        free(tmp->data);
        free(tmp);
    }
}
END_TEST

Suite *list_oper_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("Operations");

    tc = tcase_create("Core_m");

    tcase_add_test(tc, correct_getcount);
    tcase_add_test(tc, corrupted_getcount);
    
    suite_add_tcase(s, tc);
    return s;
}
