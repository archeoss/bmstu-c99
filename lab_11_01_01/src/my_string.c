#include "my_string.h"

#define NO_ERROR 0
#define ERROR    1
#define NO       0
#define YES      1
#define NORMAL   1
#define LONG     2
#define SHORT    3
#define BUFSIZE  255

char *oct_convert(unsigned long n)
{
    int cnt = 1;
    unsigned long tmp = n;
    
    do
    {
        cnt++;
        tmp = tmp / 8;
    }
    while (tmp);
    //printf("%ul, %d\n", n, cnt);
    char *buffer = malloc(sizeof(char) * cnt);
    int size_buf = 0;
    if (n == 0)
    {
        buffer[size_buf++] = '0';
        buffer[size_buf] = '\0';
    }
    while (n)
    {
        buffer[size_buf++] = n % 8 + '0';
        n = n / 8;
    }
    buffer[size_buf] = '\0';
    for (int i = 0; i < size_buf / 2; i++)
    {
        char tmp = buffer[i];
        buffer[i] = buffer[size_buf - 1 - i];
        buffer[size_buf - 1 - i] = tmp;
    }

    return buffer;
}

static char *int_to_str(long long n)
{
    long long cnt = 1;
    if (n < 0)
        cnt++;
    long long tmp = llabs(n);
    
    do
    {
        cnt++;
        tmp = tmp / 10;
    }
    while (tmp);
    
    char *buffer = malloc(sizeof(char) * cnt);
    int size_buf = 0;
    if (n == 0)
    {
        buffer[size_buf++] = '0';
        buffer[size_buf] = '\0';
    }
    if (n < 0)
    {
        buffer[size_buf++] = '-';
        n = -n;
    }
    while (n)
    {
        buffer[size_buf++] = n % 10 + '0';
        n = n / 10;
    }
    buffer[size_buf] = '\0';
    int start = (buffer[0] == '-') ? 1 : 0;
    int iters = size_buf / 2;
    //printf("%d\n", iters);
    for (int i = 0; i < iters; i++)
    {
        char tmp = buffer[i + start];
        buffer[i + start] = buffer[size_buf - 1 - i];
        buffer[size_buf - 1 - i] = tmp;
    }

    return buffer;
}

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    if (size == 0)
        return 0;
    if (!str || !format || !*format)
        return -1;
    size_t str_size = 0;
    va_list vl;
    va_start(vl, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            if (str_size < size)
                str[str_size] = *format;
            str_size++; 
        }
        else if (*format == '%')
        {
            if (*(format + 1) == 'd')
            {
                int number = va_arg(vl, int);
                
                char *temp = int_to_str(number);
                int i = 0;
                while (*(temp + i) != '\0' )
                {
                    if (str_size < size) 
                        str[str_size] = *(temp + i);
                    str_size++;
                    i++;
                }
                format += 1;
                free(temp);
            }
            else if (*(format + 1) == 's')
            {
                char *temp = va_arg(vl, char *);
                while (*temp != '\0')
                {
                    if (str_size < size) 
                        str[str_size] = *temp;
                    str_size++;
                    temp++;
                }
                format += 1;
            }
            else if (*(format + 1) == 'l' && *(format + 2) == 'd')
            {
                long long number = va_arg(vl, long);
                
                char *temp = int_to_str(number);
                int i = 0;
                while (*(temp + i) != '\0')
                {
                    if (str_size < size) 
                        str[str_size] = *(temp + i);
                    str_size++;
                    i++;
                }
                format += 2;
                free(temp);
            }
            else if (*(format + 1) == 'o')
            {
                unsigned int number = va_arg(vl, int);
                
                char *temp = oct_convert(number);
                int i = 0;
                while (*(temp + i) != '\0')
                {
                    if (str_size < size) 
                        str[str_size] = *(temp + i);
                    str_size++;
                    i++;
                }
                format += 1;
                free(temp);
            }
            else if (*(format + 1) == 'l' && *(format + 2) == 'o')
            {
                unsigned long number = va_arg(vl, long);
                
                char *temp = oct_convert(number);
                int i = 0;
                while (*(temp + i) != '\0')
                {
                    if (str_size < size) 
                        str[str_size] = *(temp + i);
                    str_size++;
                    i++;
                }
                format += 2;
                free(temp);
            }
            else if (*(format + 1) == 'c')
            {
                char chr = va_arg(vl, int);
                if (str_size < size) 
                    str[str_size] = chr;
                str_size++;
                format += 1;
            }
        }
        format++;
    }
    if (str_size < size)
        str[str_size] = '\0';
    else
        str[size - 1] = '\0';

    return str_size;
}