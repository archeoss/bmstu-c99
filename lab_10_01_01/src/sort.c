#include "sort.h"

void front_back_split(node_t *head, node_t **back)
{
    int count = 0;
    node_t *cur_node = head;
    while (cur_node)
    {
        count++;
        cur_node = cur_node->next;
    }
    if (count > 1)
    {
        cur_node = head;
        int n = count / 2 + count % 2;
        for (int i = 0; i < n - 1; i++)
            cur_node = cur_node->next;
        *back = cur_node->next;
        cur_node->next = NULL;
    }
}

node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *head_sorted = malloc(sizeof(node_t));
    if (comparator((*head_a)->data, (*head_b)->data) < 0)
        head_sorted->data = pop_front(head_a);
    else
        head_sorted->data = pop_front(head_b);
 
    head_sorted->next = NULL;
    node_t *cur_node = head_sorted;
    while (*head_a && *head_b)
    {
        node_t *tmp = malloc(sizeof(node_t));
        if (comparator((*head_a)->data, (*head_b)->data) < 0)
            tmp->data = pop_front(head_a);
        else
            tmp->data = pop_front(head_b);
        tmp->next = NULL;
        cur_node->next = tmp;
        cur_node = tmp;
    }
    while (*head_a)
    {
        node_t *tmp = malloc(sizeof(node_t));
        tmp->data = pop_front(head_a);
        tmp->next = NULL;
        cur_node->next = tmp;
        cur_node = tmp;
    }
    while (*head_b)
    {
        node_t *tmp = malloc(sizeof(node_t));
        tmp->data = pop_front(head_b);
        tmp->next = NULL;
        cur_node->next = tmp;
        cur_node = tmp;
    }

    return head_sorted;
}

void sort(node_t **head, int (*comparator)(const void *, const void *))
{
    node_t *back = NULL;
    if (get_count(*head) > 1)
    {
        front_back_split(*head, &back);
        sort(head, comparator);
        sort(&back, comparator);
        *head = sorted_merge(head, &back, comparator);
    }
}