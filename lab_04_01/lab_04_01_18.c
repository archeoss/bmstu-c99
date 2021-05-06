#include <stdio.h>
#include "my_string.h"
#include <string.h>

#define NO_ERRORS 0
#define INPUT_ERROR 1
#define INCORRECT_DATA 2

int main(void)
{
	char str[256], key[256];
	read_line(str, 256);
	read_line(key, 256);
	int sym = getchar();
	char *s = my_strpbrk(str, key);
	printf("%s ", s);
	s = strpbrk(str, key);
	printf("%s ", s);
	int c = my_strspn(str, key);
	printf("%d ", c);
	c = strspn(str, key);
	printf("%d ", c);
	int ed = my_strcspn(str, key);
	printf("%d ", ed);
	ed = strcspn(str, key);
	printf("%d ", ed);
	s = my_strchr(str, sym);
	printf("%s ", s);
	s = strchr(str, sym);
	printf("%s ", s);
	s = my_strrchr(str, sym);
	printf("%s ", s);
	s = strrchr(str, sym);
	printf("%s ", s);
	return 0;
}

