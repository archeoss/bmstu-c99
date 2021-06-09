#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <io.h>
#include "my_string.h"

#define NO_ERRORS 0
#define INPUT_ERROR -1
#define INCORRECT_DATA -2


#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

#include "my_string.h"

int sortMe(FILE *f);
int getStudentsBySubstr(FILE *f, FILE *f_out, char *);
int deleteUnderAvg(FILE *f);

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
				error_code = sortMe(f);
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
				error_code = getStudentsBySubstr(f, f_out, keys[4]);
			}
			fclose(f);
			fclose(f_out);
		}
		else if (args == 3 && keys[1][0] == 'd' && keys[1][1] == 'b' && keys[1][2] == '\0')
		{
			f = fopen(keys[2], "r+b");
			if (f == NULL)
			{		
				error_code = INPUT_ERROR;
			}
			else
			{
				deleteUnderAvg(f);
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

int sortMe(FILE *f)
{
	int error_code = NO_ERRORS;
	struct Student std1;
	struct Student std2;
	struct Student temp;
	int i = 0, j = 0;
	int flag = 1;
	int rc;
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / (long int)sizeof(struct Student);   
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
					fread(&std1, sizeof(struct Student), 1, f);
					fread(&std2, sizeof(struct Student), 1, f);
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
					fseek(f, (i - 1) * (long int)sizeof(struct Student), SEEK_SET);
					fwrite(&std1,sizeof(struct Student),1,f);
					fwrite(&std2,sizeof(struct Student),1,f);
					fseek(f, (i) * (long int)sizeof(struct Student), SEEK_SET);
				}
				rewind(f);
				i = 0;
			}
			j++;
		}
	return error_code;
}

int getStudentsBySubstr(FILE *f, FILE *f_out, char *substr)
{
	int error_code = NO_ERRORS;
	struct Student std1;
	int rc;
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / (long int)sizeof(struct Student);   
	fseek(f, 0, SEEK_SET);
	if (n < 2)
		error_code = INCORRECT_DATA;
	else	
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct Student), 1, f);
			rc = findSubstr(std1.surname, substr);
			if (rc == 1)
				fwrite(&std1, sizeof(struct Student), 1, f_out);
		}
	return error_code;
}

int deleteUnderAvg(FILE *f)
{
	int error_code = NO_ERRORS;
	struct Student std1;
	float avg = 0;
	uint32_t mark_t;
	int deleted = 0;
	fseek(f, 0, SEEK_END);
	int n = ftell(f) / (long int)sizeof(struct Student);   
	fseek(f, 0, SEEK_SET);
	if (n < 2)
		error_code = INCORRECT_DATA;
	else	
	{
		for (int k = 0; k < n; k++)
		{
			fread(&std1, sizeof(struct Student), 1, f);
			for (int k = 0; k < N; k++)
				avg += std1.marks[k];
		}
		avg = avg / n;
		for (int k = 0; k < n; k++)
		{
			fseek(f, k * (long int)sizeof(struct Student), SEEK_SET);
			fread(&std1, sizeof(struct Student), 1, f);
			
			for (int j = 0; j < N; j++)
				mark_t += std1.marks[j];
			if (mark_t < avg)
			{
				for (int i = k; i < n - deleted; i++)
				{
					fwrite(&std1, sizeof(struct Student), 1, f);
					fread(&std1, sizeof(struct Student), 1, f);
				}
				deleted++;
			}
			mark_t = 0;
		}
		chsize(fileno(f), (int)sizeof(struct Student) * (n - deleted));
	}
	return error_code;
}
