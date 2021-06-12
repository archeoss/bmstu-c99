#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "my_string.h"

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2


#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#include "my_string.h"

int sort_me(FILE *f);
int get_students_by_substr(FILE *f, FILE *f_out, char *);
int delete_under_avg(FILE *f, FILE *f_temp);
int f_copy(FILE *f, FILE *f_temp);

int main(int args, char **keys)
{
	int error_code = NO_ERRORS;
	FILE *f;
	FILE *f_out;
	if (args > 5 || args < 3)
		error_code = INPUT_ERROR;
	else
	{
		if (args == 3 && keys[1][0] == 's' && keys[1][1] == 'b' && keys[1][2] == '\0')
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
		else if (args == 5 && keys[1][0] == 'f' && keys[1][1] == 'b' && keys[1][2] == '\0')
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
		else if (args == 3 && keys[1][0] == 'd' && keys[1][1] == 'b' && keys[1][2] == '\0')
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
			error_code = INPUT_ERROR;
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
	int i = 0, j = 0;
	int flag = 1;
	int rc;
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / (long int)sizeof(struct student);   
	fseek(f, 0, SEEK_SET);
	if (n < 2)
		error_code = INCORRECT_DATA;
	else
		while (flag == 1)
		{	
			for (int k = 0; k < n; k++)
			{			
				while (i < n - 1)
				{
					flag = 0;
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
				rewind(f);
				i = 0;
			}
			j++;
		}
	return error_code;
}

int get_students_by_substr(FILE *f, FILE *f_out, char *substr)
{
	int error_code = NO_ERRORS;
	struct student std1;
	int rc;
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / (long int)sizeof(struct student);   
	fseek(f, 0, SEEK_SET);
	if (n < 2)
		error_code = INCORRECT_DATA;
	else	
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct student), 1, f);
			rc = findSubstr(std1.surname, substr);
			if (rc == 1)
				fwrite(&std1, sizeof(struct student), 1, f_out);
		}
	return error_code;
}

int delete_under_avg(FILE *f, FILE *f_temp)
{
	int error_code = NO_ERRORS;
	struct student std1;
	float avg = 0;
	uint32_t mark_t;
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / (long int)sizeof(struct student);   
	fseek(f, 0, SEEK_SET);
	if (n < 2)
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

int f_copy(FILE *f, FILE *f_temp)
{
	int error_code = NO_ERRORS;
	struct student std1;
	fseek(f_temp, 0, SEEK_END);
	int n = ftell(f_temp) / (long int)sizeof(struct student);   
	fseek(f_temp, 0, SEEK_SET);
	for (int k = 0; k < n; k++)
	{
		fread(&std1, sizeof(struct student), 1, f_temp);
		fwrite(&std1, sizeof(struct student), 1, f);
	}
	return error_code;
}