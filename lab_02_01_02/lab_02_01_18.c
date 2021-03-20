#include <stdio.h>
#include <stdlib.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1

float find_n(int *a, unsigned int n)
{
	float sr_n, negative_n = 0, negative_sum = 0;
	for (unsigned int i = 0; i < n; i++)
		if (a[i] < 0)
		{
			negative_sum += a[i];
			negative_n += 1;
		}
	sr_n = negative_sum / negative_n;
	return sr_n;
}
int main(void)
{
	int error_code = INPUT_ERROR, rc;
	unsigned int n;
	float sr_n;
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%u", &n);
	printf("\n");
	int * a = (int*)malloc(n * sizeof(int));
	if (rc == 1)
	{
		int flag = 1;
		for (unsigned int i = 0; i < n; i++)
		{
			printf("a[%u] = ", i);
			rc = scanf("%d", &a[i]);
			if (rc == 0)
			{
				error_code = INPUT_ERROR;
				flag = 0;
				break;
			}
			printf("\n");
		}
		if (flag == 1)
		{
			sr_n = find_n(a, n);
			printf("Среднее арифметичексое = %f", sr_n);
			error_code = NO_ERRORS;
		}
	}
	else
		error_code = INPUT_ERROR;
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	return error_code;
}