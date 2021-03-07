#include <stdio.h>
#include <math.h>
int main()
{
	int error_code, rc;
	float x;
	printf("Input x:\n");
	rc = scanf("%f", &x); 
	if (rc == 1)
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