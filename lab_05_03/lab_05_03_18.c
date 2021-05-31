#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define N 255


#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int process(FILE *f);
int get_n(char *chr);
void sort_f(FILE *f);
void sort_al(FILE *f, int n);

int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	FILE *f;
	int n;
	if (args > 4)
		error_code = INPUT_ERROR;
	else
	{
		if (keys[1][0] == 'c' && keys[1][1] == '\0')
		{
			n = get_n(keys[2]);
			f = fopen(keys[3], "wb");
			put_random_numbers(f, n);
			fclose(f);
		}
		else if (keys[1][0] == 'p' && keys[1][1] == '\0')
		{
			f = fopen(keys[2], "rb");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
				printf("File do not exist");
			}
			else
				print_f(f);
			fclose(f);
		}
		else if (keys[1][0] == 's' && keys[1][1] == '\0')
		{
			f = fopen(keys[2], "r+b");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
				printf("File do not exist");
			}
			else
				sort_f(f);
			fclose(f);
		}
	}
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
}


int get_n(char *chr)
{
	int n = 0;
	while (*chr != '\0')
	{
		n = n * 10 + ((int)*chr - 48);
		chr++;
	}
	return n;
}

void sort_f(FILE *f)
{
	int n = getlen(f);
	sort_al(f, n);
}

void sort_al(FILE *f, int n)
{
	int c_number;
	int number;
	int flag = 1, i = 0;
	while (i < n && flag == 1)
	{
		flag = 0;
		c_number = get_number_by_pos(f, i);
		for (int j = i + 1; j < n; j++)
		{
			number = get_number_by_pos(f, j);
			if (c_number < number)
			{
				flag = 1;
				put_number_by_pos(f, i, number);
				put_number_by_pos(f, j, c_number);
				c_number = number;
			}
		}
		i++;
	}
}
