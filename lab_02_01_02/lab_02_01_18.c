#include <stdio.h>
#include <string.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
float find_n(int *a, int n)
{
	float sr_n, negative_n = 0, negative_sum = 0;
	for (int i = 0; i < n; i++)
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
	int error_code = NO_ERRORS, rc;
	int n;
	float sr_n;
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%d", &n);
	printf("\n");
	int a[n];
	if (rc == 1)
	{
		for (int i = 0; i < n; i++)
		{
			printf("a[%d] = ", i);
			rc = scanf("%d", &a[i]);
			if (rc == 0)
			{
				error_code = INPUT_ERROR;
				break;
			}
			printf("\n");
		}
		sr_n = find_n(a, n);
		printf("Среднее арифметичексое = %f", sr_n);
	}
	else
		error_code = INPUT_ERROR;
	return error_code;
}