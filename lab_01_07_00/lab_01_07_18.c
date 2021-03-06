#include <stdio.h>
#include <math.h>
int func(float x, float eps)
{	
	int temp = x, k = 1;
	float result = 1;
	while (abs(temp)>=eps)
		{
			result += temp;
			k += 1;
			temp = temp * x / k;
		}
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
		fx = exp(x);
		sx = func(x, eps)
		absolute = abs(fx - sx);
		relative = absolute / fx;
		printf("F(x) = %f, S(x) = %f, Absolute = %f, Relative = %f", fx, sx, absolute, relative);
	}
	else
		printf("Input Error");
	return error_code;
} 