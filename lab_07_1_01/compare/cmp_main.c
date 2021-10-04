#include "../inc/sort.h"
#include "../inc/readme.h"
#include <time.h>

int comp(const int *i, const int *j)
{
    return *i - *j;
}

#define N 100
#define NN 100
#define TIMES 10
int main()
{
    double timespent_a[TIMES];
    double timespent_b[TIMES];
    int *a = malloc(N * NN * sizeof(int));
    int *b = malloc(N * NN * sizeof(int));
    FILE* f1 = fopen("Data1.txt", "w");
    FILE* f2 = fopen("Data2.txt", "w");
    for (int j = 0; j < NN; j++)
    {
        srand(time(NULL) * j);
        for (int i = 0; i < N * j; i++)
        {
            int t = (rand() % 51);
            b[i] = t; 
            a[i] = t;
        }
        for (int k = 0; k < TIMES; k++)
        {
            int *a_cpy = malloc(N * NN * sizeof(int));
            int *b_cpy = malloc(N * NN * sizeof(int));
    
            for (int i = 0; i < N * j; i++)
            {
                b_cpy[i] = b[i]; 
                a_cpy[i] = a[i];
            }
            clock_t begin_a = clock();
            mysort(a_cpy, (unsigned)(N * j), sizeof(int), (int(*)(const void *, const void *))comp);
            clock_t end_a = clock();
            timespent_a[k] = (double)(end_a - begin_a) / CLOCKS_PER_SEC;

            clock_t begin_b = clock();
            qsort(b_cpy, (unsigned)(N * j), sizeof(int), (int(*)(const void *, const void *))comp);
            clock_t end_b = clock();
            timespent_b[k] = (double)(end_b - begin_b) / CLOCKS_PER_SEC;
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
        fprintf(f1, "%f\n", sum_a / (TIMES - 2));
        fprintf(f2, "%f\n", sum_b / (TIMES - 2));
    }
    free(a);
    free(b);
    fclose(f1);
    fclose(f2);
    return 0;
}