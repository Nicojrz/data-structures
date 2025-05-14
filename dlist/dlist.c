#include "dlist.h"

void create_dlist(DList *l)
{
	l->head = NULL;
	l->tail = NULL;
}

int isEmpty_dlist(DList l)
{
	return l.head == NULL && l.tail == NULL;
}

void insertFirst_dlist(DList *l, element e)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->e = e;
	new->prev = NULL;
	
	if(isEmpty_dlist(*l))
	{
		new->next = NULL;
		l->head = new;
		l->tail = new;
	}
	else
	{
		new->next = l->head;
		l->head->prev = new;
		l->head = new;
	}
}

void insertEnd_dlist(DList *l, element e)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->e = e;
	new->next = NULL;
	
	if(isEmpty_dlist(*l))
	{
		new->prev = NULL;
		l->head = new;
		l->tail = new;
	}
	else
	{
		new->prev = l->tail;
		l->tail->next = new;
		l->tail = new;
	}
}

void insertAfter_dlist(DList *l, element e, int i)
{
	if(i < 1)
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
			printf("Indice fuera de rango.\n");
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
	
	return e;
}

element deleteNode_dlist(DList *l, int i)
{
	element e;

	if(isEmpty_dlist(*l))
	{
		printf("La lista esta vacia.\n");
		e = -1;
	}
	else if(i < 1)
	{
		printf("Indice invalido.\n");
		e = -1;
	}
	else
	{
		int k;
		Node *naux;

		for(k = 1, naux = l->head; k<i && naux!=NULL; k++, naux=naux->next);

		if(naux == NULL)
		{
			printf("Indice fuera de rango.");
			e = -1;
		}
		else
		{
			e = naux->e;
            
            if(l->tail == l->head)
            {
                l->head = l->tail = NULL;
            }
            else if(naux == l->head)
            {
                l->head = naux->next;
                if(l->head != NULL)
                    l->head->prev = NULL;
            }
            else if(naux == l->tail)
            {
                l->tail = naux->prev;
                if(l->tail != NULL)
                    l->tail->next = NULL;
            }
            else
            {
                naux->prev->next = naux->next;
                naux->next->prev = naux->prev;
            }

            free(naux);
		}
	}
	return e;
}

void delete_dlist(DList *l)
{
	Node *naux;

	while(l->tail != NULL)
	{
		naux = l->tail;
		l->tail = naux->prev;
		free(naux);
	}
	l->head = NULL;
}

Node * searchNode_dlist(DList l, int i)
{
	Node *naux;

	if(isEmpty_dlist(l) || i<0)
	{
		printf("Indice invalido.\n");
		naux = NULL;	
	}
	else
	{
		int k;
		for(k=1, naux=l.head; k<i && naux!=NULL; k++, naux=naux->next);

		if(naux == NULL)
		{
			printf("Indice fuera de rango.\n");
		}
	}

	return naux;
}

Node * searchElement_dlist(DList l, element e)
{
	Node *naux;
	
	if(isEmpty_dlist(l))
	{
		printf("La lista esta vacia.\n");
		naux = NULL;
	}
	else
	{
		naux = l.head;

		while(naux != NULL)
		{
			if(naux->e = e)
			{
				break;
			}
			else
			{
				naux = naux->next;
			}
		}
	}

	return naux;
}

void print_dlist(DList l)
{
	if(isEmpty_dlist(l))
	{
		printf("La lista esta vacia.\n");
	}
	else
	{
		Node *naux = l.head;
		while(naux != NULL)
		{
			printf("%d\n", naux->e);
			naux = naux->next;
		}
	}
}
