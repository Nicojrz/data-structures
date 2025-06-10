#ifndef DSTACK
#define DSTACK

#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct node
{
    element e;
    struct node *next;
} node;

void create_dstack(node** s);
int isEmpty_dstack(node* s);
void push_dstack(node** s, element e);
element pop_dstack(node** s);
void delete_dstack(node** s);
void print_dstack(node** s);

#include "dstack.h"

#endif
