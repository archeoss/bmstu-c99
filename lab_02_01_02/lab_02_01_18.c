#include <stdio.h>
#include <string.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1

int main(void)
{
	int error_code = NO_ERRORS, rc;
	int N;
	float negative_sum = 0, negative_n = 0;
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%d", &N);
	printf("\n");
	int a[N];
	memset( a, 0, N*sizeof(int));
	if (rc == 1)
	{
		for (int i = 0; i < N; i++)
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
		for (int i = 0; i < N; i++)
			if (a[i] < 0)
			{
				negative_sum += a[i];
				negative_n += 1;
			}
		printf("Среднее арифметичексое = %f", negative_sum / negative_n);
	}
	else
		error_code = INPUT_ERROR;
	return error_code;
}