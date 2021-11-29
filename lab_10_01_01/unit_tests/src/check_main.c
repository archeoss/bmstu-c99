#include <check.h>
#include <stdlib.h>
#include "check_io.h"
#include "check_operations.h"
#include "check_list_operations.h"

int main()
{
    int number_failed;
    Suite *s_io = io_suite();
    Suite *s_oper = oper_suite();
    Suite *ls_oper = list_oper_suite();
    SRunner *sr = srunner_create(s_io);
    srunner_add_suite(sr, s_oper);
    srunner_add_suite(sr, ls_oper);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}