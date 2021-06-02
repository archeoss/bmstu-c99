#include <stdio.h>
#include "my_string.h"
#include <string.h>
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
	char months[][10] = {"january", "JANUARY", "february", "FEBRUARY", "march", "MARCH", "april", "APRIL", "may",
	"MAY", "june", "JUNE", "july", "JULY", "august", "AUGUST", "september",
	"SEPTEMBER", "october", "OCTOBER", "november", "NOVEMBER", "december", "DECEMBER"};
	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int error_code = NO_ERRORS;
	int count1; 
	char str1[MAX_LENGTH];
	char arr1[MAX_LENGTH/2][MAX_WORD];
	char *pntrs1[MAX_LENGTH];
	get_pntrs(&arr1[0][0], pntrs1);
	read_line(str1, MAX_LENGTH);
	count1 = get_words(str1, pntrs1);
	char *p_m1;
	char *p_m2;
	char *p_p;
	int rc = -1;
	int i = 0;
	int add = 0;
	int year;
	int day = 0;
	if (count1 != 3)
	{
		rc = INPUT_ERROR;
	}
	else
	{
		while (i < MONTH_COUNT && rc == -1)
		{
			p_m1 = months[i * 2];
			p_m2 = months[i * 2 + 1];
			p_p = pntrs1[1];
			while (*p_m1 != '\0' && rc == -1)
			{
				if (*p_m1 != *p_p && *p_m2 != *p_p)
					rc = INCORRECT_DATA;
				p_m1++;
				p_m2++;
				p_p++;
			}
			if (rc == -1 && *p_p == '\0')
				rc = NO_ERRORS;
			else
				rc = -1;
			i++;
		}
		i--;
		if (rc == NO_ERRORS)
		{
			
			if (rc == NO_ERRORS)
			{
				year = get_int_date(&arr1[2][0]);
				day =  get_int_date(&arr1[0][0]);
				if (year > 9999)
				{
					rc = INCORRECT_DATA;
				}
				else
				{
					if (i == 1)
					{
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
	if (rc == NO_ERRORS)
		printf("YES");
	else
		printf("NO");
	return error_code;
}

void get_pntrs(char *a, char **pntrs)
{
	for (int i = 0; i < MAX_LENGTH/2; i++)
		pntrs[i] = a + i * MAX_WORD;
}

int get_int_date(char *a)
{
	int date = 0;
	while (*a != '\0')
	{
		date = date * 10 + ((int)(*a) - 48);
		a++;
	}
	return date;
}