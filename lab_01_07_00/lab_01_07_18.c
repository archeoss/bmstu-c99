#include <stdio.h>
#include <math.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

double func(double, double);

int main()
{
	int error_code, rc;
	double x, eps;
	double fx, sx, absolute, relative;
	printf("Input x and epsilon:\n");
	rc = scanf("%lf%lf", &x, &eps); 
	if (rc == 2)
		error_code = NO_ERRORS;
	else 
		error_code = INPUT_ERROR;
	if (error_code == NO_ERRORS)
	{	
		if (eps <= 0 || eps > 1)
		{
			error_code = INCORRECT_DATA;
			printf("Input Error");
		}
		else
		{
			fx = exp(x);
			sx = func(x, eps);
			absolute = fabs(fx - sx);
			relative = absolute / fx;
			printf("F(x) = %lf  S(x) = %lf  Absolute = %lf  Relative = %lf", fx, sx, absolute, relative);
		}
	}
	else
		printf("Input Error");
	return error_code;
} 

double func(double x, double eps)
{	
	int k = 1;
	double result = 1, temp = x;
	while (fabs(temp) >= eps)
	{
		result += temp;
		k += 1;
		temp = temp * x / k;
	}
	return result;
}