#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2

#include "my_string.h"

int getlen(FILE *f)
{
	int n;
	fseek(f, 0, SEEK_END);
	long long int ft = ftell(f);
	if (ft % sizeof(student) == 0)
	{
		n = (ft / sizeof(student));
    }
	else
        n = 0;
	fseek(f, 0, SEEK_SET);
	return n;
}

void print_f(FILE *f)
{
    int n = getlen(f);
    for (int i = 0; i < n; i++)
    {
        student std = { 0 };
        fread(&std, sizeof(student), 1, f);
        print_std(&std);
    }
}

void print_std(student *std)
{
    printf("%s\n", std->surname);
    printf("%s\n", std->name);
	for (int i = 0; i < N; i++)
    {
		printf("%d ", std->marks[i]);
	}
    printf("\n");
}

student get_student(FILE *f, int pos)
{
	fseek(f, pos * sizeof(student), SEEK_SET);
    student std = { 0 };
    fread(&std, sizeof(student), 1, f);
    fseek(f, 0, SEEK_SET);
    return std;
}
