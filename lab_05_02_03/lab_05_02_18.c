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
		error_code = INCORRECT_DATA;
	if (error_code == NO_ERRORS)
		printf("%d", result);
	return error_code;
}

int process(FILE *f)
{
	float sr;
	double disp;
	int error_code;
	int result;
	error_code = find_sr(f, &sr);
	rewind(f);
	if (error_code != INCORRECT_DATA)
	{
		find_dispersion(f, sr, &disp);
		rewind(f);
		result = check_three_sigma(f, disp, sr, DISPERSION_COEF);
	}
	else
		result = INCORRECT_DATA;
	return result;
}
