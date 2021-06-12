#include <stdio.h>
#include <stdlib.h>

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

int get_number_by_pos(FILE *f, long long unsigned int pos)
{
	int number;
	fseek(f, pos * sizeof(int), SEEK_SET);
	fread(&number, sizeof(int), 1, f);
	fseek(f, 0, SEEK_SET);
	return number;
}

void put_number_by_pos(FILE *f, long long unsigned int pos, int number)
{
	int pos_current = ftell(f);
	fseek(f, pos * sizeof(int), SEEK_SET);
	fwrite(&number, sizeof(int), 1, f);
	fseek(f, pos_current, SEEK_SET);
}