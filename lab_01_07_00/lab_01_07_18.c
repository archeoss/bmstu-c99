#include <stdio.h>
#include <math.h>
float func(float x, float eps)
{	
	int k = 1;
	float result = 1, temp = x;
	while (abs(temp) >= eps)
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
	float x, eps;
	float fx, sx, absolute, relative;
	printf("Input x and epsilon:\n");
	rc = scanf("%f%f", &x, &eps); 
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
			relative = absolute / fx;
			printf("F(x) = %f, S(x) = %f, Absolute = %f, Relative = %f", fx, sx, absolute, relative);
		}
	}
	else
		printf("Input Error");
	return error_code;
} 