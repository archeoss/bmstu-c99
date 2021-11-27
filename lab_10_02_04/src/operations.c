#include "operations.h"

node_t *make_simple(int number)
{
    int i = 2;
    node_t *head = NULL;
    node_t *cur_node = NULL, *prev_node = NULL;
    while (number > 1)
    {
        if (number % i == 0)
        {
            if (!cur_node)
            {
                alloc_node(&head, &cur_node);
                if (prev_node)
                    prev_node->next = cur_node;
                prev_node = cur_node;
            }
            ((data_t *)cur_node->data)->number = i;
            ((data_t *)cur_node->data)->power++;
            number = number / i;
        }
        else
        {
            i++;
            cur_node = NULL;
        }
    }

    return head;
}

void *pop_back(node_t **head)
{
    node_t *cur_node = *head, *prev_node = cur_node;
    while (cur_node->next != NULL)
    {
        prev_node = cur_node;
        cur_node = cur_node->next;
    }
    void *dat = cur_node->data;
    if (cur_node == *head)
        *head = NULL;
    else
        prev_node->next = NULL;
    free(cur_node);

    return dat;    
}

void *pop_front(node_t **head)
{
    void *dat = NULL;
    if (head && *head)
    {
        dat = (*head)->data;
        node_t *tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    return dat;
}

node_t *simple_mul(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
{
    node_t *result_head = NULL, *cur_node = NULL;
    while (*head_a && *head_b)
    {
        data_t *dat;
        if (comparator((*head_a)->data, (*head_b)->data) > 0)
            dat = pop_front(head_b);
        else if (comparator((*head_a)->data, (*head_b)->data) < 0)
            dat = pop_front(head_a);
        else
        {
            dat = pop_front(head_a);
            data_t *dat_b = pop_front(head_b);
            
            dat->power += dat_b->power;
            free(dat_b);
        }

        if (!result_head)
        {
            result_head = malloc(sizeof(node_t));
            if (!result_head)
                exit(EXIT_FAILURE);
            
            result_head->data = dat;
            result_head->next = NULL;
            cur_node = result_head;
        }
       else
        {
            node_t *tmp = malloc(sizeof(node_t));
            if (!tmp)
                exit(EXIT_FAILURE);

            tmp->next = NULL;
            cur_node->next = tmp;
            cur_node = cur_node->next;
            cur_node->data = dat;
        }
    }
    while (*head_a)
    {
        data_t *dat = pop_front(head_a);
        node_t *tmp = malloc(sizeof(node_t));
        if (!tmp)
            exit(EXIT_FAILURE);
        
        tmp->next = NULL;
        cur_node->next = tmp;
        cur_node = cur_node->next;
        cur_node->data = dat;
    }
    while (*head_b)
    {
        data_t *dat = pop_front(head_b);
        node_t *tmp = malloc(sizeof(node_t));
        if (!tmp)
            exit(EXIT_FAILURE);
        
        tmp->next = NULL;
        cur_node->next = tmp;
        cur_node = cur_node->next;
        cur_node->data = dat;
    }

    return result_head;
}

int compare_numbers(const void *dat_a, const void *dat_b)
{
    return ((data_t *)dat_a)->number - ((data_t *)dat_b)->number;
}

void simple_sqr(node_t *head)
{
    while (head)
    {
        ((data_t *)head->data)->power *= 2;
        head = head->next;
    }   
}

int simple_div(node_t **head_a, node_t **head_b)
{
    int error_code = NO_ERROR;
    node_t *cur_node = *head_a;
    while (*head_b && error_code == NO_ERROR)
    {
        data_t *dat = pop_front(head_b);
        while (cur_node && ((data_t *)cur_node->data)->number < dat->number)
            cur_node = cur_node->next;

        if (cur_node)
            ((data_t *)cur_node->data)->power -= dat->power;
        else 
            error_code = INCORRECT_DATA_ERROR;

        if (error_code == NO_ERROR)
        {
            if (((data_t *)cur_node->data)->power == 0)
                pop_number(head_a, cur_node);
            else if (((data_t *)cur_node->data)->power < 0)
                error_code = INCORRECT_DATA_ERROR;
        }
        free(dat);
    }
    if (!*head_a)
        error_code = INCORRECT_DATA_ERROR;

    return error_code;
}

void pop_number(node_t **head, node_t *elem)
{
    if (*head == elem)
        *head = (*head)->next;
    else
    {
        node_t *cur_node = *head;
        while (cur_node->next != elem)
            cur_node = cur_node->next;
        cur_node->next = elem->next;
    }

    free(elem->data);
    free(elem);
}