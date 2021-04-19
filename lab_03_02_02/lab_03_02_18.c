#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int *, int n, int m);
int print_arr(int *a, int n, int m);
int form_result(int *a, int *, int n, int m);
int nechet_sum(int a);
int move_lines(int *a, int m);
int move(int *a, int n);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc, expand = 0;
	int a[2 * N][N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 11 && n > 0 && m < 11 && m > 0)
		{
			error_code = form_matrix(&a[0][0], n, m);
			if (error_code == NO_ERRORS)
			{	
				error_code = form_result(&a[0][0], &expand, n, m);
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
	{
		printf("\n");
		print_arr(a[0], n + expand, m);
	}
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
	while (rc == 1 && i < n && rc != EOF)
	{	
		j = 0;
		while (rc == 1 && j < m && rc != EOF)
		{
			rc = scanf("%d", a);
			a++;
			j++;
			if (rc == 0 || rc == EOF)
				error_code = INPUT_ERROR;
		}
		a = a - m + N;
		i++;
	}
	
	printf("\n");
	return error_code;
}

int form_result(int *a, int *expand, int n, int m)
{
	int cnt = 0, error_code = INCORRECT_DATA;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nechet_sum(abs(*a)) == 1)
				cnt++;
			a++;
		}
		a = a - m;
		if (cnt > 1)
		{
			error_code = NO_ERRORS;
			for (int k = n; k > i; k--)
			{
				move_lines(a + N * (k - i), m);
			}
			for (int i = 0; i < m; i++)
			{
				*a = -1;
				a++;
			}
			(*expand)++;
			a = a - m + N;
		}
		cnt = 0;
		a += N;
	}
	return error_code;	
}

int nechet_sum(int a)
{
	int tmp, result = 0;
	tmp = abs(a);		
	while (tmp > 0)
	{
		result += tmp % 10;
		tmp = tmp / 10;
	}
	result = result % 2;
	return result;
}

int move(int *a, int n)
{
	int *b;
	b = (a - n);
	*a = *b;
	return 0;
}

int move_lines(int *a, int m)
{
	for (int i = 0; i < m; i++)
	{
		move(a, N);
		a++;
	}		
	return 0;
}