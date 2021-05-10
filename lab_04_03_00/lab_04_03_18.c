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
	char output[MAX_LENGTH];
	char str1[MAX_LENGTH];
	read_line(str1, MAX_LENGTH);
	char *p1 = str1;
	char *p_o = output;
	char word1[MAX_WORD];
	char *i;
	char temp;
	i = str1 + getlen(str1);
	int	j = 0;
	int len;
	while (i > p1)
	{
		get_word(p1, word1);
		strip_r(word1, p_o + j);
		j = getlen(p_o) + 1;
		p_o[j - 1] = ' ';
		p1 += getlen(word1) + 1;
	}
	reverse_cst(output);
	printf("Result: %s\n", output);
	return 0;
}

void reverse_cst(char *str)
{
	int len = getlen(str);
	char temp;
	for (int j = 0; j < (len - 1) / 2; j++)
	{
		temp = str[j];
		str[j] = str[len - j - 2];
		str[len - j - 2] = temp;
	}
}