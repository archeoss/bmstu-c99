#include "my_string.h"
#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 256
#define MAX_WORD 256

int read_line(char *s, int n)
{
	int i = 0;
	int rc = 0;
	char ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		if (i < n)
			s[i++] = ch;
	s[i] = '\0';
	if (i == n)
		rc = 1;
	return rc;
}

int get_words(char *str, char **arr)
{
	int i = 0;
	char *c;
	char sep[] = { '\t', ' ', '\0' };
	c = strtok(str, sep);
	while (c != NULL)
	{
		arr[i] = c;
		c = strtok(NULL, sep);
		i++;
	}
	return i;
}