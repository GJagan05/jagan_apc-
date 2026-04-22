#include "apc.h"

void insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new)
    {
        perror("malloc failed");
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head == NULL)   // Empty list
    {
        *head = new;
        *tail = new;
    }
    else                // Non-empty list
    {
        (*head)->prev = new;
        *head = new;
    }
}
