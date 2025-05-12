#include "dlist.h"

void create_dlist(DList *l)
{
	l->head = NULL;
	l->tail = NULL;
}

int isEmpty_dlist(DList *l)
{
	return l.head == NULL && l.tail == NULL;
}

void insertFirst_dlist(DList *l, element e)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->e = e;
	new->prev = NULL;
	new->next = l->head;
	l->head->prev = new;
	l->head = new;
}

void insertEnd_dlist(DList *l, element e)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->e = e;
	new->next = NULL;
	new->prev = l->tail;
	l->tail->next = new;
	l->tail = new;
}

void insertAfter_dlist(DList *l, element e, int i)
{
	if(i < 0)
	{
		printf("Indice invalido.\n");
	}
	else if(isEmpty_dlist(*l))
	{
		insertFirst_dlist(l, e);
	}
	else
	{
		int k;
		Node *naux;

		for(k=1, naux=l->head; k<i && naux!=NULL; k++, naux=naux->next);

		if(naux == NULL)
		{
			printf("Indice invalido.\n");
		}
		else
		{
			Node *new = (Node *)malloc(sizeof(Node));
			new->e = e;
			new->next = naux->next;
			new->prev = naux;
			naux->next->prev = new;
			naux->next = new;
		}
	}
}

element deleteFirst_dlist(DList *l)
{
	element e;

	if(isEmpty_dlist(*l))
	{
		printf("La lista esta vacia.\n");
		e = -1;
	}
	else
	{
		Node *naux = l->head;
		e = naux->e;
		naux->next->prev = NULL;
		l->head = naux->next;
		free(naux);
	}

	return e;
}

element deleteEnd_dlist(DList *l)
{
	element e;

	if(isEmpty_dlist(*l))
	{
		printf("La lista esta vacia.\n");
		e = -1;
	}
	else
	{
		Node *naux = l->tail;
		e = naux->e;
		naux->prev->next = NULL;
		l->tail = naux->prev;
		free(naux);
	}
}
