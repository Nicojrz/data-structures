#ifndef SQUEUE
#define SQUEUE

#define SIZE 10
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct SQueue
{
	element Q[SIZE];
	int head;
	int tail;
} SQueue;

int next(int n);

void create_queue(Queue* q);
int isFull_queue(Queue q);
int isEmpty_queue(Queue q);
void enqueue_queue(Queue* q, element e);
element dequeue_queue(Queue* q);
void delete_queue(Queue* q);
void copy_queue(Queue* q, Queue* c);

#include "squeue.c"
#endif
