#include "my_string.h"
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

void read_line(char *s, int n)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n' && ch != EOF)
		if (i < n - 1)
			s[i++] = ch;
	s[i] = '\0';
}

int getlen(char *s)
{
	char *cur = s;
	int len = 0;
	while (*cur)
	{
		len++;
		cur++;
	}
	return len;
}

void reverse(char *word)
{
	int len = getlen(word);
	char temp;
	if (len > 1)
		for (int j = 0; j < len / 2; j++)
		{
			temp = word[j];
			word[j] = word[len - j - 1];
			word[len - j - 1] = temp;
		}
}

void strip_r(char *input, char *output)
{
	int len = getlen(input);
	int count = 0;
	*output = input[0];
	output++;
	count++;
	for (int i = 1; i < len; i++)
	{
		if (input[i] != input[0])
		{
			*output = input[i];
			output++;
			count++;
		}
	}
	*output = '\0';
	reverse(output - count);
}

int is_uniq(char *str, char **arr, int n)
{
	int flag = 0;
	int i = 0;
	int rc;
	int result = 0;
	while (i < n && flag == 0)
	{
		if ((rc = strcmp(str, arr[i])) == 0)
			flag = 1;
		i++;
	}
	if (flag == 0)
		result = 1;
	else
		result = 0;
	return result;
}

int get_words(char *str, char **arr)
{
	int i = 0;
	char *c;
	char sep[] = " .:;,-.?!\t\0";
	c = strtok(str, sep);
	while (c != NULL)
	{
		arr[i] = c;
		c = strtok(NULL, sep);
		i++;
	}
	return i;
}

void reverse_cst(char *str)
{
	int len = getlen(str);
	for (int j = 0; j < (len - len % 2) / 2; j++)
	{
		swap(str + j, str + len - j - 1);
	}
}

void swap(char *str1, char *str2)
{
	char temp;
	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

int strip_me(char **arr, char *output, int count)
{
	int i = 0, j = 0, error_code = NO_ERRORS;
	while (i < count - 1)
		{
			if ((strcmp(arr[i], arr[count - 1])) != 0)
			{
				strip_r(arr[i], output + j);
				j = getlen(output) + 1;
				if (i < count - 2)
					output[j - 1] = ' ';
			}
			i++;
		}
	if (j == 0)
		error_code = INCORRECT_DATA;
	else
	{
		j--;
		remove_end_spaces(output + j);
		reverse_cst(output);
	}
	return error_code;
}

void remove_end_spaces(char *str)
{
	while (*str == ' ')
		{
			str = '\0';
			str--;
		}
}