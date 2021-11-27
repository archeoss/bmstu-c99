#include "mem_alloc.h"

void alloc_node(node_t **head, node_t **cur_node)
{
    *cur_node = malloc(sizeof(node_t));
    if (*cur_node)
    {
        (*cur_node)->next = NULL;
        (*cur_node)->data = malloc(sizeof(data_t));
        if (!(*cur_node)->data)
            exit(EXIT_FAILURE);

        ((data_t *)(*cur_node)->data)->number = 0;
        ((data_t *)(*cur_node)->data)->power = 0;
        if (!*head)
            *head = *cur_node;
    }
    else
        exit(EXIT_FAILURE);
}

void clear_list(node_t *head)
{
    while (head)
    {
        node_t *tmp = head;
        head = head->next;
        free(tmp->data);
        free(tmp);
    }
}