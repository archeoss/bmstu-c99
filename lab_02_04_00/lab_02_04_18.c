#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2
#define OVERFLOW 100

int form_arr(int *);
int bubble_sort(int *, int);

int main(void)
{
	int error_code = NO_ERRORS, cnt;
	setbuf(stdout, NULL);
	int arr_input[N];
	cnt = form_arr(arr_input);
	if (cnt != 0)
	{
		bubble_sort(arr_input, cnt);
		if (cnt == 11)
		{
			error_code = OVERFLOW;
			cnt = 10;
		}
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

int form_arr(int *a)
{
	int i = 0, rc = 1, cnt = 0;
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
			cnt++;
		}
	}
	return cnt;
}

int bubble_sort(int *a, int n)
{	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j + 1] ^ a[j];
			}
		}
	}
	return 0;
}