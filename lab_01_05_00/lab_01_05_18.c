#include <stdio.h>
int pow_e(int a, int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= a;
	}
	return result;
}
int main()
{
	int n, a, result, error_code, rc;
	printf("Input a and n:\n ");
	rc = scanf("%d%d", &a, &n);
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
			printf("Result: %d", result);
		}
	}
	else
		printf("Input Error");
	return error_code;
} 