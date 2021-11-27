#include "io.h"

int get_mode()
{
    int mode;
    char command[COMMAND_LEN];

    if (fgets(command, COMMAND_LEN - 1, stdin))
    {
        if (strcmp(command, "out") == 0)
            mode = OUT_MODE;
        else if (strcmp(command, "mul") == 0)
            mode = MUL_MODE;
        else if (strcmp(command, "sqr") == 0)
            mode = SQR_MODE;
        else if (strcmp(command, "div") == 0)
            mode = DIV_MODE;
        else
            mode = NO_MODE;
    }
    else
        mode = NO_MODE;

    return mode;
}

node_t *get_number()
{
    int number;
    node_t *head = NULL;
    int rc = scanf("%d", &number);
    if (rc)
        head = make_simple(number);

    return head;
}

void print_simple(node_t **head)
{
//    printf("<out\n");
    while (*head)
    {
        data_t *dat = pop_back(head);
        printf("%d %d ", dat->number, dat->power);
        free(dat);
    }
    printf("1\n");
}
