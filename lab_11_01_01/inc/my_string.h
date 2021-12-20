#ifndef _MY_STRING_H_

#define _MY_STRING_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>
#include <string.h>

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...);
char *oct_convert(unsigned long n);

#endif