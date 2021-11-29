#include "io.h"

static int read_struct(FILE *f, data_t *cur_node)
{
    cur_node->name = NULL;
    cur_node->is_priority = 0;
    char junk[JUNK_LEN];
    size_t name_size = 0;
    int rc = 0;
    if (getline(&cur_node->name, &name_size, f) != -1)
        rc++;
    if (rc > 0)
        rc += check_line(cur_node->name);
    rc += fscanf(f, "%d%d", &cur_node->rating, &cur_node->is_priority);
    rc += cur_node->is_priority == 0 || cur_node->is_priority == 1 ? 0 : -1;
    fgets(junk, JUNK_LEN, f); // После fscanf остается лишний \n, который мешает getline

    return rc;
}

int read_items(char *filename, node_t **head)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return FILE_NOT_FOUND;

    data_t *cur_data = malloc(sizeof(data_t));
    int rc = read_struct(f, cur_data);
    int error_code = NO_ERROR;
    int count = 0;
    while (rc == 3)
    {
        if (check_rating(cur_data))
        {    
            rc = 0;
            node_t *cur_node = malloc(sizeof(node_t));
            if (cur_node)
            {
                cur_node->data = cur_data;
                push(head, cur_node);
            }
            else
            {
                rc = -1;
                error_code = ALLOC_ERROR;
            }
        }
        else
        {
            free(cur_data->name);
            free(cur_data);
        }
        count++;
        cur_data = malloc(sizeof(data_t));
        rc = read_struct(f, cur_data);
        if (rc != 3)
        {
            free(cur_data->name);
            free(cur_data);
        }
    }

    if (rc > 0 || count == 0)
    {
        free(cur_data->name);
        free(cur_data);
        error_code = INCORRECT_DATAFILE;   
    } 
    fclose(f);

    return error_code;
}

void show_all(node_t *head)
{
    node_t *cur_node = head;
    while (cur_node)
    {
        data_t *dat = cur_node->data;
        printf("%s%d\n%d\n", dat->name, dat->rating, dat->is_priority);
        cur_node = cur_node->next;
    }
}

int file_list(char *filename, node_t *head)
{
    int error_code = NO_ERROR;
    node_t *cur_node = head;
    FILE *f = fopen(filename, "w");
    if (f)
    {
        while (cur_node)
        {
            data_t *dat = cur_node->data;
            fprintf(f, "%s%d\n%d\n", dat->name, dat->rating, dat->is_priority);
            cur_node = cur_node->next;
        }
    }
    else
        error_code = KEY_ERROR;

    return error_code;
}