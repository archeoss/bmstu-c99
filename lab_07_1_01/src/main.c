// Сортировка - вариант 2:
// Сортировка обменом (метод пузырька):
// Последовательно сравниваются пары соседних элементов
// x[k] и x[k+1] (k = 0, 1, . . . , n-2)
// и, если x[k] > x[k+1], то они переставляются; 
// в результате наибольший элемент окажется на своём месте в конце массива;
// затем этот метод применяется ко всем элементам, кроме последнего, и т.д.

#include "../inc/sort.h"
#include "../inc/io.h"
#include "../inc/errors.h"

int main(int args, char **keys)
{
    int *a = NULL;
    int *a_end;
    int error_code = NO_ERROR;
    unsigned int count;
    if (args > 2 && args < 5)
    {
        count = fcount(keys[1]);
        if (count != 0)
        {
            a = malloc(count * sizeof(int));
            a_end = a + count;
        }
        else
            error_code = INCORRECT_DATA_ERROR;
        
        if (error_code == NO_ERROR)
            error_code = read_file(keys[1], a, a_end);
        
        if (error_code == NO_ERROR)
        {
            if (args == 4 && !(strcmp("f", keys[3])))
            {
                count -= 2;
                if (count < 1)
                    error_code = INCORRECT_DATA_ERROR;
                else
                {
                    int *a_tmp;
                    int *ae_tmp;
                    error_code = key(a, a_end, &a_tmp, &ae_tmp);
                    if (error_code == NO_ERROR)
                    {
                        free(a);
                        a = a_tmp;
                        a_end = ae_tmp;
                    }
                }
            }
            else if (args == 4 && (strcmp("f", keys[3])))
                error_code = KEY_ERROR;
            if (error_code == NO_ERROR)
            {
                if (count != 1)
                    mysort(a, (unsigned)(a_end - a), sizeof(int), (int(*)(const void *, const void *))comp);
                if (keys[2] != NULL)
                    error_code = write_arr(keys[2], a, a_end);
            }
        }
    }
    if (a)
        free(a);
    else
        error_code = KEY_ERROR;
    
    return error_code;
}
