#include <stdio.h>
float pow_e(float a, int n)
{
	float result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= a;
	}
	return result;
}
int main()
{
	int n, error_code, rc;
	float a, result;
	printf("Input a and n:\n ");
	rc = scanf("%f%d", &a, &n);
	if (rc == 2)
		error_code = 0;
	else
		error_code = 1;
	if (error_code == 0)
	{	
		if (n < 1)
		{
			error_code = 2;
			printf("Input Error");
		}
		else
		{
			result = pow_e(a, n);
			printf("Result: %f", result);
		}
	}
	else
		printf("Input Error");
	return error_code;
} 