#include "check_io.h"

//
// read_items() check
//

START_TEST(correct_read_items)
{
    node_t *head = NULL;
    ck_assert_int_eq(read_items("./unit_tests/tests/test_01.txt", &head), NO_ERROR);
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

START_TEST(incorrect_read_items)
{
    node_t *head = NULL;
    ck_assert_int_eq(read_items("./unit_tests/tests/test_02.txt", &head), INCORRECT_DATAFILE);
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

Suite *io_suite(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("IO");

    tc = tcase_create("Core_s");

    tcase_add_test(tc, correct_read_items);
    tcase_add_test(tc, incorrect_read_items);
    
    suite_add_tcase(s, tc);
    return s;
}
