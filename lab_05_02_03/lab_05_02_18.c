#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define N 255

#define DISPERSION_COEF 0.9973 

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int process(FILE *f);

int main(int args, char **file)
{
	int error_code = NO_ERRORS, result = -1;
	FILE *f;
	if ((f = fopen(file[1], "r")) == NULL || args != 2)
		error_code = INPUT_ERROR;
	else
		result = process(f);
	fclose(f);
	if (result == INCORRECT_DATA)
		error_code = INCORRECT_DATA)
	if (error_code == NO_ERRORS)
		printf("%d", result);
	return error_code;
}

int process(FILE *f)
{
	float sr = find_sr(f);
	rewind(f);
	if (sr != INCORRECT_DATA)
		double disp = find_dispersion(f, sr);
	else
		result = INCORRECT_DATA;
	rewind(f);
	if (disp != INCORRECT_DATA)
		int result = check_three_sigma(f, disp, sr, DISPERSION_COEF);
	else
		result = INCORRECT_DATA;
	return result;
}