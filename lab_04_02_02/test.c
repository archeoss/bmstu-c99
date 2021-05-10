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
	int s = getlen(str);
	printf("%d ", s);
	s = getlen(key);
	printf("%d \n\n", s);
	int c = eql_wrds(str, key);
	printf("%d ", c);
	c = eql_wrds(key, key);
	printf("%d \n\n", c);
	return 0;
}
