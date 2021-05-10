#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int main(void)
{
	char str1[MAX_LENGTH], str2[MAX_LENGTH];
	read_line(str1, MAX_LENGTH);
	read_line(str2, MAX_LENGTH);
	char *p1 = str1;
	char *p2 = str2;
	char word1[MAX_WORD];
	char word2[MAX_WORD];
	char wordt[MAX_WORD];
	int rc = -1;
	int len2 = getlen(str2);
	char *i;
	i = str1 + getlen(str1);
	char *j;
	j = str2 + getlen(str2);
	char *k;
	k = str1;
	printf("Result: ");
	while (i > p1)
	{
		get_word(p1, word1);
		while (k < p1 && rc == -1)
		{
			get_word(k, wordt);
			if (eql_wrds(word1, wordt) == 1)
				rc = 2;
			k += getlen(wordt) + 1;
		}
		while(j > p2 && rc == -1)
		{
			get_word(p2, word2);
			rc = eql_wrds(word1, word2);
			if (rc == 1)
			{
				printf("%s yes \n", word1);
			}
			p2 += getlen(word2) + 1;
		}
		if (rc == -1)
			printf("%s no \n", word1);
		rc = -1;
		p1 += getlen(word1) + 1;
		p2 = j - len2;
		k = str1;
	}
	return 0;
}