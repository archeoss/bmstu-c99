#ifndef _MY_STRING_H_

#define _MY_STRING_H_

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

struct student
{
	char surname[SURNAME_LEN + 1];
	char name[NAME_LEN + 1];
	uint32_t marks[N];
};
int getlen(FILE *f);
int compare_wrds(char *str1, char *str2);
void print_f(FILE *f);
int find_substr(char *str1, char *str2);

#endif