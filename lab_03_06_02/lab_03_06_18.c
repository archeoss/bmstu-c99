#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

void form_matrix(int **, int n, int m);
void print_arr(int **a, int n, int m);
void get_pntrs(int *, int **);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	int *pntrs[N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 1 || n > N || m > N || m < 1)
			error_code = INCORRECT_DATA;
		else
		{
			get_pntrs(&a[0][0], pntrs);
			form_matrix(pntrs, n, m);
			print_arr(pntrs, n, m);
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

void form_matrix(int **a, int n, int m)
{
	int number = n * (m + 1), one = 1; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (j % 2 == 0)
				number -= 2 * n; 
			a[i][j] = number + (1 - j % 2) + i * one;
			one *= -1;
		}
		number = n * (m + 1);
		one = 1;
	}
}


