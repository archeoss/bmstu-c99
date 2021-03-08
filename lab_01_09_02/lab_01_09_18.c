#include <stdio.h>
#include <math.h>
int mult(double *sum)
{
	int n = 0, rc,error_code;
	double x;
	rc = scanf("%lf", &x);
	if (rc != 1)
		error_code = 1;
	else if (x < 0)
		error_code = 2;
	if (error_code == 0)
	{
		while (x >= 0 && rc == 1)
		{
			n += 1;
			*sum += sqrt(n + x);
			rc = scanf("%lf", &x);
		}
	if (rc == 1)
	{
		error_code = 0;
		*sum /= n;
	}
	else
		error_code = 3;
	}
	return error_code;
}
int main()
{
	double sum = 0;
	int error_code;
	error_code = mult(&sum);
	if (error_code == 0)
	{
		printf("%.6lf", sum);
	}
	else
		printf("Input Error");
	return error_code;
}