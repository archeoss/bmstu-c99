#include "../inc/sort.h"
#include "../inc/io.h"
#include <time.h>

#define TIMES 10

int main()
{
    double timespent_a[TIMES];
    double timespent_b[TIMES];
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < TIMES; i++)
    {
        clock_t begin_a = clock();
        mysort(a, 10, sizeof(int), (int(*)(const void *, const void *))comp);
        clock_t end_a = clock();
        timespent_a[i] = (double)(end_a - begin_a) / CLOCKS_PER_SEC;

        clock_t begin_b = clock();
        qsort(b, 10, sizeof(int), (int(*)(const void *, const void *))comp);
        clock_t end_b = clock();
        timespent_b[i] = (double)(end_b - begin_b) / CLOCKS_PER_SEC;
        
    }
    for (int k = 0; k < TIMES; k++)
    {
        if (timespent_a[k] > timespent_a[0])
        {
            double tmp = timespent_a[k];
            timespent_a[k] = timespent_a[0];
            timespent_a[0] = tmp;
        }
        if (timespent_a[k] < timespent_a[1])
        {
            double tmp = timespent_a[k];
            timespent_a[k] = timespent_a[1];
            timespent_a[1] = tmp;
        }
        if (timespent_b[k] > timespent_b[0])
        {
            double tmp = timespent_b[k];
            timespent_b[k] = timespent_b[0];
            timespent_b[0] = tmp;
        }
        if (timespent_b[k] < timespent_b[1])
        {
            double tmp = timespent_b[k];
            timespent_b[k] = timespent_b[1];
            timespent_b[1] = tmp;
        }
    }
    double sum_a = 0;
    double sum_b = 0;
    for (int k = 2; k < TIMES; k++)
    {
        sum_a += timespent_a[k];
        sum_b += timespent_b[k];
    }
    printf("my_sort: %f\n", sum_a / (TIMES - 2));
    printf("qsort: %f\n", sum_b / (TIMES - 2));
    
    return 0;
}