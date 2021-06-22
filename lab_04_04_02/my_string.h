#ifndef _MY_STRING_H_

#define _MY_STRING_H_
 
int read_line(char *, int);
int getlen(char *s);
int get_words(char *str, char **arr);
void get_pntrs(char *a, char **pntrs);
int get_int_date(char *a);
void lower_str(char *str);
int get_month(char *str, char *months, int char_size, int n);
int vis_check(int year);
int check_date(int day, int month, int year, int days_in_month);

#endif