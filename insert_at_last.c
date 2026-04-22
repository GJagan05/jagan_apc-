#include "apc.h"

void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if (!new)
    {
        perror("malloc failed");
        return;
    }

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail == NULL)   // List is empty
    {
        *head = new;
        *tail = new;
    }
    else                 // Insert after the current tail
    {
        (*tail)->next = new;
        *tail = new;
    }
}
