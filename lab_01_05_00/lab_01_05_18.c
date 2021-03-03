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
	char tmp;
	printf("Input a and n:\n ");
	if (((rc = scanf("%d%d", &a, &n)) != 2 && rc != EOF) || tmp != '\n')
	{
		error_code = 1;
	}
	else
		error_code = 0;
	if (error_code == 0)
	{
		result = pow_e(a, n);
		printf("Result: %d", result);
	}
	else
		printf("Input Error");
	return error_code;
} 