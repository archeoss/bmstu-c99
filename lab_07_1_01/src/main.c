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
    int *array = NULL;
    int *array_end;
    int error_code = NO_ERROR;
    unsigned int count;
    if (args > 2 && args < 5)
    {
        count = len_of_file(keys[1]);
        if (count > 0)
        {
            array = malloc(count * sizeof(int));
            array_end = array + count;
        }
        else
            error_code = INCORRECT_DATA_ERROR;
        
        if (error_code == NO_ERROR)
            error_code = read_file(keys[1], array, array_end);
        
        if (error_code == NO_ERROR)
        {
            if (args == 4 && !(strcmp("f", keys[3])))
            {
                
                if (count < 3)
                    error_code = INCORRECT_DATA_ERROR;
                else
                {
                    int *array_tmp;
                    int *array_end_tmp;
                    error_code = key(array, array_end, &array_tmp, &array_end_tmp);
                    if (error_code == NO_ERROR)
                    {
                        free(array);
                        array = array_tmp;
                        array_end = array_end_tmp;
                    }
                }
            }
            else if (args == 4 && (strcmp("f", keys[3])))
                error_code = KEY_ERROR;
            if (error_code == NO_ERROR)
            {
                count = array_end - array;
                if (count > 1)
                    mysort(array, (unsigned)(count), sizeof(int), (int(*)(const void *, const void *))comp);
                error_code = write_arr(keys[2], array, array_end);
            }
        }
    }
    if (array)
        free(array);
    else
        error_code = KEY_ERROR;
    
    return error_code;
}
