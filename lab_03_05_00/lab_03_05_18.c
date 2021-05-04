#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int **, int n, int m);
void print_arr(int **a, int n, int m);
int form_result(int **a, int *result, int n, int m);
void reverse(int *a, int k);
int is_simple(int x);
void get_pntrs(int *, int **);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	int arr[N * N];
	int *pntrs[N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 1 || n > N || m > N || m < 1)
			error_code = INCORRECT_DATA;
		else
		{
			get_pntrs(&a[0][0], pntrs);
			error_code = form_matrix(pntrs, n, m);
			if (error_code == NO_ERRORS)
			{	
				error_code = form_result(pntrs, &arr[0], n, m);
			}
		}
	}
	else
		error_code = INPUT_ERROR;
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	else
		print_arr(pntrs, n, m);
	return error_code;
}

void get_pntrs(int *a, int **pntrs)
{
	for (int i = 0; i < N; i++)
		pntrs[i] = a + i * N;
}

void print_arr(int **a, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int form_matrix(int **a, int n, int m)
{
	int error_code = NO_ERRORS, i = 0, j = 0, rc = 1;
	while (rc == 1 && i < n && rc != EOF)
	{	
		j = 0;
		while (rc == 1 && j < m && rc != EOF)
		{
			rc = scanf("%d", &a[i][j]);
			j++;
			if (rc == 0 || rc == EOF)
				error_code = INPUT_ERROR;
		}
		i++;
	}
	return error_code;
}

int form_result(int **a, int *arr, int n, int m)
{
	int cnt = 0, error_code = NO_ERRORS;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (is_simple(a[i][j]) == 1)
			{
				*arr = a[i][j];
				arr++;
				cnt++;
			}
		}
	}
	arr -= cnt;
	if (cnt == 0)
		error_code = INCORRECT_DATA;
	else
	{
		reverse(arr, cnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (is_simple(a[i][j]) == 1)
				{
					a[i][j] = *arr;
					arr++;
				}
			}
		}
	}
	return error_code;
}

int is_simple(int x)
{
	int result = 1, i = 2;
	if (x < 2)
		result = 0;
	while (i < x / 2 + 1 && result == 1)
	{		
		if (x % i == 0)
			result = 0;
		i++;
	}
	return result;
}

void reverse(int *a, int k)
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
}