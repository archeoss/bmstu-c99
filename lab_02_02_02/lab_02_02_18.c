#include <stdio.h>
#include <stdlib.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_arr(int *, int);
int first_equal_last(int *, int *, int);
int print_arr(int *a, int m);

int main(void)
{
	int error_code = INPUT_ERROR, rc, cnt;
	int n;
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%d", &n);
	printf("\n");
	int arr_input[N], arr_output[N];
	if (rc == 1)
	{
		if (n < 1 || n > N)
			error_code = INCORRECT_DATA;
		else
		{
			error_code = form_arr(arr_input, n);
			if (error_code == NO_ERRORS)
			{
				cnt = first_equal_last(arr_input, arr_output, n);
				if (cnt != 0)
					print_arr(&arr_output[0], cnt);
				else
					error_code = INCORRECT_DATA;
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

int print_arr(int *a, int m)
{
	printf("\n");
	for (int j = 0; j < m; j++)
	{	
		printf("%d ", *a);
		a++;
	}
	printf("\n");
	return 0;
}

int form_arr(int *a, int n)
{
	int rc = 1, i = 0, error_code = NO_ERRORS;
	int tmp = 0; 
	while (i < n && rc != EOF && rc != 0)
	{
		printf("a[%d] = ", i);
		rc = scanf("%d", &tmp);
		if (rc == EOF || rc == 0)
			error_code = INPUT_ERROR;
		else
		{
			a[i] = tmp;
			printf("\n");
			i++;
		}
	}
	return error_code;
}

int first_equal_last(int *a, int *b, int n)
{
	int first, last, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		last = abs(a[i]);
		first = last % 10;		
		while (last > 9)
			last = last / 10;
		if (first == last)
		{
			b[cnt] = a[i];
			cnt++;
		}
	}
	return cnt;
}