#include <stdio.h>
#include <math.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

#define N 10

int form_arr(int *pa, int *pe);
int func(int *pa, int *pe);

int main(void)
{
	int error_code, rc, n, minimum;
	int a[N];
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%d", &n);
	printf("\n");
	if (rc == 1)
	{
		if (n < 2)
			error_code = INCORRECT_DATA;
		else
		{
			int *pa;
			pa = &a[0];
			error_code = form_arr(pa, pa + n);
			if (error_code == NO_ERRORS)
			{
				minimum = func(pa, pa + n);
				printf("%d", minimum);
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

int form_arr(int *pa, int *pe)
{
	int rc = 1, error_code = NO_ERRORS;
	int tmp = 0;
	while (pa < pe && rc != EOF && rc != 0)
	{
		printf("a[%d] = ", i);
		rc = scanf("%d", &tmp);
		printf("\n");
		i++;
		*pa = tmp;
		pa++;
		printf("\n");
	}
	return error_code;
}

int func(int *pa, int *pe)
{
	int temp, minimum = (*pa) * (*(pa + 1));
	pa++;
	while (pa < pe - 1)
	{
		temp = (*pa) * (*(pa + 1));
		if (temp < minimum)
			minimum = temp;
		pa++;
	}
	return minimum;
}
