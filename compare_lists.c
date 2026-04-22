#include "apc.h"

int compare_lists(Dlist *head1, Dlist *head2)
{
    // Count the lengths
    int len1 = 0, len2 = 0;
    Dlist *temp;

    for(temp = head1; temp != NULL; temp = temp->next) len1++;
    for(temp = head2; temp != NULL; temp = temp->next) len2++;

    if(len1 > len2) return 1;  // head1 > head2
    if(len2 > len1) return -1; // head1 < head2

    // Same length → compare digit by digit
    Dlist *t1 = head1, *t2 = head2;
    while(t1 && t2)
    {
        if(t1->data > t2->data) return 1;
        if(t1->data < t2->data) return -1;
        t1 = t1->next;
        t2 = t2->next;
    }

    return 0; // equal
}