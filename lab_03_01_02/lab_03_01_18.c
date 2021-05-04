#include <stdio.h>

#define N 10


#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int **, int n, int m);
void print_arr(int *a, int m);
int form_result(int **a, int *arr, int n, int m);
void get_pntrs(int *, int **);


int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	rc = scanf("%d%d", &n, &m);
	int arr[N];
	int *pntrs[N];
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
				form_result(pntrs, &arr[0], n, m);
				printf("Result:");
				print_arr(&arr[0], m);
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

void print_arr(int *a, int m)
{
	printf("\n");
	for (int j = 0; j < m; j++)
	{	
		printf("%d ", a[j]);
	}
	printf("\n");
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
	int line[N];
	if (n == 1)
		for (int i = 0; i < m; i++)
		{
			*arr = 0;
			line[i] = a[0][i];
			arr++;
		}
	else
		for (int i = 0; i < m; i++)
		{
			*arr = 1;
			line[i] = a[0][i];
			arr++;
		}
	arr -= m;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] * (line[j]) >= 0)
				*arr = 0;
			line[j] = a[i][j];
			arr++;
		}
		arr -= m;
	}
	return 0;
}
