#ifndef _STRUCTURES_H_

#define _STRUCTURES_H_

typedef struct node node_t;

struct node
{
    void *data;
    struct node *next;
};

typedef struct citizen
{
    char *name;
    int rating, is_priority;
} data_t;

#endif