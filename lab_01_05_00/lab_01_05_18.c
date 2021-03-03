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
	int n;
	float a, result;
	printf("Input a and n:\n ");
	scanf("%f%d", &a, &n);
	result = pow_e(a, n);
	printf("Result: %f", result);
	return 0;
} 