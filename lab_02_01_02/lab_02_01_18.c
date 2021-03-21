#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_arr(int *a, int n)
{
	int rc, error_code = NO_ERRORS;
	int tmp = 0; 
	for (int i = 0; i < n; i++)
		{
			printf("a[%d] = ", i);
			rc = scanf("%d", &tmp);
			if (rc == EOF)
				break;
			if (rc == 0)
			{
				error_code = INPUT_ERROR;
				break;
			}
			a[i] = tmp;
			printf("\n");
		}
	return error_code;
}


float find_n(int *a, int n)
{
	float sr_n, negative_n = 0, negative_sum = 0;
	for (int i = 0; i < n; i++)
		if (a[i] < 0)
		{
			negative_sum += a[i];
			negative_n += 1;
		}
	if (negative_n <= 0)
		sr_n = 0;
	else
		sr_n = negative_sum / negative_n;
	return sr_n;
}

int main(void)
{
	int error_code = INPUT_ERROR, rc;
	int n;
	float sr_n;
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%d", &n);
	printf("\n");
	int a[N];
	if (rc == 1)
	{
		if (n < 1 || n > 10)
			error_code = INCORRECT_DATA;
		else
		{
			error_code = form_arr(a, n);
			if (error_code == NO_ERRORS)
			{
				sr_n = find_n(a, n);
				if (sr_n >= 0)
					error_code = INCORRECT_DATA;
				else
				{
					error_code = NO_ERRORS;
					printf("Среднее арифметичексое = %f", sr_n);
				}
			}
		}
	}
	else
		error_code = INPUT_ERROR;
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
}