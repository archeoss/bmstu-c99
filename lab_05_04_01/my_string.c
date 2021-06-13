#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#include "my_string.h"

int getlen(FILE *f)
{
	int n;
	fseek(f, 0, SEEK_END);
	long long int ft = ftell(f);
	if (ft % sizeof(struct student) == 0)
	{
		n = (ft / sizeof(struct student));
    }
	else
        n = 0;
	fseek(f, 0, SEEK_SET);
	return n;
}

void print_f(FILE *f)
{
	int cnt = getlen(f);
	for (int i = 0; i < cnt; i++)
	{
		struct student std = { 0 };
		fread(&std, sizeof(struct student), 1, f);
		printf("%s\n%s\n", std.surname, std.name);
		for (int j = 0; j < N; j++)
			printf("%d ", std.marks[j]);
		printf("\n");
	}
}

struct student get_student(FILE *f, int pos)
{
	fseek(f, pos * sizeof(struct student), SEEK_SET);
    struct student std = { 0 };
    fread(&std, sizeof(struct student), 1, f);
    fseek(f, 0, SEEK_SET);
    return std;
}
