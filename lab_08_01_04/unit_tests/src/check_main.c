#include <check.h>
#include <stdlib.h>
#include "check_matrix_func.h"
#include "check_mem_alloc.h"

int main()
{
    int number_failed;
    Suite *s_mf = mf_suite();
    Suite *s_mem = mem_suite();
    SRunner *sr = srunner_create(s_mf);
    srunner_add_suite(sr, s_mem);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}