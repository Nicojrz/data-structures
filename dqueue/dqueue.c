#include <dqueue.h>

void create_dqueue(DQueue *q)
{	
	q->head = NULL;
	q->tail = NULL;
}

int isEmpty_dqueue(DQueue q)
{	
	return q->head == NULL;
}

void enqueue_dqueue(DQueue *q, element e)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->e = e;
	new->next = NULL;
	
	if(isEmpty_dqueue(*q)) 
	{
		q->head = new;
	}
	else
	{
		q->tail->next = new;
	}
	
	q->tail = new;
}
element dequeue_dqueue(DQueue *q)
{
	element e;
	
	if(isEmpty_dqueue(*q))
	{
		printf("Error de underflow."\n);
		e = -1;
	}
	else
	{
		Node *naux = q->head;
		e = q->head->e;
		
		if(q->head->next == NULL)
		{
			q->head = NULL;
			q->tail = NULL;
		}
		else
		{
			q->head = q->head->next;
		}
		
		free(naux);
	}
	
	return e;
}

void delete_dequeue(DQueue *q)
{
	element e;
	
	while(!isEmpty_dqueue(*q))
	{
		e = dequeue_dqueue(q);
	}
}

void print_dqueue(DQueue q)
{
	DQueue qaux;
	element e;
	
	create(&qaux);
	
	while(!isEmpty_dqueue(q))
	{
		e = dequeue_dqueue(&q));
		printf("%d\n",e);
		enqueue_dqueue(&qaux, e);
	}
	while(!isEmpty_dqueue(aux))
	{
		e = dequeue_dqueue(&aux);
		enqueue_dqueue(&q, e);
	}
}