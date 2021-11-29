#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "list_operations.h"
#include "errors.h"
#include "operations.h"
#include "structures.h"
#include "sort.h"

int main(int args, char **keys)
{
    int error_code = NO_ERROR;
    node_t *head = NULL;
    if (args == 3)
        error_code = read_items(keys[1], &head);
    else
        error_code = KEY_ERROR;

    if (error_code == NO_ERROR)
    {
        head = sort(head, compare_rating);
        remove_duplicates(&head, compare_char);
        priority_change(&head);
        file_list(keys[2], head);
    }
    free_list(head);
    
    return error_code;
}