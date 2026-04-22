#include <stdlib.h>
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    int negResult = 0;

    /* Use local pointers – DO NOT modify original lists */
    Dlist *h1 = *head1, *t1 = *tail1;
    Dlist *h2 = *head2, *t2 = *tail2;

    /* Compare numbers */
    if (compare_lists(h1, h2) < 0)
    {
        Dlist *th = h1; h1 = h2; h2 = th;
        Dlist *tt = t1; t1 = t2; t2 = tt;
        negResult = 1;
    }

    Dlist *temp1 = t1;
    Dlist *temp2 = t2;
    int borrow = 0;

    *headR = *tailR = NULL;

    while (temp1 || temp2)
    {
        int d1 = temp1 ? temp1->data : 0;
        int d2 = temp2 ? temp2->data : 0;

        int sub = d1 - d2 - borrow;

        if (sub < 0)
        {
            sub += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_at_first(headR, tailR, sub);

        if (temp1) temp1 = temp1->prev;
        if (temp2) temp2 = temp2->prev;
    }

    /* Remove leading zeros */
    while (*headR && (*headR)->data == 0 && (*headR)->next)
    {
        Dlist *del = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(del);
    }

    return negResult;   // caller handles sign
}
