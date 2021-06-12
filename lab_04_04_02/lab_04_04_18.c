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

#define YEAR_LENGTH 4
void get_pntrs(char *a, char **pntrs);
int get_int_date(char *a);

int main(void)
{
	char months[][10] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int error_code = NO_ERRORS;
	int rc = -1;
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
		while (i < MONTH_COUNT && rc == -1)
		{
			if (strcmp(months[i], arr1[1]) == 0)
				rc = NO_ERRORS;
			i++;
		}
		if (i == MONTH_COUNT && rc == -1)
			rc = INCORRECT_DATA;
		i--;
		if (rc == NO_ERRORS)
		{
			if (rc == NO_ERRORS)
			{
				year = get_int_date(arr1[2]);
				day = get_int_date(arr1[0]);
				if (year > 9999 || year < 1)
				{
					rc = INCORRECT_DATA;
				}
				else
				{
					if (i == 1)
					{
						if (year % 100 == 0)
						{
							if (year % 400 == 0)
								add = 1;
						}
						else
							if (year % 4 == 0)
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

int get_int_date(char *a)
{
	int date = 0;
	int flag = 0;
	while (*a && flag == 0)
	{
		if (isdigit(*a) != 0)
		{
			date = date * 10 + ((int)(*a) - 48);
			a++;
		}
		else
		{
			date = 0;
			flag = 1;
		}
	}
	return date;
}