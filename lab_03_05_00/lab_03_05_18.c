#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int *, int n, int m);
int print_arr(int *a, int n, int m);
int form_result(int *a, int *result, int n, int m);
int reverse(int *a, int k);
int is_simple(int x);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	int arr[N * N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 11 && n > 0 && m < 11 && m > 0)
		{
			error_code = form_matrix(&a[0][0], n, m);
			if (error_code == NO_ERRORS)
			{	
				error_code = form_result(&a[0][0], &arr[0], n, m);
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
	else
		print_arr(&a[0][0], n, m);
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

int form_result(int *a, int *arr, int n, int m)
{
	int cnt = 0, error_code = NO_ERRORS;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (is_simple(*a) == 1)
			{
				*arr = *a;
				arr++;
				cnt++;
			}
			a++;
		}
		a = a - m + N;
	}
	arr -= cnt;
	a = a - N * n;
	if (cnt == 0)
		error_code = INCORRECT_DATA;
	else
	{
		reverse(arr, cnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (is_simple(*a) == 1)
				{
					*a = *arr;
					arr++;
				}
				a++;
			}
			a = a - m + N;
		}
	}
	return error_code;
}

int is_simple(int x)
{
	int result = 1, i = 2;
	while (i < x / 2 + 1 && result == 1)
	{		
		if (x % i == 0)
			result = 0;
		i++;
	}
	return result;
}

int reverse(int *a, int k)
{
	int *b;
	b = a + k - 1;
	for (int i = 0; i < k / 2; i++)
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *b ^ *a;
		a++;
		b--;
	}
	return 0;
}