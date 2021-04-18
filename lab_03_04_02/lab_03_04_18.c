#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int *, int n, int m);
int print_arr(int *a, int n, int m);
int form_result(int *a, int *result, int n, int m);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc, result = -1;
	int a[N][N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 11 && n > 1 && n == m)
		{
			error_code = form_matrix(&a[0][0], n, m);
			if (error_code == NO_ERRORS)
			{	
				form_result(&a[1][m - 2], &result, n, m);
				if (result == -1)
					error_code = INCORRECT_DATA;
				else
					printf("\n%d", result);
			}
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
	int error_code = NO_ERRORS, i = 0, j = 0, rc = 1;
	while (rc == 1 && i < n)
	{	
		j = 0;
		while (rc == 1 && j < m)
		{
			rc = scanf("%d", a);
			a++;
			j++;
			if (rc == 0)
				error_code = INPUT_ERROR;
		}
		a = a - m + N;
		i++;
	}
	printf("\n");
	return error_code;
}

int form_result(int *a, int *result, int n, int m)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = m - i; j < m; j++)
		{
			a++;
			if (abs(*a) % 10 == 5)
				if (*result < *a || *result == -1)
					*result = *a;
		}
		a = a - i - 1 + N;
	}
	return 0;
}

