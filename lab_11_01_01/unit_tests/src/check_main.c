#include <check.h>
#include <stdlib.h>
#include "check_my_string.h"

int main()
{
    int number_failed;
    Suite *s_io = my_string_s();
    SRunner *sr = srunner_create(s_io);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}