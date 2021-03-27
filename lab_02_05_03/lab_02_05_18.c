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
	int error_code, rc, n;
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
			func(pa, pa + n);
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
	int rc, error_code = NO_ERRORS;
	int tmp = 0;
	while (pa < pe)
	{
		//printf("a[%d] = ", i);
		rc = scanf("%d", &tmp);
		if (rc == EOF)
		{
			error_code = INPUT_ERROR;
			break;
		}
		if (rc == 0)
		{
			error_code = INPUT_ERROR;
			break;
		}
		*pa = tmp;
		pa++;
		printf("\n");
	}
	return error_code;
}

int func(int *pa, int *pe)
{
	while (pa < pe - 1)
	{
		printf("%d ", (*pa) * (*(pa + 1)));
		pa++;
	}
	return 0;
}
