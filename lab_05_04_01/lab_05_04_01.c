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

#include "my_string.h"

int sort_me(FILE *f);
int get_students_by_substr(FILE *f, FILE *f_out, char *);
int delete_under_avg(FILE *f, FILE *f_temp);
void f_copy(FILE *f, FILE *f_temp);

int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	FILE *f;
	FILE *f_out;
	char known_keys[3][3] = { "sb", "fb", "db" };
	if (args > 5 || args < 3)
		error_code = UNKOWN_KEY;
	else
	{
		if (args == 3 && strcmp(keys[1], known_keys[0]) == 0)
		{
			f = fopen(keys[2], "r+b");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				error_code = sort_me(f);
				if (error_code == NO_ERRORS)
					print_f(f);
			}
			fclose(f);
		}
		else if (args == 5 && strcmp(keys[1], known_keys[1]) == 0)
		{
			f = fopen(keys[2], "rb");
			f_out = fopen(keys[3], "wb");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				error_code = get_students_by_substr(f, f_out, keys[4]);
			}
			fclose(f);
			fclose(f_out);
		}
		else if (args == 3 && strcmp(keys[1], known_keys[2]) == 0)
		{
			f = fopen(keys[2], "rb");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				char tmp_f[] = { "temp.bin" };
				FILE *f_temp = fopen(tmp_f, "w+b");
				delete_under_avg(f, f_temp);
				fclose(f);
				f = fopen(keys[2], "wb");
				f_copy(f, f_temp);
				fclose(f_temp);
				remove(tmp_f);
			}			
			fclose(f);
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
	struct student std1;
	struct student std2;
	struct student temp;
	int rc;
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
				fread(&std1, sizeof(struct student), 1, f);
				fread(&std2, sizeof(struct student), 1, f);
				i++;
				rc = compare_wrds(std1.surname, std2.surname);
				if (rc == -1)
				{
					flag = 1;
					temp = std1;
					std1 = std2;
					std2 = temp;
				}
				if (rc == 0)
				{
					rc = compare_wrds(std1.name, std2.name);
					if (rc == -1)
					{
						flag = 1;
						temp = std1;
						std1 = std2;
						std2 = temp;
					}
				}
				fseek(f, (i - 1) * (long int)sizeof(struct student), SEEK_SET);
				fwrite(&std1, sizeof(struct student), 1, f);
				fwrite(&std2, sizeof(struct student), 1, f);
				fseek(f, (i) * (long int)sizeof(struct student), SEEK_SET);
			}
			fseek(f, 0, SEEK_SET);
			i = 0;
		}
	}
	return error_code;
}

int get_students_by_substr(FILE *f, FILE *f_out, char *substr)
{
	int error_code = NO_ERRORS;
	struct student std1;
	int rc;
	int n = getlen(f);
	if (n < 1)
		error_code = INCORRECT_DATA;
	else	
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct student), 1, f);
			rc = find_substr(std1.surname, substr);
			if (rc == 1)
				fwrite(&std1, sizeof(struct student), 1, f_out);
		}
	n = getlen(f_out);
	if (n < 1)
		error_code = INCORRECT_DATA;
	return error_code;
}

int delete_under_avg(FILE *f, FILE *f_temp)
{
	int error_code = NO_ERRORS;
	struct student std1;
	float avg = 0;
	uint32_t mark_t;
	int n = getlen(f);
	if (n < 1)
		error_code = INCORRECT_DATA;
	else	
	{
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct student), 1, f);
			for (int k = 0; k < N; k++)
				avg += std1.marks[k];
		}
		avg = avg / n;
		fseek(f, 0, SEEK_SET);
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct student), 1, f);
			for (int j = 0; j < N; j++)
				mark_t += std1.marks[j];
			if (mark_t >= avg)
			{
				fwrite(&std1, sizeof(struct student), 1, f_temp);
			}
			mark_t = 0;
		}
	}
	return error_code;
}

void f_copy(FILE *f, FILE *f_temp)
{
	struct student std1;
	int n = getlen(f_temp);
	for (int k = 0; k < n; k++)
	{
		fread(&std1, sizeof(struct student), 1, f_temp);
		fwrite(&std1, sizeof(struct student), 1, f);
	}
}