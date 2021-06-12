#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define N 255


#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int sort_f(FILE *f);
void sort_al(FILE *f, int n);

int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	FILE *f;
	int n;
	char *temp;
	if (keys[1][0] == 'c')
	{
		n = strtol(keys[2], &temp, 0);
		if (*temp == '\0')
		{
			f = fopen(keys[3], "wb");
			put_random_numbers(f, n);
			fclose(f);
		}
		else
			error_code = INPUT_ERROR;
	}
	else if (keys[1][0] == 'p')
	{
		f = fopen(keys[2], "rb");
		if (f == NULL)
		{		
			error_code = INPUT_ERROR;
		}
		else
			error_code = print_f(f);
		fclose(f);
	}
	else if (keys[1][0] == 's')
	{
		f = fopen(keys[2], "r+b");
		if (f == NULL)
		{		
			error_code = INPUT_ERROR;
			printf("File do not exist");
		}
		//else
			//error_code = sort_f(f);
		fclose(f);
	}
	else
		error_code = INPUT_ERROR;
	return error_code;
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

void sort_al(FILE *f, int n)
{
	int number2;
	int number1;
	int i = 0;
	while (i < n)
	{
		for (int j = 0; j < n - 1; j++)
		{
			number1 = get_number_by_pos(f, j);
			number2 = get_number_by_pos(f, j + 1);
			if (number1 < number2)
			{
				put_number_by_pos(f, j + 1, number1);
				put_number_by_pos(f, j, number2);
			}
		}
		i++;
	}
}
