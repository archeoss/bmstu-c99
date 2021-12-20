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
    char *buffer = malloc(sizeof(char) * BUFSIZE);
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
    char *buffer = malloc(sizeof(char) * BUFSIZE);
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

int my_snprintf(char *str, size_t size, const char *format, ...)
{
    if (size == 0)
        return -1;
    char *s = malloc(size * sizeof(char));
    va_list vl;
    size_t str_size = 0;
    va_start(vl, format);
    int error_code = NO_ERROR;
    short type_size;
    if (str && size)
    {
        while (*format != '\0')
        {
            int is_allocated = NO;
            if (*format != '%')
            {
                if (str_size < size)
                    s[str_size++] = *format;
                format++;
            }
            if (*format == '%')
            {
                format++;
                if (str_size < size)
                {
                    switch (*format)
                    {
                        case 'l':
                            type_size = LONG;
                            format++;
                            break;
                        case 'h':
                            type_size = SHORT;
                            format++;
                            break;    
                        default:
                            type_size = NORMAL;
                            break;
                    }
                    if (*format != '\0')
                    {
                        char *to_print;
                        if (type_size == LONG)
                        {
                            switch (*format)
                            {
                                case 'd':
                                    is_allocated = YES;
                                    to_print = int_to_str(va_arg(vl, int64_t));
                                    break;
                                case 'o':
                                    is_allocated = YES;
                                    to_print = oct_convert(va_arg(vl, int64_t));
                                    break;
                                default:
                                    error_code = ERROR;
                                    break;
                            }
                        }
                        else
                        {
                            is_allocated = NO;
                            switch (*format)
                            {
                                case 'd':
                                    is_allocated = YES;
                                    to_print = int_to_str(va_arg(vl, int32_t));
                                    break;
                                case 'o':
                                    is_allocated = YES;
                                    to_print = oct_convert(va_arg(vl, uint32_t));
                                    break;
                                case 's':
                                    to_print = va_arg(vl, char *);
                                    break;
                                case 'c':
                                    is_allocated = YES;
                                    char tmp = va_arg(vl, int);
                                    to_print = malloc(sizeof(char) * 2);
                                    to_print[0] = tmp;
                                    to_print[1] = '\0';
                                    break;
                                default:
                                    error_code = ERROR;
                                    break;
                            }
                        }
                        format++;
                        char *cur_pos = to_print;
                        while (*cur_pos != '\0' && str_size < size && error_code == NO_ERROR)
                            s[str_size++] = *(cur_pos++);
                        if (is_allocated)
                            free(to_print);
                    }
                }
            }
        }
        va_end(vl);
        if (str_size == size)
            str[size - 1] = '\0';
        else
            str[str_size] = '\0';
    }
    memcpy(str, s, str_size);

    return str_size;
}