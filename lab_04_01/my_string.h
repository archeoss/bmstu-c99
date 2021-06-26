#ifndef _MY_STRING_H_

#define _MY_STRING_H_

char *my_strpbrk(char *, char *); 
void read_line(char *, int);
int my_strspn(char *str, char *key);
int my_strcspn(char *str, char *key);
char *my_strchr(char *str, int);
char *my_strrchr(char *str, int);
int getlen(char *s);

#endif