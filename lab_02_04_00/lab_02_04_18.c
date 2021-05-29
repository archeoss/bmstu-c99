#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2
#define OVERFLOW 100

int form_arr(int *, int *);
void bubble_sort(int *, int);
void swap(int *a, int *b);

int main(void)
{
	int error_code = NO_ERRORS, cnt;
	setbuf(stdout, NULL);
	int arr_input[N];
	error_code = form_arr(&arr_input[0], &cnt);
	if (cnt != 0)
	{
		bubble_sort(arr_input, cnt);
		for (int i = 0; i < cnt; i++)
		{
			printf("%d ", arr_input[i]);
		}
	}
	else
		error_code = INCORRECT_DATA;
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
}

int form_arr(int *a, int *cnt)
{
	int i = 0, rc = 1, error_code = NO_ERRORS;
	*cnt = 0;
	int tmp = 0; 
	while (i < N && rc != EOF && rc != 0)
	{
		printf("a[%d] = ", i);
		rc = scanf("%d", &tmp);
		if (rc != EOF && rc != 0)
		{
			a[i] = tmp;
			printf("\n");
			i++;
			(*cnt)++;
		}
	}
	if ((rc = scanf("%d", &tmp)) == 1)
		error_code = OVERFLOW;
	return error_code;
}

void bubble_sort(int *a, int n)
{	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(a + j, a + j + 1);
		}
	}
}

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *b ^ *a;
}
