#include <stdio.h>
#include <stdlib.h>
void put_random_numbers(FILE *f, int n)
{
	int number;
	for (int i = 0; i < n; i++) 
	{
		number = rand() % 1000;
		fwrite(&number, sizeof(int), 1, f);
	}
}

void print_f(FILE *f)
{
	int number;
	fread(&number, sizeof(int), 1, f);
	while (feof(f) == 0)
	{
		printf("%d ", number);
		fread(&number, sizeof(int), 1, f);
	}
	printf("\n");
}

size_t getlen(FILE *f)
{
	size_t n;
	fseek(f, 0, SEEK_END);
	n = ((size_t)ftell(f)) / sizeof(int);
	rewind(f);
	return n;
}

int get_number_by_pos(FILE *f, long long unsigned int pos)
{
	int number;
	fseek(f, pos * sizeof(int), SEEK_SET);
	fread(&number, sizeof(int), 1, f);
	rewind(f);
	return number;
}

void put_number_by_pos(FILE *f, long long unsigned int pos, int number)
{
	fseek(f, pos * sizeof(int), SEEK_SET);
	fwrite(&number, sizeof(int), 1, f);
	rewind(f);
}