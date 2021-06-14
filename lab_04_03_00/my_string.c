#include "my_string.h"
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256
#define MAX_WORD 16

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
	int j = 0;
	char *p_s = str;
	while (*p_s != '\0')
	{	
		while (j < MAX_WORD && *p_s != '\0' && *p_s != ' ' && *p_s != ',' && *p_s != ';' && *p_s != ':' && *p_s != '-' && *p_s != '.' && *p_s != '?' && *p_s != '!')
		{
			arr[i][j] = *p_s;
			j++;
			p_s++;
		}
		if (j != 0)
		{
			arr[i][j] = '\0';
			i++;
			j = 0;
		}
		if (*p_s != '\0')
			p_s++;
	}
	return i;
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