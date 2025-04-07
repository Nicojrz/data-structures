#include "dstack.h"

void create_dstack(Node** s)
{
    *s = NULL;
}

int isEmpty_dstack(Node* s)
{
    if(s == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push_dstack(Node** s, element e)
{
    Node* new = (Node*)malloc(sizeof(Node));
    if(new == NULL)
    {
	printf("Error memoria dPush.\n");
    }
    new->e = e;
    new->next = *s;
    *s = new;
}

element pop_dstack(Node** s)
{
    element eaux;
    if(!isEmpty_dstack(*s))
    {
        eaux = (*s)->e;
        Node* saux = (*s);
        *s = (*s)->next;
        free(saux);
    }
    else
    {
        eaux = 0;
        printf("Error underflow\n");
    }
    return eaux;
}

void delete_dstack(Node** s)
{
    while(!isEmpty_dstack(*s))
    {
        element e = pop_dstack(s);
    }
}

void print_dstack(Node** s)
{
    Node* aux = NULL;
    element e;

    while(!isEmpty_dstack(*s))
    {
        e = pop_dstack(s);
        push_dstack(&aux,e);
	printf("%d", e);
    }
    while(!isEmpty_dstack(aux))
    {
        e = pop_dstack(&aux);
        push_dstack(s,e);
    }
    printf("\n");
}
