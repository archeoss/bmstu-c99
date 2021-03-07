#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
uint32_t sdv(uint32_t x, int n)
{
	x = (x << n) | (x >> (32 - n));
	return x;
}
int main()
{
	int error_code, rc;
	uint32_t a;
	int n;
	char bit1[33];
	printf("Input a and n:\n");
	rc = scanf("%u%d", &a, &n); 
	if (rc == 2)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{
		if (n < 0)
		{
			printf("Error: Negative Inputs");
			error_code = 2;
		}
		else
		{	
			a = sdv(a, n);
			int k = 0;
			while (a > 0)
			{	
				bit1[31 - k] = a % 2 + '0';
				a = a / 2;
				k++;
			}
			printf("\n");
			while (k < 33)
			{
				bit1[31 - k] = 0 + '0';
				k++;
			}
			bit1[32] = '\0';

			printf("Result: %s", bit1);
		}
	}
	else
		printf("Error: Wrong type of inputs");
	return error_code;
} 