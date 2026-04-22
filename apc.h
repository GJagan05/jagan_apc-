#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;

/* store operands */
void digit_to_list(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   char *num1, char *num2);

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);

int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR);

int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR);

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR);

/* list helpers */
void insert_at_first(Dlist **head, Dlist **tail, int data);
void insert_at_last(Dlist **head, Dlist **tail, int data);
void delete_list(Dlist **head, Dlist **tail);
void remove_start_zero(Dlist **head, Dlist **tail);

/* arithmetic helpers */
int add_lists(Dlist **head1, Dlist **tail1,
              Dlist **head2, Dlist **tail2,
              Dlist **headR, Dlist **tailR);

void print_final(Dlist *head);
int validate(char **argv);
int compare_lists(Dlist *head1, Dlist *head2);

#endif
