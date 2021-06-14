#ifndef _MY_STRING_H_

#define _MY_STRING_H_
 
void read_line(char *, int);
int getlen(char *s);
int get_words(char *str, char **arr);
void strip_r(char *input, char *output);
void reverse(char *word);
void reverse_cst(char *str);
void get_pntrs(char *a, char **pntrs);

#endif