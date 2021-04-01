#include <stdio.h>
#include <stdint.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

#define LEN_4BITES 32

uint32_t sdv(uint32_t, int);
int print_num(uint32_t a);

int main()
{
	int error_code, rc;
	uint32_t a;
	int n;
	printf("Input a and n:\n");
	rc = scanf("%u%d", &a, &n); 
	if (rc == 2)
		error_code = NO_ERRORS;
	else 
		error_code = INPUT_ERROR;
	if (error_code == NO_ERRORS)
	{
		if (n < 0)
		{
			printf("Error: Negative Inputs");
			error_code = INCORRECT_DATA;
		}
		else
		{	
			a = sdv(a, n);
			printf("Result: ");
			for (int i = LEN_4BITES - 1; i >= 0; i --)
				printf("%u", (a >> i) % 2);
		}
	}
	else
		printf("Error: Wrong type of inputs");
	return error_code;
} 

int print_num(uint32_t a)
{
	int tmp;
	printf("Result: ");
	for (int i = LEN_4BITES - 1; i >= 0; i --)
	{	
		tmp = (a >> i) % 2;
		printf("%d", tmp);
	}
}

uint32_t sdv(uint32_t x, int n)
{
	return (x << n) | (x >> (LEN_4BITES - n));
}