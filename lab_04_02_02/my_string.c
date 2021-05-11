#include "my_string.h"
#include <stdio.h>
#define MAX_LENGTH 256
#define MAX_WORD 30

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

int eql_wrds(char *str1, char *str2)
{
	char *p_s; 
	char *p_k;
	p_s = str1;
	p_k = str2;
	int i = 0;
	int size_s = getlen(str1);
	int size_k = getlen(str2);
	int result = 1;
	if (size_s != size_k)
		result = -1;
	while (i < size_s && result == 1)
	{
		if (*p_k != *p_s)
			result = -1;
		p_k++;
		i++;
		p_s++;
	}
	return result;
}

char *get_word(char *str, char *word)
{
	char *result = &word[0];
	char *p_s = str;
	int i = 0;
	int size_s = getlen(str);
	if (size_s == 0 || *p_s == ' ' || *p_s == ',' || *p_s== ';' || *p_s == ':' || *p_s == '-' || *p_s == '.' || *p_s == '?' || *p_s == '!')
		result = NULL;
	else
	{
		while (i < size_s && i < MAX_WORD && *p_s != ' ' && *p_s != ',' && *p_s != ';' && *p_s != ':' && *p_s != '-' && *p_s != '.' && *p_s != '?' && *p_s != '!')
		{
			if (*p_s != ' ')
				word[i] = *p_s;
			i++;
			p_s++;
		}
		word[i] = '\0';
	}
	return result;
}