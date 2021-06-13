#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "my_string.h"

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2
#define UNKOWN_KEY 53

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#define BUF_LEN 256

#include "my_string.h"

int sort_me(FILE *f);
int get_students_by_substr(FILE *f, FILE *f_out, char *);
int delete_under_avg(char *);
void f_copy(FILE *f, FILE *f_temp);
void swap(FILE *f, int pos1, int pos2);
double get_avg_of_std(student *std);
void f_del(char *fname, int *pos, int n_pos);
float get_sum(student *std);
double get_avg(FILE *f);
int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	//FILE *f;
	//FILE *f_out;
	char known_keys[3][3] = { "sb", "fb", "db" };
	if (args > 5 || args < 3)
		error_code = UNKOWN_KEY;
	else
	{
		// if (args == 3 && strcmp(keys[1], known_keys[0]) == 0)
		// {
			// f = fopen(keys[2], "r+b");
			// if (f == NULL)
			// {		
				// error_code = INPUT_ERROR;
			// }
			// else if(getlen(f) < 1)
				// error_code = INCORRECT_DATA;
			// else
			// {
				// error_code = sort_me(f);
				// if (error_code == NO_ERRORS)
					// print_f(f);
				// fclose(f);
			// }
		// }
		// else if (args == 5 && strcmp(keys[1], known_keys[1]) == 0)
		// {
			// f = fopen(keys[2], "rb");
			// f_out = fopen(keys[3], "wb");
			// if (f == NULL)
			// {		
				// error_code = INPUT_ERROR;
			// }
			// else if(getlen(f) < 1)
				// error_code = INCORRECT_DATA;
			// else
			// {
				// error_code = get_students_by_substr(f, f_out, keys[4]);
				// fclose(f);
			// }
			// fclose(f_out);
		// }
		if (args == 3 && strcmp(keys[1], known_keys[2]) == 0)
		{
			delete_under_avg(keys[2]);
		}
		else
			error_code = UNKOWN_KEY;
	}
	if (error_code == INPUT_ERROR)
		printf("INPUT_ERROR");
	else if (error_code == INCORRECT_DATA)
		printf("INCORRECT_DATA");
	return error_code;
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
			for (int j = 0; j < n - 1; j++)
			{
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

int get_students_by_substr(FILE *f, FILE *f_out, char *substr)
{
	int error_code = NO_ERRORS;
	if (getlen(f) < 1)
	{
		error_code = INCORRECT_DATA;
	}
	else
	{
		int n = getlen(f);
		for (int i = 0; i < n; i++)
		{
			student std = get_student(f, i);
			char *p_std = std.surname;
			if (strstr(p_std, substr) == p_std)
				fwrite(&std, sizeof(student), 1, f_out);
		}
		if (getlen(f_out) < 1)
			error_code = INCORRECT_DATA;
	}
	return error_code;
}

int delete_under_avg(char *fname)
{
	int error_code = NO_ERRORS;
	FILE *f = fopen(fname, "rb");
	if (f == NULL)
		error_code = INPUT_ERROR;
	else if (getlen(f) < 1)
	{
		error_code = INCORRECT_DATA;
		fclose(f);
	}
	else
	{
		FILE *temp = fopen("temp.bin", "wb+");
		int n = getlen(f);
		double avg = get_avg(f);
		for (int i = 0; i < n; i++)
		{
			student std = { 0 };
			fread(&std, sizeof(student), 1, f);
			double std_avg = get_avg_of_std(&std);
			if (std_avg >= avg)
			fwrite(&std, sizeof(student), 1, temp);
		}
		fclose(f);
		f = fopen(fname, "wb");
		error_code = getlen(temp) == 0 ? INCORRECT_DATA : 0;
		f_copy(f, temp);
		fclose(temp);
		remove("temp.bin");
		fclose(f);
	}
	return error_code;
}

double get_avg(FILE *f)
{
	double sum = 0;
	int n = getlen(f);
	for (int i = 0; i < n; i++)
	{
		student std = { 0 };
		fread(&std, sizeof(student), 1, f);
		sum += std.marks[0] + std.marks[1] + std.marks[2] + std.marks[3];
	}
	fseek(f, 0, SEEK_SET);
	sum = sum / (n * N);
	return sum;
}

double get_avg_of_std(student *std)
{
	double sum;
	for (int i = 0; i < N; i++)
		sum += (std->marks[i]);
	return sum;
}


void swap(FILE *f, int pos1, int pos2)
{
	student temp1 = { 0 };
	student temp2 = { 0 };

	fseek(f, (long long unsigned int)pos1 * sizeof(student), SEEK_SET);
	fread(&temp1, sizeof(student), 1, f);
	fseek(f, (long long unsigned int)pos2 * sizeof(student), SEEK_SET);
	fread(&temp2, sizeof(student), 1, f);
	fseek(f, (long long unsigned int)pos1 * sizeof(student), SEEK_SET);
	fwrite(&temp2, sizeof(student), 1, f);
	fseek(f, (long long unsigned int)pos2 * sizeof(student), SEEK_SET);
	fwrite(&temp1, sizeof(student), 1, f);
	fseek(f, 0, SEEK_SET);
}

void f_copy(FILE *f, FILE *f_temp)
{
	int n = getlen(f_temp);
	for (int k = 0; k < n; k++)
	{
		student std1 = { 0 };
		fread(&std1, sizeof(student), 1, f_temp);
		fwrite(&std1, sizeof(student), 1, f);
	}
}
