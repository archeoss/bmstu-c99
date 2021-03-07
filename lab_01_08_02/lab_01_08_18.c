#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int error_code, rc;
	int n, a;
	char *bit1 = malloc(33), temp[2];
	printf("Input a and n:\n");
	rc = scanf("%d%d", &a, &n); 
	if (rc == 2)
		error_code = 0;
	else 
		error_code = 1;
	if (error_code == 0)
	{
		if (n < 1 || a < 1)
		{
			printf("Input Error");
			error_code = 2;
		}
		else
		{	
			int k = 0;
			while (a > 0)
			{	
				bit1[31 - k] = a % 2 +'0';
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
			printf("%s\n", bit1);
			for (int i = 0; i < n; i++)
			{
				strncpy(temp, bit1, 1);
				temp[1] = '\0';
				for (int i = 0; i < 32; i++)
					bit1[i] = bit1[i+1];
				bit1[31] = (int)temp[0] ;
				bit1[32] = '\0';
				printf("%s\n", bit1);
			}
			printf("%s", bit1);
		}
	}
	else
		printf("Input Error");
	return error_code;
} 