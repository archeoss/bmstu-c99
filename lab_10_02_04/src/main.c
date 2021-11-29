#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "errors.h"
#include "operations.h"
#include "structures.h"
#include "defines.h"
#include "mem_alloc.h"

int main(void)
{
    int error_code = NO_ERROR;
    node_t *head_a = NULL;
    node_t *head_b = NULL;
    int mode = get_mode();
    
    switch (mode)
    {
        case OUT_MODE:
            head_a = get_number();
            if (head_a)
                print_simple(&head_a);
            else
                error_code = NO_OUT;
            break;
        case MUL_MODE:
            head_a = get_number();
            head_b = get_number();
            if (head_a && head_b)
            {
                node_t *result = simple_mul(&head_a, &head_b, compare_numbers);
                print_simple(&result);
            }
            else
            {
                clear_list(head_a);
                clear_list(head_b);
                error_code = INCORRECT_DATA_ERROR;
            }
            break;
        case SQR_MODE:
            head_a = get_number();
            if (head_a)
            {
                simple_sqr(head_a);
                print_simple(&head_a);
            }
            else
                error_code = INCORRECT_DATA_ERROR;
            break;
        case DIV_MODE:
            head_a = get_number();
            head_b = get_number();
            if (head_a && head_b)
            {
                error_code = simple_div(&head_a, &head_b);
                if (error_code == NO_ERROR)
                    print_simple(&head_a);
            }
            else
                error_code = INCORRECT_DATA_ERROR;
            
            if (error_code != NO_ERROR)
            {
                clear_list(head_a);
                clear_list(head_b);
            }
            break;
        case NO_MODE:
            error_code = KEY_ERROR;
            break;
    }

    return error_code;
}