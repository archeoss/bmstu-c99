#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int *, int n, int m);
int print_arr(int *a, int n, int m);
int form_result(int *a, int n, int m);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 11 && n > 0 && m < 11 && m > 0)
		{
			form_matrix(&a[0][0], n, m);
			print_arr(&a[0][0], n, m);
		}
		else
			error_code = INCORRECT_DATA;
	}
	else
		error_code = INPUT_ERROR;
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
}

int print_arr(int *a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", *a);
			a++;
		}
		printf("\n");
		a = a - m + N;
	}
	return 0;
}

int form_matrix(int *a, int n, int m)
{
	int number = n * (m + 1), one = 1; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j % 2 == 0)
				number -= 2 * n; 
			*a = number + (1 - j % 2) + i * one;
			one *= -1;
			a++;
		}
		number = n * (m + 1);
		one = 1;
		a = a - m + N;
	}
	return 0;
}


