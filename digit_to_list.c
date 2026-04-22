#include "apc.h"

// Convert num1 and num2 strings into doubly linked lists
void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *num1, char *num2)
{
    int i;

    // Convert first number
    for(i = 0; num1[i] != '\0'; i++)
    {
        int digit = num1[i] - '0';
        insert_at_last(head1, tail1, digit);
    }

    // Convert second number
    for(i = 0; num2[i] != '\0'; i++)
    {
        int digit = num2[i] - '0';
        insert_at_last(head2, tail2, digit);
    }
}