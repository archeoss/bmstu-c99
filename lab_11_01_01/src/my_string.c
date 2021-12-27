#include "my_string.h"

int my_snprintf(char *restrict str, size_t size, const char *restrict format, ...)
{
    if ((!str || !format || !*format) && size != 0)
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
    else if (size > 0)
        str[size - 1] = '\0';

    return str_size;
}