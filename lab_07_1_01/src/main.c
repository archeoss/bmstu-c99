// Сортировка - вариант 2:
// Сортировка обменом (метод пузырька):
// Последовательно сравниваются пары соседних элементов
// x[k] и x[k+1] (k = 0, 1, . . . , n-2)
// и, если x[k] > x[k+1], то они переставляются; 
// в результате наибольший элемент окажется на своём месте в конце массива;
// затем этот метод применяется ко всем элементам, кроме последнего, и т.д.

#include "../inc/sort.h"
#include "../inc/readme.h"

#define NO_ERROR 0
#define KEY_ERROR 1
#define INCORRECT_DATA_ERROR 2
#define NOT_FOUND 3
int comp(const int *i, const int *j);

int main(int args, char **keys)
{
    int error_code = NO_ERROR;
    FILE *f;
    unsigned int count;
    if (args > 2 && args < 5)
    {
        if ((f = fopen(keys[1], "r")) != NULL)
        {
            count = fcount(f);
            if (count != 0)
            {
                int *a = malloc(count * sizeof(int));
                int *a_end = a + count;
                error_code = read_file(f, a, a_end);
                if (error_code == NO_ERROR)
                {
                    if (args == 4 && !(strcmp("f",keys[3])))
                    {
                        count -= 2;
                        if (count < 1)
                            error_code = INCORRECT_DATA_ERROR;
                        else
                        {
                            int *a_tmp = malloc(count * sizeof(int));
                            int *ae_tmp = a_tmp + count;
                            error_code = key(a, a_end, &a_tmp, &ae_tmp);
                            free(a);
                            a = a_tmp;
                            a_end = ae_tmp;
                            //for (int i = 0; i < (int)count; i++)
                            //    printf("%d\n", a[i]);
                        }
                    }
                    if (error_code == NO_ERROR)
                    {
                        fclose(f);
                        if (count != 1)
                            mysort(a, count, sizeof(int), (int(*) (const void *, const void *))comp);
                        if ((f = fopen(keys[2], "w")) != NULL)
                            error_code = write_arr(f, a, a_end);
                    }
                    // for (int i = 0; i < (int)count; i++)
                    //     printf("%d\n", a[i]);
                }
                free(a);
            }
            else
                error_code = INCORRECT_DATA_ERROR;
            fclose(f);
        }
        else
            error_code = KEY_ERROR;
    }
    else
        error_code = KEY_ERROR;
    return error_code;
}

int comp(const int *i, const int *j)
{
    return *i - *j;
}