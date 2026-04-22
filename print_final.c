#include "apc.h"

// Function to print the final result number from linked list
void print_final(Dlist *head)
{
    if (!head)
    {
        printf("0");
        return;
    }

    Dlist *temp = head;

    // Check for negative sentinel
    int is_negative = 0;
    if (temp->data == -1)
    {
        is_negative = 1;
        temp = temp->next;
    }

    // Skip leading zeros
    while (temp && temp->data == 0)
        temp = temp->next;

    if (!temp)
    {
        printf("0");  // all zeros
        return;
    }

    if (is_negative)
        printf("-");

    // Print remaining digits
    while (temp)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
