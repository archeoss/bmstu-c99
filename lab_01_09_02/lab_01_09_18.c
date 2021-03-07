#include <stdio.h>
#include <math.h>
int main()
{
	int error_code, rc, k = 1;
	double x, gx;
	printf("Input x: ");
	rc = scanf("%lf\n", &x); 
	if (rc == 1)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{
		while (x > 0)
		{
			gx += sqrt(k + x);
			k ++;
			printf("Input x: ");
			rc = scanf("%lf\n", &x); 
		}
		gx = gx / n;
		printf("Result: %lf", gx);
	}
	else
		printf("Input Error");
	return error_code;
} 