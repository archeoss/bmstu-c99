#include "operations.h"

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

char *int_to_str(long long n)
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
    for (int i = 0; i < iters; i++)
    {
        char tmp = buffer[i + start];
        buffer[i + start] = buffer[size_buf - 1 - i];
        buffer[size_buf - 1 - i] = tmp;
    }

    return buffer;
}
