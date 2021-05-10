#include "my_string.h"
#include <stdio.h>


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

char *my_strpbrk(char *str, char *key)
{
	char *result = NULL;
	char *p_s; 
	char *p_k;
	p_s = str;
	p_k = key;
	int i = 0, j = 0;
	int size_k = getlen(key);
	int size_s = getlen(str);
	while (i < size_s && result == NULL)
	{
		while (j < size_k && result == NULL)
		{
			if (*p_k == *p_s)
				result = p_s;
			p_k++;
			j++;
		}
		i++;
		p_s++;
		p_k -= j;
		j = 0;
	}
	return result;
}

int my_strspn(char *str, char *key)
{
	int result = 0;
	char *p_s; 
	char *p_k;
	p_s = str;
	p_k = key;
	int i = 0, j = 0;
	int size_k = getlen(key);
	int size_s = getlen(str);
	int flag = 1;
	while (i < size_s && flag == 1)
	{
		flag = 0;
		while (j < size_k)
		{
			if (*p_k == *p_s)
			{
				result++;
				flag = 1;
			}
			p_k++;
			j++;
		}
		i++;
		p_s++;
		p_k -= j;
		j = 0;
	}
	return result;
}

int my_strcspn(char *str, char *key)
{
	char *p_s; 
	char *p_k;
	p_s = str;
	p_k = key;
	int i = 0, j = 0;
	int size_k = getlen(key);
	int size_s = getlen(str);
	int result = size_s;
	while (i < size_s && result == size_s)
	{
		while (j < size_k && result == size_s)
		{
			if (*p_k == *p_s)
				result = i;
			p_k++;
			j++;
		}
		i++;
		p_s++;
		p_k -= j;
		j = 0;
	}
	
	return result;
}

char *my_strchr(char *str, int sym)
{
	char *result = NULL;
	char *p_s;
	p_s = str;
	int i = 0;
	int size_s = getlen(str);
	while (i < size_s + 1 && result == NULL)
	{
		if (sym == *p_s)
			result = p_s;
		i++;
		p_s++;
	}
	return result;
}

char *my_strrchr(char *str, int sym)
{
	char *result = NULL;
	char *p_s;
	p_s = str;
	int i = 0;
	int size_s = getlen(str);
	while (i < size_s + 1)
	{
		if (sym == *p_s)
			result = p_s;
		i++;
		p_s++;
	}
	return result;
}