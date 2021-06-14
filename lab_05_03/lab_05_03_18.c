#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define N 255


#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	FILE *f;
	int n;
	char *temp;
	if (args < 3 || args > 4)
		error_code = INPUT_ERROR;
	else if (keys[1][0] == 'c')
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
		else
			error_code = sort_f(f);
		fclose(f);
	}
	else
		error_code = INPUT_ERROR;
	return error_code;
}

