#include <stdio.h>
#include <math.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int mult(double *);

int main()
{
	double sum = 0;
	int error_code;
	error_code = mult(&sum);
	if (error_code == NO_ERRORS)
	{
		printf("%.6lf", sum);
	}
	return error_code;
}

int mult(double *sum)
{
	int n = 0, rc, err_code;
	double x;
	rc = scanf("%lf", &x);
	if (rc != 1)
		err_code = INPUT_ERROR;
	else if (x < 0)
		err_code = INCORRECT_DATA;
	else
	{
		while (x >= 0)
		{
			n += 1;
			*sum += sqrt(n + x);
			scanf("%lf", &x);
		}
		*sum /= n;
		err_code = NO_ERRORS;
	}
	return err_code;
}