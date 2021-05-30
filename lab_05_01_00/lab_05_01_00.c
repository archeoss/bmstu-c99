#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#define N 255

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int process(FILE *f);

int main(void)
{
	char file_in[N];
	int error_code;
	scanf("%s", file_in);
	error_code = process(stdin);
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
}

int process(FILE *f)
{
	int error_code = NO_ERRORS;
	int max_n; 
	max_n = find_pos_after_neg(f);
	if (max_n == -1)
		error_code = INCORRECT_DATA;
	else
		printf("%d", max_n);
	return error_code;
}
