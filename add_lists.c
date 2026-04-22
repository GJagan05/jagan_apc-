#include "apc.h"

int add_lists(Dlist **head1, Dlist **tail1,
              Dlist **head2, Dlist **tail2,
              Dlist **headR, Dlist **tailR)
{
    int carry = 0;

    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;

    while (t1 || t2 || carry)
    {
        int sum = carry;

        if (t1)
        {
            sum += t1->data;
            t1 = t1->prev;
        }

        if (t2)
        {
            sum += t2->data;
            t2 = t2->prev;
        }

        insert_at_first(headR, tailR, sum % 10);
        carry = sum / 10;
    }

    return SUCCESS;
}
