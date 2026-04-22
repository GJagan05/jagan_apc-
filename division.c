#include "apc.h"

int division(Dlist **head1, Dlist **tail1, 
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *tempH = NULL, *tempT = NULL;
    int count = 0;

    /* Division by zero check */
    if (*head2 == NULL)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    /* If dividend < divisor → result = 0 */
    if (compare_lists(*head1, *head2) < 0)
    {
        insert_at_last(headR, tailR, 0);
        return SUCCESS;
    }

    /* Repeated subtraction */
    while (compare_lists(*head1, *head2) >= 0)
    {
        subtraction(head1, tail1,
                    head2, tail2,
                    &tempH, &tempT);

        /* Replace dividend with result of subtraction */
        delete_list(head1, tail1);
        *head1 = tempH;
        *tail1 = tempT;
        tempH = tempT = NULL;

        count++;
    }

    /* Store quotient */
    insert_at_last(headR, tailR, count);

    return SUCCESS;
}

