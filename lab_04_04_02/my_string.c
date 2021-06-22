#include "my_string.h"
#include <stdio.h>
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

#define ASCII_ZERO 48

int read_line(char *s, int n)
{
	int i = 0;
	int rc = 0;
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		if (i < n)
			s[i++] = ch;
	s[i] = '\0';
	if (i == n)
		rc = 1;
	return rc;
}

int get_words(char *str, char **arr)
{
	int i = 0;
	char *c;
	char sep[] = { '\t', ' ', '\0' };
	c = strtok(str, sep);
	while (c != NULL)
	{
		arr[i] = c;
		c = strtok(NULL, sep);
		i++;
	}
	return i;
}

int get_int_date(char *a)
{
	int date = 0;
	int flag = 0;
	while (*a && flag == 0)
	{
		if (isdigit(*a) != 0)
		{
			date = date * 10 + ((int)(*a) - ASCII_ZERO);
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

void lower_str(char *str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

int get_month(char *str, char *months, int char_size, int month_count)
{
	int i = 0, rc = FIRST_INIT;
	while (i < month_count && rc == FIRST_INIT)
	{
		if (strcmp(months, str) == 0)
			rc = NO_ERRORS;
		months += char_size;
		i++;
	}
	if (i == month_count && rc == FIRST_INIT)
		i++;
	i--;
	return i;
}

int check_date(int day, int month, int year, int days_in_month)
{
	int rc = NO_ERRORS;
	int add = 0;
	if (year > MAX_YEAR || year < MIN_YEAR)
	{
		rc = INCORRECT_DATA;
	}
	else
	{
		if (month == 1)
		{
			add = vis_check(year);
		}
		if (day > days_in_month + add || day < 1)
		{
			rc = INCORRECT_DATA;
		}
	}
	return rc;
}

int vis_check(int year)
{
	int add = 0;
	if (year % 100 == 0 && year % 400 == 0)
		add = 1;
	else if (year % 4 == 0 && year % 100 != 0)
		add = 1;
	return add;
}