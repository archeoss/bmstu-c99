#include <stdio.h>
#include <math.h>
int ten_to_bit(int x)
{
	int result = 0;
}
int main()
{
	int error_code, rc;
	int a, n, bit;
	printf("Input a and n:\n");
	rc = scanf("%d%d", &a, &n); 
	if (rc == 2)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{
		
	}
	else
		printf("Input Error");
	return error_code;
} 