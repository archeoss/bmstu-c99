#include <stdio.h>
#include "my_string.h"
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 256
#define MAX_WORD 16
#define MONTH_COUNT 12

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2
#define FIRST_INIT -1
#define MAX_YEAR 9999
#define MIN_YEAR 1
#define CHAR_SIZE 10
int main(void)
{
	char months[][CHAR_SIZE] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int error_code = NO_ERRORS;
	int rc = NO_ERRORS;
	char str1[MAX_LENGTH + 1];
	char *arr1[MAX_LENGTH];
	error_code = read_line(str1, MAX_LENGTH + 1);
	int count1 = get_words(str1, arr1);
	int i = 0;
	int year;
	int day = 0;
	if (error_code == NO_ERRORS && count1 == 3)
	{
		lower_str(arr1[1]);
		i = get_month(arr1[1], *months, CHAR_SIZE, MONTH_COUNT);
		if (i == MONTH_COUNT)
			rc = INCORRECT_DATA;
		if (rc == NO_ERRORS)
		{
			year = get_int_date(arr1[2]);
			day = get_int_date(arr1[0]);
			rc = check_date(day, i, year, days[i]);
		}
	}
	else 
		rc = INCORRECT_DATA;
	if (error_code == NO_ERRORS)
	{	
		if (rc == NO_ERRORS)
			printf("YES");
		else
			printf("NO");
	}
	return error_code;
}
