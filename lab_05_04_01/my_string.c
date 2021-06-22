#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define TEMP_FILE "temp.bin"
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
	if (ft % (long long int)sizeof(struct student) == 0)
	{
		n = (ft / (long long int)sizeof(struct student));
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

int get_students_by_substr(FILE *f, FILE *f_out, char *substr)
{
	int error_code = NO_ERRORS;
	struct student std1 = { 0 };
	int n = getlen(f);
	if (n < 1)
		error_code = INCORRECT_DATA;
	else	
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct student), 1, f);
			if (strstr(std1.surname, substr) == std1.surname)
				fwrite(&std1, sizeof(struct student), 1, f_out);
		}
	n = getlen(f_out);
	if (n < 1)
		error_code = INCORRECT_DATA;
	return error_code;
}

int delete_under_avg(FILE *f, char *key)
{
	int error_code = NO_ERRORS;
	float avg = 0;
	float mark_t;
	int n = getlen(f);
	if (key)
		error_code = NO_ERRORS;
	if (n < 1)
		error_code = INCORRECT_DATA;
	else	
	{
		FILE *f_temp = fopen(TEMP_FILE, "wb+");
		for (int k = 0; k < n; k++)
		{
			struct student std1 = { 0 };
			fread(&std1, sizeof(struct student), 1, f);
			for (int k = 0; k < N; k++)
				avg += std1.marks[k];
		}
		avg = avg / n;
		fseek(f, 0, SEEK_SET);
		for (int k = 0; k < n; k++)
		{
			struct student std1 = { 0 };
			fread(&std1, sizeof(struct student), 1, f);
			for (int j = 0; j < N; j++)
				mark_t += std1.marks[j];
			if (mark_t >= avg)
			{
				fwrite(&std1, sizeof(struct student), 1, f_temp);
			}
			mark_t = 0;
		}
		f = fopen(key, "wb");
		n = getlen(f_temp);
		f_copy(f, f_temp);
		fclose(f_temp);
		remove("temp.bin");
	}
	return error_code;
}

void swap(FILE *f, int pos1, int pos2)
{
	struct student temp1 = { 0 };
	struct student temp2 = { 0 };
	fseek(f, (long long unsigned int)pos1 * sizeof(struct student), SEEK_SET);
	fread(&temp1, sizeof(struct student), 1, f);
	fseek(f, (long long unsigned int)pos2 * sizeof(struct student), SEEK_SET);
	fread(&temp2, sizeof(struct student), 1, f);
	fseek(f, (long long unsigned int)pos1 * sizeof(struct student), SEEK_SET);
	fwrite(&temp2, sizeof(struct student), 1, f);
	fseek(f, (long long unsigned int)pos2 * sizeof(struct student), SEEK_SET);
	fwrite(&temp1, sizeof(struct student), 1, f);
	fseek(f, 0, SEEK_SET);
}

void f_copy(FILE *f, FILE *f_temp)
{
	int n = getlen(f_temp);
	fseek(f, 0, SEEK_SET);
	fseek(f_temp, 0, SEEK_SET);
	for (int k = 0; k < n; k++)
	{
		struct student std1 = { 0 };
		fread(&std1, sizeof(struct student), 1, f_temp);
		fwrite(&std1, sizeof(struct student), 1, f);
	}
}
int sort_me(FILE *f)
{
	int error_code = NO_ERRORS;
	int rc;
	int time_to_swap = 0;
	int n = getlen(f);
	if (n < 1)
		error_code = INCORRECT_DATA;
	else
	{
		int flag = 1, i = 0;
		while (i < n && flag == 1)
		{
			flag = 0;
			for (int j = 0; j < n - i - 1; j++)
			{
				time_to_swap = 0;
				rc = strcmp(get_student(f, j + 1).surname, get_student(f, j).surname);
				if (rc < 0)
				{
					flag = 1;
					time_to_swap = 1;
				}
				if (rc == 0)
				{
					rc = strcmp(get_student(f, j + 1).name, get_student(f, j).name);
					if (rc < 0)
					{
						flag = 1;
						time_to_swap = 1;
					}
				}
				if (time_to_swap == 1)
				{
					swap(f, j, j + 1);
				}
			}
			i++;
		}
	}
	return error_code;
}
