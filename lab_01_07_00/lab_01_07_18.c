#include <stdio.h>
#include <math.h>
double func(double x, double eps)
{	
	int k = 1;
	double result = 1, temp = x;
	while (temp >= eps)
	{
		result += temp;
		k += 1;
		temp = temp * x / k;
	}
	return result;
}
int main()
{
	int error_code, rc;
	double x, eps;
	double fx, sx, absolute, relative;
	printf("Input x and epsilon:\n");
	rc = scanf("%lf%lf", &x, &eps); 
	if (rc == 2)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{	
		if (eps <= 0 || eps > 1)
		{
			error_code = 2;
			printf("Input Error");
		}
		else
		{
			fx = exp(x);
			sx = func(x, eps);
			absolute = (fx - sx);
			if (absolute < 0)
				absolute = -1 * absolute;
			relative = absolute / fx;
			printf("F(x) = %lf  S(x) = %lf  Absolute = %lf  Relative = %lf", fx, sx, absolute, relative);
		}
	}
	else
		printf("Input Error");
	return error_code;
} 