#include <stdio.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int pow_e(int, int);

int main()
{
	int n, a, result, error_code, rc;
	printf("Input a and n:\n ");
	rc = scanf("%d%d", &a, &n);
	if (rc == 2)
		error_code = NO_ERRORS;
	else
		error_code = INPUT_ERROR;
	if (error_code == NO_ERRORS)
	{	
		if (n < 1)
		{
			error_code = INCORRECT_DATA;
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

int pow_e(int a, int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= a;
	}
	return result;
}
