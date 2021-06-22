#ifndef _MY_STRING_H_

#define _MY_STRING_H_

#define SURNAME_LEN 25
#define NAME_LEN 10
#define N 4

struct student
{
	char surname[SURNAME_LEN + 1];
	char name[NAME_LEN + 1];
	unsigned int marks[N];
};
int getlen(FILE *f);
void print_f(FILE *f);
struct student get_student(FILE *f, int pos);
int sort_me(FILE *f);
int get_students_by_substr(FILE *f, FILE *f_out, char *);
int delete_under_avg(FILE *f, char *key);
void f_copy(FILE *f, FILE *f_temp);
void swap(FILE *f, int pos1, int pos2);
void copy_students_above_avg(FILE *f, FILE *f_temp, float avg, int n);
float get_avg(FILE *f, int n);

#endif