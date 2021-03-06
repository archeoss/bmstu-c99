#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2
#define NEW_LINE -1

#define YES 1
#define NO -1
#define REPEAT 3

int main(void)
{
	int error_code = NO_ERRORS;
	int count1, count2; 
	char str1[MAX_LENGTH], str2[MAX_LENGTH];
	char *arr1[MAX_LENGTH];
	char *arr2[MAX_LENGTH];
	read_line(str1, MAX_LENGTH);
	read_line(str2, MAX_LENGTH);
	count1 = get_words(str1, arr1);
	count2 = get_words(str2, arr2);
	int rc = NO;
	int i = 0, j = 0, k = 0;
	if (count1 == 0 || count2 == 0)
	{
		error_code = INPUT_ERROR;
	}
	else
	{
		printf("Result: ");
		while (i < count1 && rc == NO)
		{			
			while (k < i && rc == NO)
			{
				rc = eql_wrds(arr1[i], arr1[k]); //Функция возвращает 1 в случае если слова равны, и -1 если нет
				k++;
			}
			if (rc == YES)
				rc = REPEAT;
			while (j < count2 && rc == NO)
			{
				rc = eql_wrds(arr1[i], arr2[j]);
				j++;				
			}
			if (rc == YES)
				printf("%s yes\n", arr1[i]);
			else if (rc == NO)
				printf("%s no\n", arr1[i]);
			i++;
			j = 0;
			rc = NO;
			k = 0;
		}
	}
	return error_code;
}
