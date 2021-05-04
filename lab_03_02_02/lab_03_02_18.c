#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int **, int n, int m);
void print_arr(int **a, int n, int m);
int form_result(int **a, int n, int m);
int nechet_sum(int a);
void move_lines(int **a, int start, int exp, int n, int m);
void get_pntrs(int *, int **);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc, expand = 0;
	int a[2 * N][N];
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
				expand = form_result(pntrs, n, m);
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
	{
		printf("\n");
		print_arr(pntrs, n + expand, m);
	}
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

int form_result(int **a, int n, int m)
{
	int cnt = 0, exp = 0, flag = 0;
	for (int i = 0; i < n + exp; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (nechet_sum(a[i][j]) == 1)
				cnt++;
		}
		if (cnt > 1 && flag == 0)
		{
			flag = 1;
			move_lines(a, i, exp, n, m);
			for (int j = 0; j < m; j++)
				a[i][j] = -1;
			exp++;
		}
		else
			flag = 0;
		cnt = 0;
	}
	return exp;
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

void move_lines(int **a, int start, int exp, int n, int m)
{
	for (int i = n + exp; i > start - 1; i--)
	{
		for (int j = 0; j < m; j++)
			a[i + 1][j] = a[i][j];
	}
}