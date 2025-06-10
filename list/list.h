#ifndef LIST
#define LIST

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct Node
{
	element e;
	struct Node *next;
} Node;

typedef struct List
{
	Node *head;
} List;

void create_list(List *l);
int isEmpty_list(List l);
void insertFirst_list(List *l, element e);
void insertEnd_list(List *l, element e);
void insertAfter_list(List *l, element e, int i);
element deleteFirst_list(List *l);
element deleteEnd_list(List *l);
element deleteNode_list(List *l, int i);
void delete_list(List *l);
element searchNode_list(List *l, int i);
int searchElement_list(List *l, element e);
void print_list(List l);

#include "list.c"

#endif
