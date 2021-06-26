#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2
#define UNKOWN_KEY 53

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#include "my_string.h"

int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	FILE *f;
	FILE *f_out;
	char known_keys[3][3] = { "sb", "fb", "db" };
	if (args > 5 || args < 3)
		error_code = UNKOWN_KEY;
	else
	{
		if (args == 3 && strcmp(keys[1], known_keys[0]) == 0)
		{
			f = fopen(keys[2], "r+b");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				error_code = sort_me(f);
				if (error_code == NO_ERRORS)
					print_f(f);
				fclose(f);
			}
		}
		else if (args == 5 && strcmp(keys[1], known_keys[1]) == 0)
		{
			f = fopen(keys[2], "rb");
			f_out = fopen(keys[3], "wb");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				error_code = get_students_by_substr(f, f_out, keys[4]);
				fclose(f);
			}
			fclose(f_out);
		}
		else if (args == 3 && strcmp(keys[1], known_keys[2]) == 0)
		{
			f = fopen(keys[2], "rb");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				error_code = delete_under_avg(f, keys[2]);
				fclose(f);
			}
		}
		else
			error_code = UNKOWN_KEY;
	}
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
}
