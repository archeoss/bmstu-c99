#include "check_my_string.h"

//
// my_snprintf() check
//

START_TEST(string_check_a)
{
    char s[] = "12345";
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, 6, "%s", s);
    int code2 = my_snprintf(res_my, 6, "%s", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(string_check_b)
{
    char s[] = "abc gh 123";
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%s", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%s", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(char_check)
{
    char s = 'g';
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%c", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%c", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(int_check)
{
    int s = 12345;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, 6, "%d", s);
    int code2 = my_snprintf(res_my, 6, "%d", s);
    //printf("%s\n^%s\n", res_my, res_std);
    
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(neg_int_check)
{
    int s = -12345;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%d", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%d", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(long_int_check)
{
    long s = 1223456789;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%ld", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%ld", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(neg_long_int_check)
{
    long s = -1223456789;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%ld", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%ld", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(oct_check)
{
    int s = 123;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%o", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%o", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(long_oct_check)
{
    long s = 123456;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%lo", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%lo", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(neg_oct_check)
{
    int s = -123;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%o", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%o", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(neg_long_oct_check)
{
    long s = -123456;
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%lo", s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%lo", s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(all_check_a)
{
    int s = 123;
    char ss[] = "qwerty";
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = snprintf(res_std, BUFSIZ, "%d %s %o", s, ss, s);
    int code2 = my_snprintf(res_my, BUFSIZ, "%d %s %o", s, ss, s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(all_check_b)
{
    int s = 123;
    char ss[] = "qwerty";
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code2 = my_snprintf(res_my, BUFSIZ, "aboba %d %s %o \nboba", s, ss, s);
    int code1 = snprintf(res_std, BUFSIZ, "aboba %d %s %o \nboba", s, ss, s);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(all_check_size)
{
    int s = 123;
    char ss[] = "qwerty";
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];
    int code1 = my_snprintf(res_my, strlen("aboba 123 qwerty boba\n") + 1, "aboba %d %s boba\n", s, ss);
    int code2 = snprintf(res_std, strlen("aboba 123 qwerty boba\n") + 1, "aboba %d %s boba\n", s, ss);
    //printf("%s\n^%s", res_my, res_std);
    ck_assert_int_eq(strcmp(res_std, res_my), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(null_buf)
{
    int size = 30;
    int number = 999;
    char format[30] = "test format %d";

    char buff1[20] = "\0";
    int code1 = my_snprintf(buff1, size, format, number);

    char buff2[20] = "\0";
    int code2 = snprintf(buff2, size, format, number);

    ck_assert_int_eq(strcmp(buff1, buff2), 0);
    ck_assert_int_eq(code1, code2);
}
END_TEST

START_TEST(count_check)
{
    int s = 123;
    char ss[] = "qwerty";
    char res_std[BUFSIZ];
    char res_my[BUFSIZ];

    ck_assert_int_eq
    (
        my_snprintf(res_my, BUFSIZ, "aboba %d %s %o \nboba", s, ss, s),
        snprintf(res_std, BUFSIZ, "aboba %d %s %o \nboba", s, ss, s)
    );
}
END_TEST

Suite *my_string_s(void)
{
    Suite *s;
    TCase *tc;

    s = suite_create("IO");

    tc = tcase_create("Core_s");

    tcase_add_test(tc, string_check_a);
    tcase_add_test(tc, string_check_b);
    
    tcase_add_test(tc, char_check);
    
    tcase_add_test(tc, int_check);
    tcase_add_test(tc, long_int_check);
    tcase_add_test(tc, neg_int_check);
    tcase_add_test(tc, neg_long_int_check);
    
    tcase_add_test(tc, oct_check);
    tcase_add_test(tc, long_oct_check);
    tcase_add_test(tc, neg_oct_check);
    tcase_add_test(tc, neg_long_oct_check);

    tcase_add_test(tc, all_check_a);
    tcase_add_test(tc, all_check_b);
    tcase_add_test(tc, all_check_size);

    tcase_add_test(tc, null_buf);

    tcase_add_test(tc, count_check);
    
    suite_add_tcase(s, tc);

    return s;
}
