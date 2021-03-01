#include <stdio.h>
float pow(float a, int n)
{
	float result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= n;
	}
	return result;
}
int main()
{
	int n;
	float a;
	printf("Input a and n:\n ");
	scanf("%f%d", &a, &n);
	result = pow(a, n);
	printf("Result: %f", result);
	return 0;
} 