#include <stdio.h>
#include <stdlib.h>

#define N 10
#define END 5

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int **, int n, int m);
int form_result(int **a, int n, int m);
void get_pntrs(int *, int **);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc, result = -1;
	int a[N][N];
	int *pntrs[N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 1 || n > N || m != n)
			error_code = INCORRECT_DATA;
		else
		{
			get_pntrs(&a[0][0], pntrs);
			error_code = form_matrix(pntrs, n, m);
			if (error_code == NO_ERRORS)
			{	
				result = form_result(pntrs, n, m);
				if (result == -1)
					error_code = INCORRECT_DATA;
				else
					printf("\n%d", result);
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

void get_pntrs(int *a, int **pntrs)
{
	for (int i = 0; i < N; i++)
		pntrs[i] = a + i * N;
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
	int result = -1;
	for (int i = 1; i < n; i++)
		for (int j = m - i; j < m; j++)
			if (abs(a[i][j]) % 10 == 5)
				if (result < a[i][j] || result == -1)
					result = a[i][j];
	return result;
}

