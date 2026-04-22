#include "apc.h"

void remove_start_zero(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0 && (*head)->next)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
}
