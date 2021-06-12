#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"

#define N 255

#define DISPERSION_COEF 0.9973 

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int process(FILE *f);
int check_n(FILE *f);

int main(int args, char **file)
{
	int error_code = NO_ERRORS, result = -1;
	FILE *f;
	if ((f = fopen(file[1], "r")) == NULL || args != 2)
		error_code = INPUT_ERROR;
	else
		error_code = check_n(f)
	if (error_code == NO_ERRORS)
		result = process(f);
	fclose(f);
	if (error_code == NO_ERRORS)
		printf("%d", result);
	return error_code;
}

int process(FILE *f)
{
	float sr = find_sr(f);
	rewind(f);
	double disp = find_dispersion(f, sr);
	rewind(f);
	int result = check_three_sigma(f, disp, sr, DISPERSION_COEF);
	return result;
}

int check_n(FILE *f)
{
	float i = 0;
	int rc, n = 0, error_code = NO_ERRORS;
	while ((rc = fscanf(f, "%f", &i)) != EOF && rc == 1 && n < 2)
		n++;
	if (n < 2)
		error_code = INCORRECT_DATA;
	return error_code;
}