#include "squeue.h"

int next(int n)
{
	return (n+1)%SIZE;
}

void create_queue(Queue* q)
{
	q->head = -1;
	q->tail = -1;
}

int isFull_queue(Queue q)
{
	if(next(q.tail) == q.head)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isEmpty_queue(Queue q)
{
	if(q.head == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue_queue(Queue* q, element e)
{
	if(isFull_queue(*q))
	{
		printf("Error de overflow\n");
	}
	else
	{
		if(isEmpty_queue(*q))
		{
			q->head = next(q->head);
		}
		q->tail = next(q->tail);
		q->Q[q->tail] = e;
	}
}

element dequeue_queue(Queue* q)
{
	element e
	if(isEmpty_queue(*q))
	{
		e = -1;
		printf("Error de underflow\n");
	}
	else
	{
		e = q->Q[q->head];
		if(q->tail == q->head)
		{
			q->tail = -1;
			q->head = -1;
		}
		else
		{
			q->head = next(q->head);
		}
	}
	return e;
}

void delete_queue(Queue* q)
{
	while(!isEmpty_queue(*q))
	{
		element e = dequeue_queue(q);
	}
}

void copy_queue(Queue* q, Queue* c)
{
	element e;
	Queue aux;
	create_queue(&aux);

	while(!isEmpty_queue(*q))
	{
		enqueue_queue(&aux, dequeue_queue(q));
	}
	while(!isEmpty_queue(aux))
	{
		e = dequeue_queue(&aux);
		enqueue_queue(q, e);
		enqueue_queue(c, e);
	}
}