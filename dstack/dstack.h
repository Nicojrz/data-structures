#ifndef DSTACK
#define DSTACK

#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct Node
{
    element e;
    struct Node *next;
} Node;

void create_dstack(Node** s);
int isEmpty_dstack(Node* s);
void push_dstack(Node** s, element e);
element pop_dstack(Node** s);
void delete_dstack(Node** s);
void print_dstack(Node** s);

#include "dstack.h"

#endif
