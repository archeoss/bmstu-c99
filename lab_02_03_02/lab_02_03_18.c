#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int form_arr(int *, int);
int delete_quadro(int *, int);

int main(void)
{
	int error_code = INPUT_ERROR, rc, cnt;
	int n;
	setbuf(stdout, NULL);
	printf("Введите количество: ");
	rc = scanf("%d", &n);
	printf("\n");
	int arr_input[N];
	if (rc == 1)
	{
		if (n < 1 || n > 10)
			error_code = INCORRECT_DATA;
		else
		{
			error_code = form_arr(arr_input, n);
			if (error_code == NO_ERRORS)
			{
				cnt = delete_quadro(arr_input, n);
				if (cnt != n)
					for (int i = 0; i < n - cnt; i++)
					{
						printf("%d ", arr_input[i]);
					}
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

int form_arr(int *a, int n)
{
	int rc, error_code = NO_ERRORS;
	int tmp = 0; 
	for (int i = 0; i < n; i++)
	{
		rc = scanf("%d", &tmp);
		if (rc == EOF || rc == 0)
		{
			error_code = INPUT_ERROR;
			break;
		}
		a[i] = tmp;
		printf("\n");
	}
	return error_code;
}

int delete_quadro(int *a, int n)
{	
	int cnt = 0;
	int k, i;
	while (i < n - cnt)
	{
		k = 1;
		while (k * k < a[i])
			k++;
		if (k * k == a[i]) 
		{
			for (int j = i; j < n - cnt; j++)
			{
				a[j] = a[j + 1];
			}
			cnt++;
		}
		i++;
	}
	return cnt;
}