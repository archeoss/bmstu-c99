//Ввод матрицы, её вывод, создать массив с минимумами каждого столбца матрицы
//Отсортировать массив по убыванию и вывести его(вариант 2)

#include <stdio.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_arr(int *, int n, int m);
int print_arr(int *a, int n, int m);
int get_mins(int *a, int *b, int n, int m);
int sort_me(int *a, int m);

int main(void)
{
	int error_code = NO_ERRORS, n, m, rc;
	int a[N][N];
	int minimums[N];
	rc = scanf("%d%d", &n, &m);
	if (rc == 2)
	{
		if (n < 11 && n > 0 && m < 11 && m > 0)
		{
			error_code = form_arr(&a[0][0], n, m);
			if (error_code == NO_ERRORS)
			{	
				printf("Matrix:");
				print_arr(&a[0][0], n, m); //Ввод производится построчно
				get_mins(&a[0][0], &minimums[0], n, m);
				sort_me(&minimums[0], m);
				printf("Sorted minimums of rows in matrix:");
				print_arr(&minimums[0], 1, m);
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

int form_arr(int *a, int n, int m)
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

int get_mins(int *a, int *b, int n, int m)
{
	for (int j = 0; j < m; j++)
	{	
		*b = *a;
		a++;
		b++;
	}
	b = b - m;
	a = a - m + N;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			if (*a < *b)
			{
				*b = *a;
			}
			b++;
			a++;
		}
		a = a - m + N;
		b = b - m;
	}
	return 0;
}

int sort_me(int *a, int m)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{	
			if (*a < *(a + 1))
			{
				*a = *a ^ *(a + 1);
				*(a + 1) = *a ^ *(a + 1);
				*a = *(a + 1) ^ *a;
			}
			a++;
		}
		a = a - m + 1;
	}
	return 0;
}
