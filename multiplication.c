#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1,
	               Dlist **head2, Dlist **tail2, 
				   Dlist **headR, Dlist **tailR)
{
    if (((*head1 == *tail1) && ((*head1)->data == 0)) ||
        ((*head2 == *tail2) && ((*head2)->data == 0)))
    {
        insert_at_first(headR, tailR, 0);
        return SUCCESS;
    }

    insert_at_first(headR, tailR, 0);  // initialize result
    Dlist *temp2 = *tail2;
    int count = 0;

    while (temp2)
    {
        Dlist *temp_head = NULL;
        Dlist *temp_tail = NULL;
        Dlist *temp1 = *tail1;
        int carry = 0;

        while (temp1)
        {
            int data = temp1->data * temp2->data + carry;
            carry = data / 10;
            data = data % 10;
            insert_at_first(&temp_head, &temp_tail, data);
            temp1 = temp1->prev;
        }

        if (carry)
            insert_at_first(&temp_head, &temp_tail, carry);

        for (int i = 0; i < count; i++)
            insert_at_last(&temp_head, &temp_tail, 0);

        Dlist *new_res_head = NULL, *new_res_tail = NULL;
        add_lists(headR, tailR,
                  &temp_head, &temp_tail,
                  &new_res_head, &new_res_tail);

        delete_list(headR, tailR);
        *headR = new_res_head;
        *tailR = new_res_tail;

        delete_list(&temp_head, &temp_tail);
        count++;
        temp2 = temp2->prev;
    }

    remove_start_zero(headR, tailR);  
    return SUCCESS;
}