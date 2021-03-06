#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define MAX_LENGTH 256

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int main(void)
{
	char str[MAX_LENGTH], key[MAX_LENGTH];
	read_line(str, MAX_LENGTH);
	read_line(key, MAX_LENGTH);
	int sym = getchar();
	char *s = my_strpbrk(str, key);
	printf("%s ", s);
	s = strpbrk(str, key);
	printf("%s \n\n", s);
	int c = my_strspn(str, key);
	printf("%d ", c);
	c = strspn(str, key);
	printf("%d \n\n", c);
	int ed = my_strcspn(str, key);
	printf("%d ", ed);
	ed = strcspn(str, key);
	printf("%d \n\n", ed);
	s = my_strchr(str, sym);
	printf("%s ", s);
	s = strchr(str, sym);
	printf("%s \n\n", s);
	s = my_strrchr(str, sym);
	printf("%s ", s);
	s = strrchr(str, sym);
	printf("%s \n\n", s);
	s = my_strchr(str, (int)'\0');
	printf("%s s", s);
	s = strchr(str, (int)'\0');
	printf("%s s\n\n", s);
	s = my_strrchr(str, (int)'\0');
	printf("%s s", s);
	s = strrchr(str, (int)'\0');
	printf("%s s", s);
	return 0;
}

