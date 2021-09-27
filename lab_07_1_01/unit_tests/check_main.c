#include <check.h>
#include <stdlib.h>
#include "inc/check_sort.h"
#include "inc/check_readme.h"

int main()
{
    int number_failed;
    Suite *s_readme = readme_suite();
    Suite *s_sort = sort_suite();
    SRunner *sr = srunner_create(s_readme);
    srunner_add_suite(sr, s_sort);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}