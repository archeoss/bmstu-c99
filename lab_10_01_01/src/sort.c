#include "sort.h"

static void copy_list(node_t *cur_node, node_t **head_cpy)
{
    while (*head_cpy)
    {
        data_t *dat = pop_front(head_cpy);
        node_t *tmp = malloc(sizeof(node_t));
        if (!tmp)
            exit(EXIT_FAILURE);
        
        tmp->next = NULL;
        cur_node->next = tmp;
        cur_node = cur_node->next;
        cur_node->data = dat;
    }
}

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
    if (!comparator || !((head_a && *head_a && (*head_a)->data) || (head_b && *head_b && (*head_b)->data)))
        return NULL;

    node_t *head_sorted = malloc(sizeof(node_t));
    if (head_a && head_b && *head_a && *head_b)
    {
        if (comparator((*head_a)->data, (*head_b)->data) < 0)
            head_sorted->data = pop_front(head_a);
        else
            head_sorted->data = pop_front(head_b);
    }
    else if (head_a && *head_a)
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
    copy_list(cur_node, head_a);
    copy_list(cur_node, head_b);

    return head_sorted;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !comparator)
        return NULL;

    node_t *back = NULL;
    node_t *result = head;
    if (head->next != NULL)
    {
        front_back_split(head, &back);
        node_t *new_head_a = sort(head, comparator);
        node_t *new_head_b = sort(back, comparator);
        result = sorted_merge(&new_head_a, &new_head_b, comparator);
    }

    return result;
}