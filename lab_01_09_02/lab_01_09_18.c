#include <stdio.h>
#include <math.h>
double func(double x, int k)
{
	double result = sqrt(k + x);
	return result;
}
int main()
{
	int error_code, rc, k = 1;
	double x, gx;
	printf("Input x: ");
	rc = scanf("%lf", &x);
	printf("\n");	
	if (rc == 1)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{
		while (x > 0 && rc == 1)
		{
			gx += func(x, k);
			k ++;
			printf("Input x: ");
			rc = scanf("%lf", &x);
			printf("\n");			
		}
		if (rc == 1)
		{
			gx = gx / (k - 1);
			printf("Result: %lf", gx);
		}
		else
		{
			printf("Input Error");
			error_code = 2;
		}
	}
	else
		printf("Input Error");
	return error_code;
} 