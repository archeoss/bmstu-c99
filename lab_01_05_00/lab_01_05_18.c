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
	int n, error_code, rc, a, result;
	printf("Input a and n:\n ");
	rc = scanf("%d%d", &a, &n);
	if (rc == 2)
		error_code = 0;
	else
		error_code = 1;
	if (error_code == 0)
	{
		result = pow_e(a, n);
		printf("Result: %d", result);
	}
	else
		printf("Input Error");
	return error_code;
} 