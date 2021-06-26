#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int main(void)
{
	char output[MAX_LENGTH];
	char str[MAX_LENGTH];
	char *pntrs[MAX_LENGTH/2];
	char arr[MAX_LENGTH/2][MAX_WORD];
	get_pntrs(&arr[0][0], pntrs);
	read_line(str, MAX_LENGTH);
	int count = get_words(str, pntrs);
	int error_code = NO_ERRORS;
	error_code = strip_me(pntrs, output, count);
	if (error_code == NO_ERRORS)
		printf("Result: %s\n", output);
	return error_code;
}
