#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

void get_pntrs(char *a, char **pntrs);

int main(void)
{
	int error_code = NO_ERRORS;
	int count1, count2; 
	char str1[MAX_LENGTH], str2[MAX_LENGTH];
	char arr1[MAX_LENGTH/2][MAX_WORD], arr2[MAX_LENGTH/2][MAX_WORD];
	char *pntrs1[MAX_LENGTH];
	char *pntrs2[MAX_LENGTH];
	get_pntrs(&arr1[0][0], pntrs1);
	get_pntrs(&arr2[0][0], pntrs2);
	read_line(str1, MAX_LENGTH);
	read_line(str2, MAX_LENGTH);
	count1 = get_words(str1, pntrs1);
	count2 = get_words(str2, pntrs2);
	int rc = -1;
	int i = 0, j = 0, k = 0;
	printf("Result: ");
	if (getlen(str1) == 0 || getlen(str1) == 0)
	{
		printf("INPUT_ERROR");
		error_code = INPUT_ERROR;
	}
	else
	{
		while (i < count1 && rc == -1)
		{			
			while (k < i && rc == -1)
			{
				rc = eql_wrds(arr1[i], arr1[k]);
				k++;
			}
			if (rc == 1)
				rc = 3;
			while(j < count2 && rc == -1)
			{
				rc = eql_wrds(arr1[i], arr2[j]);
				j++;				
			}
			if (rc == 1)
				printf("%s yes\n", arr1[i]);
			else if (rc == -1)
				printf("%s no\n", arr1[i]);
			i++;
			j = 0;
			rc = -1;
		}
	}
	return error_code;
}

void get_pntrs(char *a, char **pntrs)
{
	for (int i = 0; i < MAX_LENGTH/2; i++)
		pntrs[i] = a + i * MAX_WORD;
}