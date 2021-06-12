#include <stdio.h>
#include <math.h>

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

int find_sr(FILE *f, float *sr)
{
	float i = 0, sum_s = 0;
	int rc, n = 0, error_code = NO_ERRORS;
	while ((rc = fscanf(f, "%f", &i)) != EOF && rc == 1)
	{
		sum_s += i;
		n++;
	}
	if (n < 2)
		error_code = INCORRECT_DATA;
	else
		*sr = sum_s / n;
	return error_code;
}

void find_dispersion(FILE *f, float sr, double *disp)
{
	double sum_s = 0;
	float i = 0;
	int n = 0, rc;
	while ((rc = fscanf(f, "%f", &i)) != EOF && rc == 1)
	{
		sum_s += pow(sr - i, 2);
		n++;
	}
	*disp = sqrt(sum_s / n);
}

int check_three_sigma(FILE *f, double disp, float sr, double k)
{
	float n_correct = 0, n = 0;
	float i = 0;
	int result = 12, rc;
	while ((rc = fscanf(f, "%f", &i)) != EOF && rc == 1)
	{
		if (i > sr - 3 * disp && i < sr + 3 * disp)
			n_correct++;
		n++;
	}
	if (n_correct / n >= k)
		result = 1;
	else
		result = 0;
	return result;
}
