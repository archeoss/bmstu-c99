#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

void put_random_numbers(FILE *f, int n)
{
	int number;
	for (int i = 0; i < n; i++) 
	{
		number = rand() % 1000;
		fwrite(&number, sizeof(int), 1, f);
	}
}

int getlen(FILE *f)
{
	int n;
	fseek(f, 0, SEEK_END);
	n = ((int)ftell(f)) / sizeof(int);
	fseek(f, 0, SEEK_SET);
	return n;
}

int print_f(FILE *f)
{
	int number, error_code = NO_ERRORS;
	int n = getlen(f); 
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			fread(&number, sizeof(int), 1, f);
			printf("%d ", number);
		}
	}
	else
		error_code = INCORRECT_DATA;
	return error_code;
}

int get_number_by_pos(FILE *f, int pos)
{
	int number;
	fseek(f, pos * sizeof(int), SEEK_SET);
	fread(&number, sizeof(int), 1, f);
	fseek(f, 0, SEEK_SET);
	return number;
}

void put_number_by_pos(FILE *f, int pos, int number)
{
	int pos_current = ftell(f);
	fseek(f, pos * sizeof(int), SEEK_SET);
	fwrite(&number, sizeof(int), 1, f);
	fseek(f, pos_current, SEEK_SET);
}

void sort_al(FILE *f, int n)
{
	int number2;
	int number1;
	int flag = 1, i = 0;
	while (i < n && flag == 1)
	{
		flag = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			number1 = get_number_by_pos(f, j);
			number2 = get_number_by_pos(f, j + 1);
			if (number1 > number2)
			{
				flag = 1;
				put_number_by_pos(f, j + 1, number1);
				put_number_by_pos(f, j, number2);
			}
		}
		i++;
	}
}

int sort_f(FILE *f)
{
	int n = getlen(f);
	int error_code = NO_ERRORS;
	if (n < 1)
		error_code = INCORRECT_DATA;
	else
		sort_al(f, n);
	return error_code;
}
