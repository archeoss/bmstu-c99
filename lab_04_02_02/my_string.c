#include "my_string.h"
#include <stdio.h>

#define MAX_LENGTH 256
#define MAX_WORD 16

#define DELIMS " .:;,-.?!\0"
#define DELIMS_COUNT 10
#define YES 1
#define NO -1

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
//Функция возвращает 1 в случае если слова равны, и -1 если нет
int eql_wrds(char *str1, char *str2)
{
	char *p_s; 
	char *p_k;
	p_s = str1;
	p_k = str2;
	int i = 0;
	int size_s = getlen(str1);
	int size_k = getlen(str2);
	int result = YES;
	if (size_s != size_k)
		result = NO;
	while (i < size_s && result == 1)
	{
		if (*p_k != *p_s)
			result = NO;
		p_k++;
		i++;
		p_s++;
	}
	return result;
}

int get_words(char *str, char **arr)
{
	int i = 0, j = 0, k, flag, last_flag = 1;
	char delims[] = DELIMS;
	while (*str != '\0')
	{	
		k = 0;
		flag = 0;
		while (k < DELIMS_COUNT && flag == 0)
		{
			if (delims[k] == *str)
			{
				if (last_flag == 0)
				{
					arr[i] = str - j;
					printf("%d %c\n", j, *(str-j));
					i++;
				}
				flag = 1;
			}
			k++;
		}
//		printf("%d %c\n", j, *str);
		j++;
		if (*str != '\0')
		{
			if (flag != 0)
			{
				j = 0;
				*str = '\0';
			}
			str++;
		}
		last_flag = flag;
	}
	if (last_flag == 0)
	{
		arr[i] = str - j;
		printf("%d %c\n", j, *(str-j));
		i++;
	}
	for (int s = 0; s < i; s++)
		printf("%s\n", arr[s]);
	return i;
}

void get_pntrs(char *a, char **pntrs)
{
	for (int i = 0; i < MAX_LENGTH/2; i++)
		pntrs[i] = a + i * MAX_WORD;
}