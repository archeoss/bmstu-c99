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
void print_f(FILE *f);
struct student get_student(FILE *f, int pos);

#endif