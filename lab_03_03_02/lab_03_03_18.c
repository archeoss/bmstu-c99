#include <stdio.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_matrix(int *, int *, int n, int m);
int print_arr(int *a, int n, int m);
int form_result(int *a, int *arr, int n, int m);
int swap(int *a, int n);
int swap_lines(int *a, int n);
int sort(int *a, int *arr, int n);

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
			error_code = form_matrix(&a[0][0], &arr[0], n, m);
			if (error_code == NO_ERRORS)
			{	
				form_result(&a[0][0], &arr[0], n, m);
				printf("Result:");
				print_arr(&a[0][0], n, m);
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

int form_matrix(int *a, int *arr, int n, int m)
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
		*arr = 1;
		arr++;
		a = a - m + N;
		i++;
	}
	return error_code;
}

int form_result(int *a, int *arr, int n, int m)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			*arr *= *a;
			a++;
		}
		arr++;
		a = a - m + N;
	}
	a = a - N * n;
	arr -= n;
	//printf("%d %d \n", *arr, *a);
	sort(a, arr, m);
	return 0;
}

int sort(int *a, int *arr, int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 1; i < n; i++)
		{
			arr++;
			a += N;
			//printf("%d %d ,", *arr, *(arr - 1));
			if (*arr < *(arr - 1))
			{
				swap(arr, 1);
				swap_lines(a, n);
			}
		}
		arr = arr - n + 1;
		a -= (n - 1) * N;
	}
	return 0;
}

int swap(int *a, int n)
{
	int *b;
	b = (a - n);
	//printf("%d %d ,", *a, *b);
	*a = *b ^ *a;
	*b = *b ^ *a;
	*a = *a ^ *b;
	//printf("%d %d \n", *a, *b);
	return 0;
}

int swap_lines(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		swap(a, N);
		a++;
	}		
	return 0;
}

