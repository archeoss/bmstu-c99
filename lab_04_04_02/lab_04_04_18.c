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

int main(void)
{
	char months[][10] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int error_code = NO_ERRORS;
	int rc = FIRST_INIT;
	char str1[MAX_LENGTH + 1];
	char *arr1[MAX_LENGTH];
	error_code = read_line(str1, MAX_LENGTH + 1);
	int count1 = get_words(str1, arr1);
	int i = 0;
	int add = 0;
	int year;
	int day = 0;
	
	if (error_code == NO_ERRORS && count1 == 3)
	{
		char *p_m = arr1[1];
		while (*p_m)
		{
			*p_m = tolower(*p_m);
			p_m++;
		}
		while (i < MONTH_COUNT && rc == FIRST_INIT)
		{
			if (strcmp(months[i], arr1[1]) == 0)
				rc = NO_ERRORS;
			i++;
		}
		if (i == MONTH_COUNT && rc == FIRST_INIT)
			rc = INCORRECT_DATA;
		i--;
		if (rc == NO_ERRORS)
		{
			if (rc == NO_ERRORS)
			{
				year = get_int_date(arr1[2]);
				day = get_int_date(arr1[0]);
				if (year > MAX_YEAR || year < MIN_YEAR)
				{
					rc = INCORRECT_DATA;
				}
				else
				{
					if (i == 1)
					{
						if (year % 100 == 0 && year % 400 == 0)
							add = 1;
						else if (year % 4 == 0 && year % 100 != 0)
							add = 1;
					}
					if (day > days[i] + add || day < 1)
					{
						rc = INCORRECT_DATA;
					}
				}
			}
		}
		else
			rc = INCORRECT_DATA;
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
