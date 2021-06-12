#include "my_string.h"
#include <string.h>
#include <stdio.h>
#define MAX_LENGTH 256
#define MAX_WORD 256

int read_line(char *s, int n)
{
	int ch, i = 0;
	int rc = 0;
	while ((ch = getchar()) != '\n' && ch != EOF && i < MAX_LENGTH)
		if (i < n - 1)
			s[i++] = ch;
	s[i] = '\0';
	if (ch != EOF && ch != '\n')
		rc = -1;
	return rc;
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

int get_words(char *str, char **arr)
{
	int i = 0;
	char dels[] = { '\0', '\t', ' '};
	char *p_s = strtok(str, dels);
	while (p_s != NULL)
	{	
		arr[i++] = p_s;
		p_s = strtok(str, dels);
	}
	return i;
}