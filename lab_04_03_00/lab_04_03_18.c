#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

void reverse_cst(char *str);

int main(void)
{
	int	j = 0, error_code = NO_ERRORS;
	char output[MAX_LENGTH];
	char str1[MAX_LENGTH];
	read_line(str1, MAX_LENGTH);
	char *p1 = str1;
	char *p_o = output;
	char word1[MAX_WORD];
	char *i;
	char *tmp;
	i = str1 + getlen(str1);
	while (i > p1)
	{
		tmp = get_word(p1, word1);
		if (tmp != NULL)
		{
			strip_r(word1, p_o + j);
			j = getlen(p_o) + 1;
			p1 += getlen(word1) + 1;
			if (i > p1)
				p_o[j - 1] = ' ';
		}
		else
			p1++;
	}
	reverse_cst(output);
	if (j != 0)
		printf("Result: %s\n", output);
	else
		error_code = INCORRECT_DATA;
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