#ifndef _STRUCTURES_H_

#define _STRUCTURES_H_

typedef struct node node_t;

struct node
{
    void *data;
    struct node *next;
};

typedef struct simple
{
    int number, power;
} data_t;

#endif