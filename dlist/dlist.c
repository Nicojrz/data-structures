#include "dlist.h"

void create_list(List *l)
{
    l = NULL;
}

int isEmpty_list(List l)
{
    return l.head==NULL;
}

void insertFirst_list(List *l, element e)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->next = l->head;
    new->e = e;
    l->head = new;
}

void insertEnd_list(List *l, element e)
{
    Node *naux;
    if(isEmpty_list(*l))
    {
        insertFirst_list(l, e);
    }
    else
    {
        for(naux=l->head; naux->next!=NULL; naux=naux->next);
        
        Node *new = (Node *)malloc(sizeof(Node));
        new->e = e;
        new->next = NULL;
        naux->next = new;
    }
}

void insertAfter_list(List *l, element e, int i)
{
    Node *naux;
    if(i<0)
    {
        printf("Indice invalido.\n");
    }
    else if(isEmpty_list(*l))
    {
        insertFirst_list(l, e);
    }
    else
    {
        int k;
        for(k=1, naux=l->head; k<i && naux!=NULL; k++, naux=naux->next);

	if(naux==NULL)
        {
            printf("Indice invalido.\n");
        }
        else
        {
            Node *new = (Node *)malloc(sizeof(Node));
            new->e = e;
            new->next = naux->next;
            naux->next = new;
        }
    }
}

element deleteFirst_list(List *l)
{
	element e;

	if(isEmpty_list(*l))
	{
		printf("La lista esta vacia.\n");
		e = -1;
	}
	else
	{
		Node *naux = l->head;
		e = naux->e;
		l->head = naux->next;
		free(naux);
	}

	return e;
}

element deleteEnd_list(List *l);
{
	element e;

        if(isEmpty_list(*l))
        {
                printf("La lista esta vacia.\n");
                e = -1;
        }
        else
        {
		Node *naux; 
		for(naux=l->head; naux->next!=NULL; naux=naux->next);

                e = naux->e;
                free(naux);
        }
        
	return e;
}

element deleteNode_list(List *l, int i)
{
	element e;

	if(i < 0)
        {
                printf("Indice invalido.\n");
		e = -1;
        }
	else if(isEmpty_list(*l))
        {
                printf("La lista esta vacia.\n");
                e = -1;
       	}
        else
        {
		int k;
                Node *naux;
                for(k=1, naux=l->head; k<i && naux!=NULL; k++, naux=naux->next);

		if(naux == NULL)
		{
			printf("Indice invalido.\n");
                	e = -1;
		}
		else
		{
			e = naux->e;
	                free(naux);
		}
        }

        return e;
}

void delete_list(List *l)
{
	while(!isEmpty_list(*l))
	{
		
	}
}

element searchNode_list(List *l, int i);
int searchElement_list(List *l, element e);

void print_list(List listita)
{
    if(isEmpty_list(listita))
    {
        printf("La lista esta vacia\n");
    }
    else
    {
        Node *n = listita.head;
        while(n != NULL)
        {
            printf("%d\n", n->e);
            n = n->next;
        }
    }
}
