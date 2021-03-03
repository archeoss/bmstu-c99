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
	char tmp;
	printf("Input a and n:\n ");
	if (((rc = scanf("%f%d%c", &a, &n, &tmp)) != 3 && rc != EOF) || tmp != '\n')
	{
		error_code = 1;
	}
	else
		error_code = 0;
	if (error_code == 0)
	{
		result = pow_e(a, n);
		printf("Result: %f", result);
	}
	else
		printf("Input Error");
	return error_code;
} 