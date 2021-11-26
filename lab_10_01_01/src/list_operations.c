#include "list_operations.h"

void *pop_front(node_t **head)
{
    void *dat = NULL;
    if (*head)
    {
        dat = (*head)->data;
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    return dat;
}

void push(node_t **head, node_t *cur_node)
{
    cur_node->next = *head;
    *head = cur_node;
}

void insert(node_t **head, node_t *elem, node_t *before)
{
    if (*head == before)
    {
        elem->next = *head;
        *head = elem;
    }
    else
    {
        node_t *cur_node = *head;
        while (cur_node->next != before)
            cur_node = cur_node->next;

        elem->next = before;
        cur_node->next = elem;
    }
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    node_t *check_node = *head;
    while (check_node)
    {
        node_t *cur_node = check_node;
        while (cur_node->next)
        {
            if (cur_node->next != check_node && comparator(cur_node->next, check_node) == 0)
            {
                node_t *tmp = cur_node->next;
                cur_node->next = cur_node->next->next;
                free(tmp);
            }
            else
                cur_node = cur_node->next;
        }
        check_node = check_node->next;
    }
}

size_t get_count(node_t *cur_node)
{
    size_t result = 0;
    while (cur_node)
    {
        result++;
        cur_node = cur_node->next;
    }

    return result;
}

void free_list(node_t *cur_node)
{
    while (cur_node)
    {
        node_t *tmp = cur_node;
        cur_node = cur_node->next;
        free(tmp);
    }
}

void priority_change(node_t **head)
{
    node_t *first_low_priority = NULL;
    node_t *cur_node = *head;
    while (cur_node && !first_low_priority)
    {
        if (priority_check(cur_node) == 0)
            first_low_priority = cur_node;
        cur_node = cur_node->next;
    }

    if (first_low_priority)
    {
        while (cur_node && cur_node->next)
        {
            if (priority_check(cur_node->next) == 1)
            {
                node_t *tmp = cur_node->next;
                cur_node->next = cur_node->next->next;
                insert(head, tmp, first_low_priority);
            }
            else
                cur_node = cur_node->next;
        }
    }
}