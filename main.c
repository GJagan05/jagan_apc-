#include <stdio.h>
#include <stdlib.h>
#include "apc.h"

int main(int argc, char *argv[])
{
    /* Argument count check */
    if (argc != 4)
    {
        printf("INVALID ARGUMENT COUNT\n");
        printf("Usage examples:\n");
        printf("  10 + 10\n");
        printf("  10 - 10\n");
        printf("  10 x 10\n");
        printf("  10 / 10\n");
        return FAILURE;
    }

    /* Argument validation */
    if (validate(argv) == FAILURE)
    {
        printf("INVALID ARGUMENTS\n");
        printf("Operands should be numbers and operator must be one of +, -, x, /\n");
        return FAILURE;
    }

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    int neg1 = 0, neg2 = 0;

    /* Handle negative numbers */
    char *num1 = argv[1];
    if (num1[0] == '-')
    {
        neg1 = 1;
        num1++;
    }

    char *num2 = argv[3];
    if (num2[0] == '-')
    {
        neg2 = 1;
        num2++;
    }

    char operator = argv[2][0];

    /* Convert operands to linked lists */
    digit_to_list(&head1, &tail1, &head2, &tail2, num1, num2);

    switch (operator)
    {
        case '+':
            if (neg1 == neg2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (neg1 && headR->data != 0)
                    insert_at_first(&headR,&tailR,-1);
            }
            else
            {
                int negResult = subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (neg1) negResult = !negResult;
                if (negResult && headR->data != 0)
                    insert_at_first(&headR,&tailR,-1);
            }
            break;

        case '-':
            if (neg1 != neg2)
            {
                addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (neg1 && headR->data != 0)
                    insert_at_first(&headR,&tailR,-1);
            }
            else
            {
                int negResult = subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
                if (neg1) negResult = !negResult;
                if (negResult && headR->data != 0)
                    insert_at_first(&headR,&tailR,-1);
            }
            break;

        case 'x':
            multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
            if ((neg1 && !neg2) || (!neg1 && neg2))
                if (headR->data != 0)
                    insert_at_first(&headR,&tailR,-1);
            break;

        case '/':
            if (division(&head1,&tail1,&head2,&tail2,&headR,&tailR) == FAILURE)
                return FAILURE;

            /* Remove leading zeros */
            while (headR && headR->data == 0 && headR->next)
            {
                Dlist *del = headR;
                headR = headR->next;
                headR->prev = NULL;
                free(del);
            }

            if ((neg1 && !neg2) || (!neg1 && neg2))
                if (!(headR->data == 0 && headR->next == NULL))
                    insert_at_first(&headR,&tailR,-1);
            break;

        default:
            printf("Invalid Input!\n");
            return FAILURE;
    }

    /* Print expression and result */
    printf("%s %c %s = ", argv[1], operator, argv[3]);
    print_final(headR);
    printf("\n");

    return SUCCESS;
}
