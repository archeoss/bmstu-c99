#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

void reverse_cst(char *str);
void get_pntrs(char *a, char **pntrs);

int main(void)
{
	int	j = 0, error_code = NO_ERRORS;
	char output[MAX_LENGTH];
	char str1[MAX_LENGTH];
	char *pntrs1[MAX_LENGTH/2];
	char arr1[MAX_LENGTH/2][MAX_WORD];
	get_pntrs(&arr1[0][0], pntrs1);
	read_line(str1, MAX_LENGTH);	
	int count1 = get_words(str1, pntrs1);
	char *p_o = output;
	int i = 0;
	while (i < count1 - 1)
	{
		if ((eql_wrds(pntrs1[i], pntrs1[count1 - 1])) == -1)
		{
			strip_r(pntrs1[i], p_o + j);
			j = getlen(p_o) + 1;
			if (i < count1 - 2)
				p_o[j - 1] = ' ';
		}
		i++;
	}
	if (j == 0)
		error_code = INCORRECT_DATA;
	else
	{
		j--;
		while (p_o[j] == ' ')
		{
			p_o[j] = '\0';
			j--;
		}
	}
	reverse_cst(output);
	if (error_code == NO_ERRORS)
		printf("Result: %s\n", output);
	return error_code;
}

void reverse_cst(char *str)
{
	int len = getlen(str);
	char temp;
	for (int j = 0; j < (len - len % 2) / 2; j++)
	{
		temp = str[j];
		str[j] = str[len - j - 1];
		str[len - j - 1] = temp;
	}
}

void get_pntrs(char *a, char **pntrs)
{
	for (int i = 0; i < MAX_LENGTH/2; i++)
		pntrs[i] = a + i * MAX_WORD;
}