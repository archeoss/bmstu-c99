#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#include "my_string.h"

int compare_wrds(char *str1, char *str2)
{
	char *p_s; 
	char *p_k;
	p_s = str1;
	p_k = str2;
	int result = 0;
	while (*p_k != '\0' && *p_s != '\0' && result == 0)
	{
		if (*p_k < *p_s)
			result = -1;
		if (*p_k > *p_s)
			result = 1;
		p_k++;
		p_s++;
	}
	if (result == 0)
	{
		if (*p_s == '\0' && *p_s != *p_k)
			result = 1;
		else if (*p_k == '\0' && *p_s != *p_k)
			result = -1;
	}
	return result;
}

int getlen(FILE *f)
{
	int n;
	fseek(f, 0, SEEK_END);
	if (ftell(f) % (long int)sizeof(struct student) == 0)
	{
		n = ((int)ftell(f)) / (long int)sizeof(struct student);
    }
	else
        n = -1;
	fseek(f, 0, SEEK_SET);
	return n;
}

void print_f(FILE *f)
{
	struct student std;
	int cnt = getlen(f);
	for (int i = 0; i < cnt; i++)
	{
		fread(&std, sizeof(struct student), 1, f);
		printf("%s\n%s\n", std.surname, std.name);
		for (int j = 0; j < N; j++)
			printf("%d ", std.marks[j]);
		printf("\n");
	}
}

int find_substr(char *str1, char *substr)
{
	char *p_s; 
	char *p_k;
	p_s = str1;
	p_k = substr;
	int i = 0;
	int result = 0;
	while (*p_k != '\0' && *p_s != '\0' && result == 0)
	{
		if (*p_k != *p_s)
			result = -1;
		p_k++;
		i++;
		p_s++;
	}
	if (result == 0)
	{
		if (*p_s == '\0' && *p_s != *p_k)
			result = -1;
		else
			result = 1;
	}
	return result;
}