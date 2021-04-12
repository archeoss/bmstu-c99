#include <stdio.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int *, int n, int m);
int print_arr(int *a, int n, int m);
int form_result(int *a, int *arr, int n, int m);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	rc = scanf("%d%d", &n, &m);
	int arr[N];
	if (rc == 2)
	{
		if (n < 11 && n > 0 && m < 11 && m > 0)
		{
			error_code = form_matrix(&a[0][0], n, m);
			if (error_code == NO_ERRORS)
			{	
				form_result(&a[0][0], &arr[0], n, m);
				printf("Result:");
				print_arr(&arr[0], 1, m);
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
	printf("\n");
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
	return error_code;
}

int form_result(int *a, int *arr, int n, int m)
{
	int line[N];
	if (n == 1)
		for (int i = 0; i < m; i++)
		{
			*arr = 0;
			line[i] = *a;
			a++;
			arr++;
		}
	else
		for (int i = 0; i < m; i++)
		{
			*arr = 1;
			line[i] = *a;
			a++;
			arr++;
		}
	arr -= m;
	a = a - m + N;
	for (int j = 1; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if ((*a) * (line[i]) >= 0)
				*arr = 0;
			line[i] = *a;
			a++;
			arr++;
		}
		arr -= m;
		a = a - m + N;
	}
	return 0;
}
