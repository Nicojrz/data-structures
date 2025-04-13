#ifndef DQUEUE
#define DQUEUE

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node
{
	element e;
	struct Node *next;
} Node;
typedef struct DQueue
{
	Node *head;
	Node *tail;
} DQueue;

void create_dqueue(DQueue *q);
int isEmpty_dqueue(DQueue q);
void enqueue_dqueue(DQueue *q, element e);
element dequeue_dqueue(DQueue *q);
void delete_dqueue(DQueue *q);
void print_dqueue(DQueue *q);

#include "dqueue.c"
#endif