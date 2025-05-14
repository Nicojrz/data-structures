#ifndef DLIST
#define DLIST

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
	element e;
	struct Node *prev;
	struct Node *next;
} Node;

typedef struct DList
{
	Node *head;
	Node *tail;
} DList;

void create_dlist(DList *l);
int isEmpty_dlist(DList l);
void insertFirst_dlist(DList *l, element e);
void insertEnd_dlist(DList *l, element e);
void insertAfter_dlist(DList *l, element e, int i);
element deleteFirst_dlist(DList *l);
element deleteEnd_dlist(DList *l);
element deleteNode_dlist(DList *l, int i);
void delete_dlist(DList *l);
Node * searchNode_dlist(DList l, int i);
Node * searchElement_dlist(DList l, element e);
void print_dlist(DList l);

#endif
