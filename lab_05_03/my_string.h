#ifndef _MY_STRING_H_

#define _MY_STRING_H_

int print_f(FILE *f);
void put_random_numbers(FILE *f, int n);
int getlen(FILE *f);
void put_number_by_pos(FILE *f, int pos, int number);
int get_number_by_pos(FILE *f, int pos);
#endif